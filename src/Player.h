#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <raylib.h>

class Player {
  private:
    Vector2 pos;
    float speed;

  public:
    Player(Vector2 startPos) : pos(startPos) {}

    void move() {}
};

#endif