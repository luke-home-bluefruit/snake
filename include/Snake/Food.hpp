#ifndef FOOD_HPP
#define FOOD_HPP

#include "Vec2.hpp"
#include "GameObject.hpp"

class Food : public GameObject {
public:
  Food();

  std::vector<Drawable> GetDrawables();
  Moveable GetMoveable();
  void SetMoveable(Moveable newMoveable);
  void OnCollision(GameObject *other);
  
private:
  Moveable moveable;
};

#endif
