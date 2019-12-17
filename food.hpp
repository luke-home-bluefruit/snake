#ifndef FOOD_HPP
#define FOOD_HPP

struct Coord {
  int x;
  int y;
};

class Food {
  public:
    Food() {}
    Coord GetFoodPosition();
    void PickFoodPosition();
  private:
    Coord foodPos;
};

#endif
