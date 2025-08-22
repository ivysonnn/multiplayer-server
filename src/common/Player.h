#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>

#ifdef IS_CLIENT
#include <raylib.h>
#endif

#include <math.h>
#include "vec2.h"
#include "RGB.h"


class Player {
  private:
    vec2 pos;
    float speed;
    RGB rgb;

  public:
    Player(vec2 startPos, float startSpeed, RGB rgb) : pos(startPos), speed(startSpeed), rgb(rgb) {}
  
    void setSpeed(float speed);
    void Update(float deltaX, float deltaY, float deltaTime);
    #ifdef IS_CLIENT
    void Draw();
    #endif
  };

#endif