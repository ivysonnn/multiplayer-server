#include "Player.h"

void Player::setSpeed(float speed) {
  this->speed = speed;
}

void Player::move(float deltaX, float deltaY) {
  float magnitude = sqrt(deltaX * deltaX + deltaY * deltaY);

  if (magnitude > 0) {
    pos.x += deltaX / magnitude * speed;
    pos.y += deltaY / magnitude * speed;
    return;
  }

  pos.x += deltaX * speed;
  pos.y += deltaY * speed;
}

void Player::draw() {
  DrawCircle(pos.x, pos.y, 40, color);
}