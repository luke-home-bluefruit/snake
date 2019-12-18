#ifndef SNAKE_HPP
#define SNAKE_HPP

#include "Coord.hpp"
#include "GameObject.hpp"

#include <vector>

class Snake : public GameObject {
  public:
    Snake();
    void Update();
    std::vector<Drawable> GetDrawables();

  private:
    enum class Direction{North, East, South, West};

    void Move();
    std::vector<int> GetRectangleToNextSegment(int x1, int y1, int x2, int y2);

    std::vector<Coord> segments;
    Direction direction;
    int count;
};



#endif
