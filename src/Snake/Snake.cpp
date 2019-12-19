#include "Snake.hpp"

#include <stdlib.h>

Snake::Snake() {
  moveable.position.x = 2;
  moveable.position.y = 5;
  moveable.velocity.x = 1;
  moveable.velocity.y = 0;
  moveable.edgeWrapping = true;

  size = 15;
  segments.push_back({
    moveable.position.x,
    moveable.position.y
  });
}

void Snake::TurnAnticlockwise() {
  int tmp = moveable.velocity.y;
  moveable.velocity.y = moveable.velocity.x;
  moveable.velocity.x = -tmp;
}

void Snake::TurnClockwise() {
  int tmp = moveable.velocity.x;
  moveable.velocity.x = moveable.velocity.y;
  moveable.velocity.y = -tmp;
}

std::vector<Drawable> Snake::GetDrawables() {
  std::vector<Drawable> drawables;

  for (std::size_t i = 0; i < segments.size(); i++) {
    drawables.push_back(Drawable());
    drawables[i].shape = Drawable::Shape::Rectangle;

    if (i != segments.size() - 1)
      drawables[i].properties = GetRectangleToNextSegment(segments[i].x * 4, segments[i].y * 4, segments[i + 1].x * 4, segments[i + 1].y * 4);
    else
      drawables[i].properties = std::vector<int> { segments[i].x * 4, segments[i].y * 4, 3, 3 };    
  }

  return drawables;
}

Moveable Snake::GetMoveable() {
  return moveable;
}

void Snake::SetMoveable(Moveable newMoveable) {
  moveable = newMoveable;
  segments.insert(segments.begin(), moveable.position);
  if (size >= segments.size())
    return;

  (void)segments.pop_back();
}

std::vector<int> Snake::GetRectangleToNextSegment(int x1, int y1, int x2, int y2) {
  int w = abs(x2 - x1) + 3;
  int h = abs(y2 - y1) + 3;
  int x = (x1 < x2) ? x1 : x2;
  int y = (y1 < y2) ? y1 : y2;

  if (w > 7) // horizontal wrapping
  {
    x = x1;
    w = 3;
  }
  if (h > 7) // vertical wrapping
  {
    y = y1;
    h = 3;
  }

  std::vector<int> properties = { x, y, w, h };
  return properties;
}
