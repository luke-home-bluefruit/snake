#include "Food.hpp"
#include "Game.hpp"
#include "Snake.hpp"
#include "U8G2Wrapper.hpp"

#include <Arduino.h>

#define ANALOG_PIN_0 14

static Game *game;

void setup(void) {
  U8G2Wrapper *graphics = new U8G2Wrapper(23, 22, 19, 20, 21);
  
  pinMode(1, INPUT_PULLUP);
  
  Serial.begin(9600);
  unsigned int rngSeed = analogRead(ANALOG_PIN_0);
  randomSeed(rngSeed);

  std::vector<GameObject*> objects {
    new Snake(),
    new Food()
  };
  game = new Game(*graphics, objects);
}

void loop(void) {
  game->Loop();
}
