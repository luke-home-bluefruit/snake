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
  std::vector<Drawable> drawables(1, Drawable());

  drawables[0].shape = Drawable::Shape::Circle;
  drawables[0].properties = std::vector<int> { foodPos.x + 1, foodPos.y + 1, 1 };

  return drawables;
}
