#include "include.hpp"
#include "main-menu-scene.hpp"

int main(void)
{
    // Initialization
    const int screenWidth = 960;   //Window size initialization
    const int screenHeight = 524;
    
    bool onMainMenu = 1;

    InitWindow(screenWidth, screenHeight, "Eurobunnea");    //Window initialization
    
    Image backgroundImg = LoadImage("../src/assets/main-menu-bg1.png"); //Image assets initialization
    Image startButton = LoadImage("../src/assets/main-menu-button.png");

    Texture2D mainBackground = LoadTextureFromImage(backgroundImg); // Convert image to texture
    Texture2D startBtn = LoadTextureFromImage(startButton);
    Texture2D startBtnHover = LoadTextureFromImage(startButton);

    UnloadImage(backgroundImg); //Unloading image since its value is given to texture
    UnloadImage(startButton);

    SetTargetFPS(60);   // Set game fps

    while (!WindowShouldClose())    // Detect window close + main game loop
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
           Vector2 mousePos = GetMousePosition();
        //----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(RAYWHITE);

            if(onMainMenu == 1){
            renderMainMenu(mainBackground, startBtn, startBtnHover,mousePos, &onMainMenu);
            }
            else{
                unloadMainMenu(mainBackground, startBtn, startBtnHover);
            }

        EndDrawing();
    }
    CloseWindow();  // Close window
    return 0;
}