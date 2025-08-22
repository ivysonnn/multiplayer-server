#include "Game.h"

#ifdef IS_CLIENT
void Game::Start() {
  const int screenWidth = 1080;
  const int screenHeight = 720;

  InitWindow(screenWidth, screenHeight, "Multiplayer Server");
  SetTargetFPS(120);

  Player player(vec2{screenWidth / 2, screenHeight / 2}, 400.f, RGB{0, 255, 0, 255});

    std::chrono::steady_clock::time_point lastUpdate = std::chrono::steady_clock::now();
    float deltaTime = 0.0f;

  while (!WindowShouldClose()) {
    auto now = std::chrono::steady_clock::now();
    deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastUpdate).count() / 1000000.0f;
    lastUpdate = now;

    float deltaX = 0.0f;
    float deltaY = 0.0f;

    if (IsKeyDown(KEY_W)) deltaY -= 1.0f;
    if (IsKeyDown(KEY_S)) deltaY += 1.0f;
    if (IsKeyDown(KEY_A)) deltaX -= 1.0f;
    if (IsKeyDown(KEY_D)) deltaX += 1.0f;
    if (IsKeyDown(KEY_LEFT_SHIFT)) player.setSpeed(600.0f);
    else player.setSpeed(400.0f);

    player.Update(deltaX, deltaY, deltaTime);

    BeginDrawing();
    ClearBackground(RAYWHITE);
    player.Draw();
    EndDrawing();
  }

  CloseWindow();
}
#endif