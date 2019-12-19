#include "Game.hpp"

#include "Food.hpp"
#include "Snake.hpp"

#include <Arduino.h>

Game::Game(GraphicsWrapper &graphics, std::vector<GameObject*> &objects, ButtonDriver &buttons) :
  buttons(buttons),
  graphics(graphics),
  objects(objects) {
}

void Game::Loop() {
  buttons.Task();
  GameTick();
  Render();
}

void Game::GameTick() {
  for (std::size_t i = 0; i < objects.size(); i++) {
    Moveable moveable = objects[i]->GetMoveable();
    moveable.position.x += moveable.velocity.x;
    moveable.position.y += moveable.velocity.y;
    if (moveable.edgeWrapping) {
      moveable.position.x = (moveable.position.x + 32) % 32;
      moveable.position.y = (moveable.position.y + 16) % 16;
    }
    objects[i]->SetMoveable(moveable);
  }

  for (std::size_t i = 0; i < objects.size(); i++) {
    Moveable a = objects[i]->GetMoveable(); 
    for (std::size_t j = i + 1; j < objects.size(); j++) {
      Moveable b = objects[j]->GetMoveable(); 
      if ((a.position.x == b.position.x) && (a.position.y == b.position.y)) {
        objects[i]->OnCollision(objects[j]);
        objects[j]->OnCollision(objects[i]);
      }
    }
  }  
}

void Game::Render() {
  graphics.Clear();

  do {
    for (std::size_t i = 0; i < objects.size(); i++) {
      std::vector<Drawable> drawables = objects[i]->GetDrawables();

      for (std::size_t j = 0; j < drawables.size(); j++) {
        switch (drawables[j].shape) {
        case Drawable::Shape::Circle:
          graphics.DrawCircle(
            drawables[j].properties[0],
            drawables[j].properties[1],
            drawables[j].properties[2]
          );
          break;

        case Drawable::Shape::Rectangle:
          graphics.DrawRectangle(
            drawables[j].properties[0],
            drawables[j].properties[1],
            drawables[j].properties[2],
            drawables[j].properties[3]
          );
          break;
        }
      }
    }
  } while (graphics.Render());
}