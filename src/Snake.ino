#include "Game.hpp"
#include "U8G2Wrapper.hpp"
#include <Arduino.h>

#define ANALOG_PIN_0 14

static Game *game;

void setup(void) {
  U8G2Wrapper *graphics = new U8G2Wrapper();

  Serial.begin(9600);
  unsigned int rngSeed = analogRead(ANALOG_PIN_0);

  game = new Game(*graphics, rngSeed);
}

void loop(void) {
  game->Loop();
}
