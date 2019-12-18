#ifndef GAME_HPP
#define GAME_HPP

#include "GameObject.hpp"
#include "GraphicsWrapper.hpp"

#include <string>
#include <vector>

class Game {
public:
  Game(GraphicsWrapper &graphics, unsigned int seed);
  void Loop();

private:
  void Update();
  void Render();

  GraphicsWrapper &graphics;
  std::vector<GameObject*> objects;
};

#endif 
