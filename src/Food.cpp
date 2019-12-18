#include "Food.hpp"
#include <Arduino.h>

//grid is 25x * 12y of 5x5 pixels
Food::Food() {
  foodPos.x = (5 * random(0, 24)) + 1;
  foodPos.y = (5 * random(0, 11)) + 1;
}

Coord Food::GetPosition() {
  return foodPos;
}

void Food::Draw(GraphicsWrapper &graphics) {
  graphics.DrawCircle(foodPos.x, foodPos.y, 2);
}
