#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "ButtonDriver.hpp"
#include "Vec2.hpp"
#include "GameObject.hpp"

#include <vector>

class Snake : public GameObject {
public:
  Snake();
  void TurnAnticlockwise();
  void TurnClockwise();

  std::vector<Drawable> GetDrawables();
  Moveable GetMoveable();
  void SetMoveable(Moveable newMoveable);
  void OnCollision(GameObject *other);

private:
  std::vector<int> GetRectangleToNextSegment(int x1, int y1, int x2, int y2);

  std::size_t size;
  std::vector<Vec2> segments;
  Moveable moveable;
};

#endif
