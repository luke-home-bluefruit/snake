#include "Snake.hpp"

#include <stdlib.h>

Snake::Snake(ButtonDriver &buttons) {
  buttons.RegisterKeyPress(0, std::bind(&Snake::KeyAnticlockwisePressCallback, this));
  buttons.RegisterKeyPress(1, std::bind(&Snake::KeyClockwisePressCallback, this));

  direction = Direction::East;

  segments.push_back(Coord(20, 28));
  segments.push_back(Coord(16, 28));
  segments.push_back(Coord(12, 28));
}

void Snake::Update() {
  Move();
}

std::vector<Drawable> Snake::GetDrawables() {
  std::vector<Drawable> drawables;

  for (std::size_t i = 0; i < segments.size(); i++) {
    drawables.push_back(Drawable());
    drawables[i].shape = Drawable::Shape::Rectangle;

    if (i != segments.size() - 1)
      drawables[i].properties = GetRectangleToNextSegment(segments[i].x, segments[i].y, segments[i + 1].x, segments[i + 1].y);
    else
      drawables[i].properties = std::vector<int> { segments[i].x, segments[i].y, 3, 3 };    
  }

  return drawables;
}

void Snake::Move() {
  int newX = segments[0].x;
  int newY = segments[0].y;

  switch (direction) {
  case Direction::North:
    newY -= 4;
    break;

  case Direction::East:
    newX += 4;
    break;

  case Direction::South:
    newY += 4;
    break;

  case Direction::West:
    newX -= 4;
    break;
  }

  newX = (newX + 128) % 128;
  newY = (newY + 64) % 64;

  segments.insert(segments.begin(), Coord(newX, newY));
  segments.pop_back();
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

void Snake::KeyAnticlockwisePressCallback() {
  switch (direction) {
  case Direction::North:
    direction = Direction::West;
    break;

  case Direction::East:
    direction = Direction::North;
    break;

  case Direction::South:
    direction = Direction::East;
    break;

  case Direction::West:
    direction = Direction::South;
    break;
  }
}

void Snake::KeyClockwisePressCallback() {
  switch (direction) {
  case Direction::North:
    direction = Direction::East;
    break;

  case Direction::East:
    direction = Direction::South;
    break;

  case Direction::South:
    direction = Direction::West;
    break;

  case Direction::West:
    direction = Direction::North;
    break;
  }
}
