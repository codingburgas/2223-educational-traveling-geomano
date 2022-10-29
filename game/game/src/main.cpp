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

    Texture2D mainBackground = LoadTexture("../src/assets/main-menu-bg.png");   //Assets initialization
    Texture2D map = LoadTexture("../src/assets/level-select-map.png");
    Texture2D tutorialBackground = LoadTexture("../src/assets/tutorial-bg.png");
    Texture2D goal = LoadTexture("../src/assets/star-select.png");

    Texture2D startBtn = LoadTexture("../src/assets/main-menu-button.png");
    Texture2D startBtnHover = LoadTexture("../src/assets/main-menu-button.png");
    Texture2D star = LoadTexture("../src/assets/star-select.png");

    Texture2D front = LoadTexture("../src/assets/front.png");
    Texture2D back = LoadTexture("../src/assets/back.png");
    Texture2D right = LoadTexture("../src/assets/right.png");
    Texture2D left = LoadTexture("../src/assets/left.png");
    Texture2D right2 = LoadTexture("../src/assets/right-2.png");
    Texture2D left2 = LoadTexture("../src/assets/left-2.png");

    Vector2 rabbitPosition = { (float)screenWidth/2, (float)screenHeight/2 };
    int rabbitDirection = 0;
    int countryChoice = 0;
    float timer = 0.0f;
    int frame = 0;
    bool completedTotal[5] = {0, 0, 0, 0, 0};
    
    SetTargetFPS(60);   // Set game fps

    while (!WindowShouldClose())    // Detect window close + main game loop
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
           Vector2 mousePos = GetMousePosition();
           timer += GetFrameTime();
           if (timer >= 0.2f) {
            timer = 0.0f;
            frame += 1;
           }

           frame = frame % 2;
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
                DisableCursor();
                unloadMenu(mainBackground, startBtn, startBtnHover);
                renderLevelSelection(map, star, &countryChoice, &currentScreen);

                (completedTotal[0]) ? DrawText("-Tutorial Completed", 30, 110, 20, GRAY) : DrawText("", 30, 110, 20, GRAY);
                (completedTotal[1]) ? DrawText("-Italy Completed", 30, 110, 20, GRAY) : DrawText("", 30, 110, 20, GRAY);
                (completedTotal[2]) ? DrawText("-France Completed", 30, 110, 20, GRAY) : DrawText("", 30, 110, 20, GRAY);
                (completedTotal[3]) ? DrawText("-Spain Completed", 30, 110, 20, GRAY) : DrawText("", 30, 110, 20, GRAY);
                (completedTotal[4]) ? DrawText("-Bulgaria Completed", 30, 110, 20, GRAY) : DrawText("", 30, 110, 20, GRAY);

                break;

                case GAMEPLAY:
                switch (countryChoice) {
                case 0:
                    completedTotal[0] = 1;
                    renderTutorial(&currentScreen, &rabbitPosition, &rabbitDirection, frame, &front, &left, &left2, &right, &right2, &back, &tutorialBackground, &goal);
                    break;
                    case 1:
                    completedTotal[1] = 1;
                    renderItaly(&currentScreen, &rabbitPosition, &rabbitDirection, frame, &front, &left, &left2, &right, &right2, &back);
                    break;
                    case 2:
                    completedTotal[2] = 1;
                    renderFrance(&currentScreen, &rabbitPosition, &rabbitDirection, frame, &front, &left, &left2, &right, &right2, &back);
                    break;
                    case 3:
                    completedTotal[3] = 1;
                    renderSpain(&currentScreen, &rabbitPosition, &rabbitDirection, frame, &front, &left, &left2, &right, &right2, &back);
                    break;
                    case 4:
                    completedTotal[4] = 1;
                    renderBulgaria(&currentScreen, &rabbitPosition, &rabbitDirection, frame, &front, &left, &left2, &right, &right2, &back);
                    break;
                    default:
                    currentScreen = LEVELSELECT;
                    break;
                    }
                break;
            }

        EndDrawing();
    }
    unloadMap(map, star);
    CloseWindow();  // Close window
    return 0;
}