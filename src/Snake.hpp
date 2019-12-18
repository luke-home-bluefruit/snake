#ifndef SNAKE_HPP
#define SNAKE_HPP
#include "Coord.hpp"
#include "GameObject.hpp"
#include <vector>

class Snake : public GameObject {
  public:
    Snake();
    void Draw(GraphicsWrapper &graphics);
    
  private:
    std::vector<Coord> segments; 
};

#endif
