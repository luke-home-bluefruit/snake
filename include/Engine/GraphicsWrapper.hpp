#ifndef GRAPHICS_WRAPPER_HPP
#define GRAPHICS_WRAPPER_HPP

class GraphicsWrapper {
public:
  virtual void Clear() = 0;
  virtual bool Render() = 0;
  virtual void DrawCircle(int x, int y, int radius) = 0;
  virtual void DrawRectangle(int x, int y, int width, int height) = 0;
};

#endif
