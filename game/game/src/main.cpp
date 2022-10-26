#include "include.hpp"
#include "main-menu-scene.hpp"
#include "level-select.hpp"
#include "gameplay-scene.hpp"

int main(void)
{
    // Initialization
    const int screenWidth = 960;   //Window size initialization
    const int screenHeight = 524;

    InitWindow(screenWidth, screenHeight, "Eurobunnea");    //Window initialization
    GameScreen currentScreen = TITLE;

    Texture2D mainBackground = LoadTexture("../src/assets/main-menu-bg1.png");   //Image assets initialization
    Texture2D map = LoadTexture("../src/assets/level-select-map.png");

    Texture2D startBtn = LoadTexture("../src/assets/main-menu-button.png");
    Texture2D startBtnHover = LoadTexture("../src/assets/main-menu-button.png");
    Texture2D star = LoadTexture("../src/assets/main-menu-bg1.png");

    Texture2D front = LoadTexture("../src/assets/front.png");
    Texture2D back = LoadTexture("../src/assets/back.png");
    Texture2D right = LoadTexture("../src/assets/right.png");
    Texture2D left = LoadTexture("../src/assets/left.png");

    Vector2 rabbitPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    int rabbitDirection = 0;

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

            switch(currentScreen){
                case TITLE:
                renderMainMenu(mainBackground, startBtn, startBtnHover, mousePos, &currentScreen);
                break;

                case LEVELSELECT:
                unloadMainMenu(mainBackground, startBtn, startBtnHover);
                renderLevelSelection(map, star, &currentScreen);
                break;

                case GAMEPLAY:
                unloadMainMenu(mainBackground, startBtn, startBtnHover);
                renderGameplayScene(&rabbitPosition, &rabbitDirection, &front, &left, &right, &back);
                break;
            }

        EndDrawing();
    }
    CloseWindow();  // Close window
    return 0;
}