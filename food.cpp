#include "food.hpp"
#include <Arduino.h>

Coord Food::GetFoodPosition() {
  return foodPos;
}

void Food::PickFoodPosition() {
  foodPos.x = random(2, 125);
  foodPos.y = random(2, 61);
  // to-do: check we're not overlapping the snake body
}
