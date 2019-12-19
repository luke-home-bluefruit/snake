#include "Food.hpp"

#include <Arduino.h>

Food::Food() {
  foodPos.x = (4 * random(0, 31));
  foodPos.y = (4 * random(0, 15));
}

Coord Food::GetPosition() {
  return foodPos;
}

void Food::Update() { }

std::vector<Drawable> Food::GetDrawables() {
  return {
    { Drawable::Shape::Circle, { foodPos.x + 1, foodPos.y + 1, 1 } }
  };
}
