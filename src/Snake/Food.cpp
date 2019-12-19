#include "Food.hpp"

#include <Arduino.h>

Food::Food() {
  moveable.position.x = random(0, 31);
  moveable.position.y = random(0, 15);
  moveable.velocity.x = 0;
  moveable.velocity.y = 0;
  moveable.edgeWrapping = false;
}

std::vector<Drawable> Food::GetDrawables() {
  return {
    { Drawable::Shape::Circle, { (moveable.position.x * 4) + 1, (moveable.position.y * 4) + 1, 1 } }
  };
}

Moveable Food::GetMoveable() {
  return moveable;
}

void Food::SetMoveable(Moveable newMoveable) {
  moveable = newMoveable;
}

void Food::OnCollision(GameObject *other) {
  moveable.position.x = random(0, 31);
  moveable.position.y = random(0, 15);
}

