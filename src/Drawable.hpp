#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP
#include <vector>

struct Drawable {
  enum class Shape {
    Circle,
    Rectangle
  };
  Shape shape;
  std::vector<int> properties;
};

#endif
