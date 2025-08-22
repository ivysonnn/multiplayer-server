#ifndef GAME_H
#define GAME_H

#include <chrono>
#ifdef IS_CLIENT
using namespace ray {
  #include <raylib.h>
}
#endif
#include "GameState.h"
#include "Player.h"
#include "vec2.h"

class Game {
  private:
    GameState gameState;
  public:
  #ifdef IS_CLIENT
    void Start();
  #endif
};

#endif