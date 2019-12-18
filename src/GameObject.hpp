#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP
#include "Drawable.hpp"
#include <vector>

class GameObject {
public:
  virtual std::vector<Drawable> GetDrawables() = 0;
};

#endif
