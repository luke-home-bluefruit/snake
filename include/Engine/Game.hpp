#ifndef GAME_HPP
#define GAME_HPP

#include "GameObject.hpp"
#include "GraphicsWrapper.hpp"

#include <string>
#include <vector>

class Game {
public:
  Game(GraphicsWrapper &graphics, std::vector<GameObject*> &objectsIn);
  void Loop();

private:
  void Update();
  void Render();

  GraphicsWrapper &graphics;
  std::vector<GameObject*> objects;
};

#endif 
