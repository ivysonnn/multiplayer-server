#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include "Player.h"

class GameState {
  private: 
    std::vector<Player> players;

  public:
    GameState() {}

    void addPlayer(Player player) {}
};

#endif