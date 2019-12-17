#include "OledSnake.hpp"
#include "food.hpp"
#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>
#include <Wire.h>
#include <stdio.h>

U8G2_SSD1306_128X64_NONAME_1_4W_SW_SPI u8g2(U8G2_R0, 23, 22, 19, 20, 21);

static Food *food;

void setup(void) {
  u8g2.begin();
  food = new Food();
}

void loop(void) {
  food->PickFoodPosition();
  u8g2.firstPage();
  do {
    u8g2.drawCircle(food->GetFoodPosition().x, food->GetFoodPosition().y, 2);
  } while ( u8g2.nextPage() );
  delay(500);
}
