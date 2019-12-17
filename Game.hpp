#ifndef GAME_HPP
#define GAME_HPP
#include "GraphicsWrapper.hpp"
#include "GameObject.hpp"
#include <vector>
#include <string>

class Game {
public:
  Game(GraphicsWrapper&graphics); 
  void Loop();
private:
  GraphicsWrapper&graphics;
  std::vector<GameObject*> objects;
};

#endif 
