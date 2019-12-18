#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "Coord.hpp"
#include "GameObject.hpp"
#include <vector>

class Snake : public GameObject {
  public:
    Snake();
    std::vector<Drawable> GetDrawables();
    
  private:
    std::vector<Coord> segments;
    std::vector<int> GetRectangleToNextSegment(int x1, int y1, int x2, int y2);
};

#endif
