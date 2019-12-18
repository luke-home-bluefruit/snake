#ifndef COORD_HPP
#define COORD_HPP

struct Coord {
  Coord() : x(0), y(0) {}
  Coord(int x, int y) : x(x), y(y) {}
  int x;
  int y;
};

#endif
