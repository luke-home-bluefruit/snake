#ifndef MOVEABLE_HPP
#define MOVEABLE_HPP

#include "Vec2.hpp"

struct Moveable {
  Vec2 position;
  Vec2 velocity;
  bool edgeWrapping;
};

#endif
