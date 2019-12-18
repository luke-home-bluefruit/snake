#ifndef FOOD_HPP
#define FOOD_HPP
#include "Coord.hpp"
#include "GameObject.hpp"

class Food : public GameObject {
  public:
    Food();
    Coord GetPosition();
    std::vector<Drawable> GetDrawables();

  private:
    Coord foodPos;
};

#endif
