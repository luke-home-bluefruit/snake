#include "Game.hpp"

#include "Coord.hpp"
#include "Food.hpp"
#include "Snake.hpp"

Game::Game(GraphicsWrapper &graphics, std::vector<GameObject*> &objectsIn) : graphics(graphics) {
  for (std::size_t i = 0; i < objectsIn.size(); i++)
    objects.push_back(objectsIn[i]);
}

void Game::Loop() {
 Update();
 Render();
}

void Game::Update() {
  for (std::size_t i = 0; i < objects.size(); i++) {
    objects[i]->Update();
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