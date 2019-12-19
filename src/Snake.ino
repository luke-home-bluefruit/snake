#include "Food.hpp"
#include "Game.hpp"
#include "Snake.hpp"
#include "U8G2Wrapper.hpp"

#include <Arduino.h>

#define ANALOG_PIN_0 14

static Game *game;

void setup(void) {
  U8G2Wrapper *graphics = new U8G2Wrapper(23, 22, 19, 20, 21);

  Serial.begin(9600);
  unsigned int rngSeed = analogRead(ANALOG_PIN_0);
  randomSeed(rngSeed);

  ButtonDriver *buttons = new ButtonDriver();

  Snake* snake = new Snake();
  std::vector<GameObject*> objects {
    snake,
    new Food()
  };

  buttons->RegisterKeyPress(0, std::bind(&Snake::TurnAnticlockwise, snake));
  buttons->RegisterKeyPress(1, std::bind(&Snake::TurnClockwise, snake));
  
  game = new Game(*graphics, objects, *buttons);
}

void loop(void) {
  game->Loop();
}
