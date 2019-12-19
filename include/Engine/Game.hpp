#ifndef GAME_HPP
#define GAME_HPP

#include "ButtonDriver.hpp"
#include "GameObject.hpp"
#include "GraphicsWrapper.hpp"

#include <string>
#include <vector>

class Game {
public:
  Game(GraphicsWrapper &graphics, std::vector<GameObject*> &objects, ButtonDriver &buttons);
  void Loop();

private:
  void Update();
  void Render();

  ButtonDriver &buttons;
  GraphicsWrapper &graphics;
  std::vector<GameObject*> objects;
};

#endif 
