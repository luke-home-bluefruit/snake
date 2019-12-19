#include "U8G2Wrapper.hpp"

#include <Arduino.h>
#include <SPI.h>
#include <U8g2lib.h>
#include <Wire.h>

#define U8G2 ((U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI*)u8g2)

U8G2Wrapper::U8G2Wrapper(int clock, int data, int chipSelect, int dataCommand, int reset) {
  u8g2 = new U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI(U8G2_R0, clock, data, chipSelect, dataCommand, reset);
  U8G2->begin();
}

void U8G2Wrapper::Clear() {
  U8G2->firstPage();
}

bool U8G2Wrapper::Render() {
  return U8G2->nextPage() != 0;
}

void U8G2Wrapper::DrawCircle(int x, int y, int radius) {
  U8G2->drawDisc(x, y, radius);
}

void U8G2Wrapper::DrawRectangle(int x, int y, int width, int height) {
  U8G2->drawBox(x, y, width, height);
}
