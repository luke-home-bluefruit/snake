#ifndef U8G2_WRAPPER_HPP
#define U8G2_WRAPPER_HPP
#include "GraphicsWrapper.hpp"

class U8G2Wrapper : public GraphicsWrapper {
public:
  U8G2Wrapper();
  void Clear();
  bool Render();
  void DrawCircle(int x, int y, int radius);
  void DrawRectangle(int x, int y, int width, int height);
};

#endif
