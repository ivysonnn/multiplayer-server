#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <vector>
#include <memory>

class Player;

class GameState {
  private: 
    std::vector<std::unique_ptr<Player>> players;

  public:
    GameState() {}

    void addPlayer(std::unique_ptr<Player> player);
    void removePlayer(Player* player);
};

#endif