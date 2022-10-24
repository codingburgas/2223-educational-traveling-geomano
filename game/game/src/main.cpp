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

    Vector2 RabbitPosition = { (float)screenWidth/2, (float)screenHeight/2 };

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

            if (IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D))
        {
            RabbitPosition.x += 2.0f;
            DrawTextureV(right1, RabbitPosition, WHITE);
        }

        if (IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A))
        {
            RabbitPosition.x -= 2.0f;
            DrawTextureV(left1, RabbitPosition, WHITE);
        }

        if (IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)) 
        {
            RabbitPosition.y -= 2.0f;
            DrawTextureV(back, RabbitPosition, WHITE);
        }

        if (IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S))
        {
            RabbitPosition.y += 2.0f;
            DrawTextureV(front, RabbitPosition, WHITE);
        }
        
        EndDrawing();
    }
    CloseWindow();  // Close window
    return 0;
}