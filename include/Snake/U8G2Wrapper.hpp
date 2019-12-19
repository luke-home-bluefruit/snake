#ifndef U8G2_WRAPPER_HPP
#define U8G2_WRAPPER_HPP

#include "GraphicsWrapper.hpp"

class U8G2Wrapper : public GraphicsWrapper {
public:
  U8G2Wrapper(int clock, int data, int chipSelect, int dataCommand, int reset);

  void Clear();
  bool Render();
  void DrawCircle(int x, int y, int radius);
  void DrawRectangle(int x, int y, int width, int height);

private:
  void *u8g2;
};

#endif
