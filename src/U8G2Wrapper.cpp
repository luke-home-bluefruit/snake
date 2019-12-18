#include "U8G2Wrapper.hpp"
#include <U8g2lib.h>
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>

U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI u8g2(U8G2_R0, 23, 22, 19, 20, 21);

U8G2Wrapper::U8G2Wrapper() {
  u8g2.begin();
}

void U8G2Wrapper::Clear() {
  u8g2.firstPage();
}

bool U8G2Wrapper::Render() {
  return u8g2.nextPage() != 0;
}

void U8G2Wrapper::DrawCircle(int x, int y, int radius) {
  u8g2.drawCircle(x, y, radius);
}

void U8G2Wrapper::DrawRectangle(int x, int y, int width, int height) {
  u8g2.drawBox(x, y, width, height);
}
