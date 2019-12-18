#include "Game.hpp"
#include "U8G2Wrapper.hpp"

static Game *game;

void setup(void) {
  U8G2Wrapper *graphics = new U8G2Wrapper();
  game = new Game(*graphics);
}

void loop(void) {
  game->Loop();
}
