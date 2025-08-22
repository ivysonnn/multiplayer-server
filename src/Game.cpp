#include "Game.h"

void Game::Start() {
  const int screenWidth = 1080;
  const int screenHeight = 720;

  InitWindow(screenWidth, screenHeight, "Multiplayer Server");
  SetTargetFPS(60);

  Player player(Vector2{screenWidth / 2, screenHeight / 2}, 5.0f, GREEN);

  while (!WindowShouldClose()) {
    float deltaX = 0.0f;
    float deltaY = 0.0f;

    if (IsKeyDown(KEY_W)) deltaY -= 1.0f;
    if (IsKeyDown(KEY_S)) deltaY += 1.0f;
    if (IsKeyDown(KEY_A)) deltaX -= 1.0f;
    if (IsKeyDown(KEY_D)) deltaX += 1.0f;
    if (IsKeyDown(KEY_LEFT_SHIFT)) player.setSpeed(7.5f);
    else player.setSpeed(5.0f);

    player.move(deltaX, deltaY);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    player.draw();
    EndDrawing();
  }

  CloseWindow();
}