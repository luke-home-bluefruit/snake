#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP
#include "GraphicsWrapper.hpp"

class GameObject {
public:
  virtual void Draw(GraphicsWrapper &graphics) = 0;
};

#endif
