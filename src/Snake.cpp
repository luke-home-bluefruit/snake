#include "Snake.hpp"
#include <stdlib.h>

Snake::Snake() {
  segments.push_back(Coord(8,  8));
  segments.push_back(Coord(12, 8));
  segments.push_back(Coord(16, 8));
  segments.push_back(Coord(16, 12));
  segments.push_back(Coord(12, 12));
  segments.push_back(Coord(12, 16));
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

std::vector<int> Snake::GetRectangleToNextSegment(int x1, int y1, int x2, int y2) {
  int x = (x1 < x2) ? x1 : x2;
  int y = (y1 < y2) ? y1 : y2;
  int w = abs(x2 - x1) + 3;
  int h = abs(y2 - y1) + 3;
  std::vector<int> properties = { x, y, w, h };
  return properties;
}