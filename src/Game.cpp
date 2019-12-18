#include "Game.hpp"
#include "Coord.hpp"
#include "Food.hpp"
#include "Snake.hpp"
#include <Arduino.h>

Game::Game(GraphicsWrapper& graphics, unsigned int seed) : graphics(graphics) {
  randomSeed(seed);

  objects.push_back(new Snake());
  objects.push_back(new Food());
}

void Game::Loop() {
  graphics.Clear();
  do {
    for (std::size_t i = 0; i < objects.size(); i++) {
      std::vector<Drawable> drawables = objects[i]->GetDrawables();
      for (std::size_t j = 0; j < drawables.size(); j++) {
        switch (drawables[j].shape) {
        case Drawable::Shape::Circle:
          graphics.DrawCircle(drawables[j].properties[0], drawables[j].properties[1], drawables[j].properties[2]);
          break;
        case Drawable::Shape::Rectangle:
          graphics.DrawRectangle(drawables[j].properties[0], drawables[j].properties[1], drawables[j].properties[2], drawables[j].properties[3]);
          break;
        }
      }
    }
  } while (graphics.Render());
}
