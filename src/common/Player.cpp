#include "Player.h"

void Player::setSpeed(float speed) {
  this->speed = speed;
}

void Player::Update(float deltaX, float deltaY, float deltaTime) {

  float magnitude = sqrt(deltaX * deltaX + deltaY * deltaY);

  if (magnitude > 0) {
    pos.x += deltaX / magnitude * speed * deltaTime;
    pos.y += deltaY / magnitude * speed * deltaTime;
    return;
  }

  pos.x += deltaX * speed * deltaTime;
  pos.y += deltaY * speed * deltaTime;
}
#ifdef IS_CLIENT
void Player::Draw() {
  ray::DrawCircle(pos.x, pos.y, 40, Color{rgb.r, rgb.g, rgb.b, rgb.a});
}
#endif