#include "Game.hpp"
#include "Coord.hpp"
#include "Food.hpp"
#include "Snake.hpp"

using namespace ::std;

Game::Game(GraphicsWrapper& graphics) : graphics(graphics) {
  objects.push_back(new Snake());
  objects.push_back(new Food());
}

void Game::Loop() {  
  graphics.Clear();
  do {
    for (size_t i = 0; i < objects.size(); i++) {
      objects[i]->Draw(graphics);
    }
  } while (graphics.Render());
}
