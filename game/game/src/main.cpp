#include "headers/include.hpp"
int main(void)
{
    // Initialization
    const int screenWidth = 1920;   //Window size initialization
    const int screenHeight = 1080;

    InitWindow(screenWidth, screenHeight, "Eurobunnea");    //Window initialization
    loadMainMenuAssets();

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
            loadMainMenu();

        EndDrawing();
    }
    unloadMainMenu();
    CloseWindow();  // Close window
    return 0;
}