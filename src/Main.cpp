#include <raylib.h>

int main(void)
{
    const int screenWidth = 1024;
    const int screenHeight = 768;

    InitWindow(screenWidth, screenHeight, "snake");

    SetTargetFPS(60);              
    // Main game loop
    while (!WindowShouldClose())   
    {
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
    }

   
    CloseWindow();   

    return 0;
}