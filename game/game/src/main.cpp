#include "include.hpp"
#include "main-menu-scene.hpp"

int main(void)
{
    // Initialization
    const int screenWidth = 960;   //Window size initialization
    const int screenHeight = 524;

    InitWindow(screenWidth, screenHeight, "Eurobunnea");    //Window initialization
    GameScreen currentScreen = TITLE;

    Image backgroundImg = LoadImage("../src/assets/main-menu-bg1.png"); //Image assets initialization
    Image startButton = LoadImage("../src/assets/main-menu-button.png");
    Image frontImg = LoadImage("../src/assets/front1.png");
    Image backImg = LoadImage("../src/assets/back1.png");
    Image rightImg = LoadImage("../src/assets/right1.png");
    Image leftImg = LoadImage("../src/assets/left1.png");

    Texture2D mainBackground = LoadTextureFromImage(backgroundImg); // Convert image to texture
    Texture2D startBtn = LoadTextureFromImage(startButton);
    Texture2D startBtnHover = LoadTextureFromImage(startButton);
    Texture2D front = LoadTextureFromImage(frontImg);
    Texture2D back = LoadTextureFromImage(backImg);
    Texture2D right1 = LoadTextureFromImage(rightImg);
    Texture2D left1 = LoadTextureFromImage(leftImg);

    UnloadImage(backgroundImg); //Unloading image since its value is given to texture
    UnloadImage(startButton);
    UnloadImage(frontImg);
    UnloadImage(backImg);
    UnloadImage(rightImg);
    UnloadImage(leftImg);

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

                case GAMEPLAY:{
                    unloadMainMenu(mainBackground, startBtn, startBtnHover);

            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)){

                rabbitPosition.x += 2.0f;
                DrawTextureV(right1, rabbitPosition, WHITE);
                rabbitDirection = 1;

            }
            else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)){

                rabbitPosition.x -= 2.0f;
                DrawTextureV(left1, rabbitPosition, WHITE);
                rabbitDirection = 2;

                }   
            else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)){

            rabbitPosition.y -= 2.0f;
            DrawTextureV(back, rabbitPosition, WHITE);
            rabbitDirection = 3;

            }

            else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)){

            rabbitPosition.y += 2.0f;
            DrawTextureV(front, rabbitPosition, WHITE);
            rabbitDirection = 4;

            }
            else{

           switch (rabbitDirection)
           {
           case 1:
            DrawTextureV(right1, rabbitPosition, WHITE);
            break;
            case 2:
            DrawTextureV(left1, rabbitPosition, WHITE);
            break;
            case 3:
            DrawTextureV(back, rabbitPosition, WHITE);
            break;
            case 4:
            DrawTextureV(front, rabbitPosition, WHITE);
            break;
            default:
            DrawTextureV(front, rabbitPosition, WHITE);
            break;
             }
             break;
            }
            } 
            }

        EndDrawing();
    }
    CloseWindow();  // Close window
    return 0;
}