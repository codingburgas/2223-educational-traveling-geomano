#include "raylib.h"
int main(void)
{
    // Initialization
    const int screenWidth = 1920;   //Window size initialization
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Eurobunnea");    //Window initialization

    SetTargetFPS(60);   // Set game fps

    while (!WindowShouldClose())    // Detect window close + main game loop
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawText("First window attempt (I like cats)", (screenWidth / 2) - 260 , 500, 40, MAROON);

        EndDrawing();
    }

    CloseWindow();  // Close window
    return 0;
}