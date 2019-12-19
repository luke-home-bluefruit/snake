#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

#include "Drawable.hpp"
#include "Moveable.hpp"

#include <vector>

class GameObject {
public:
  virtual std::vector<Drawable> GetDrawables() = 0;
  virtual Moveable GetMoveable() = 0;
  virtual void SetMoveable(Moveable moveable) = 0;
};

#endif
