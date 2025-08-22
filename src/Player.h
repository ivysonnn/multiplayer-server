#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <raylib.h>
#include <math.h>

class Player {
  private:
    Vector2 pos;
    float speed;
    Color color;

  public:
    Player(Vector2 startPos, float startSpeed, Color color) : pos(startPos), speed(startSpeed), color(color) {}
  
    void setSpeed(float speed);
    void move(float deltaX, float deltaY);
    void draw();
  };

#endif