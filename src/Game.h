#ifndef GAME_H
#define GAME_H

#include <raylib.h>
#include "GameState.h"
#include "Player.h"
        
class Game {
  private:
    GameState gameState;
  public:
    void Start();
};

#endif