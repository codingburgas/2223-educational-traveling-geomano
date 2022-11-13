#include "../headers/include.hpp"
#include "../headers/main-menu-scene.hpp"
#include "../headers/level-select.hpp"
#include "../headers/gameplay-scene.hpp"

int main(void)
{
    // Initialization

    // Window size initialization
    const int screenWidth = 960;   
    const int screenHeight = 524;

    // Window initialization
    InitWindow(screenWidth, screenHeight, "Eurobunnea");    
    GameScreen currentScreen = INTRO;

    // Assets initialization
    Texture2D introScreen1 = LoadTexture("../src/assets/intro-screen-1.png");
    Texture2D introScreen2 = LoadTexture("../src/assets/intro-screen-2.png");
    Texture2D introScreen3 = LoadTexture("../src/assets/intro-screen-3.png");
    Texture2D introScreen4 = LoadTexture("../src/assets/intro-screen-4.png");

    Texture2D mainBackground = LoadTexture("../src/assets/main-menu-bg.png");   
    Texture2D exitBackground = LoadTexture("../src/assets/exit-request-bg.png");
    Texture2D map = LoadTexture("../src/assets/level-select-map.png");
    Texture2D tutorialBackground = LoadTexture("../src/assets/tutorial-bg.png");
    Texture2D franceBackground = LoadTexture("../src/assets/france-bg.png");
    Texture2D bulgariaBackground = LoadTexture("../src/assets/bulgaria-maze.png");
    Texture2D italyBackground1 = LoadTexture("../src/assets/italy-bg-1.png"); 
    Texture2D italyBackground2 = LoadTexture("../src/assets/italy-bg-2.png"); 
    Texture2D italyBackground3 = LoadTexture("../src/assets/italy-bg-3.png"); 
    
    Texture2D goal = LoadTexture("../src/assets/star-select.png");
    Texture2D textbox = LoadTexture("../src/assets/textbox.png");
    Texture2D franceGirlIdle = LoadTexture("../src/assets/france-girl.png");
    Texture2D franceGirlTalk = LoadTexture("../src/assets/france-girl-talk.png");
    Texture2D rabbitDetailed = LoadTexture("../src/assets/bunny-large.png");

    Texture2D startBtn = LoadTexture("../src/assets/main-menu-button.png");
    Texture2D startBtnHover = LoadTexture("../src/assets/main-menu-button.png");
    Texture2D star = LoadTexture("../src/assets/star-select.png");
    Texture2D rose = LoadTexture("../src/assets/rose.png");

    Texture2D front = LoadTexture("../src/assets/front.png");
    Texture2D frontIdle = LoadTexture("../src/assets/front-2.png");
    Texture2D frontWalk1 = LoadTexture("../src/assets/front-walk-1.png");
    Texture2D frontWalk2 = LoadTexture("../src/assets/front-walk-2.png");
    
    Texture2D back = LoadTexture("../src/assets/back.png");
    Texture2D backIdle = LoadTexture("../src/assets/back-2.png");
    Texture2D backWalk1 = LoadTexture("../src/assets/back-walk-1.png");
    Texture2D backWalk2 = LoadTexture("../src/assets/back-walk-2.png");

    Texture2D left = LoadTexture("../src/assets/left.png");
    Texture2D left2 = LoadTexture("../src/assets/left-2.png");
    Texture2D leftWalk2 = LoadTexture("../src/assets/left-walk-2.png");
    Texture2D right = LoadTexture("../src/assets/right.png");
    Texture2D right2 = LoadTexture("../src/assets/right-2.png");
    Texture2D rightWalk2 = LoadTexture("../src/assets/right-walk-2.png");
    
    Texture2D boatRabbit1 = LoadTexture("../src/assets/italy-rabbit-1.png");
    Texture2D boatRabbit2 = LoadTexture("../src/assets/italy-rabbit-2.png");
    Texture2D boatRabbit3 = LoadTexture("../src/assets/italy-rabbit-3.png");
    // Initilize the necessary variables
    
    // X and Y position of the rabbit
    Vector2 rabbitPosition = { 440, 420 };
    Vector2 rabbitBoatPosition = { 0, 295 };
    
    Color firstColor = WHITE;
    Color secondColor = WHITE;

    int frame = 0;
    int frameIntroCount = 0;
    int franceDialogue = 0;
    int rabbitDirection = 0;
    int countryChoice = 0;
    int franceDialogueCounter = 0;
    float timer = 0.0f;
    bool isFrench = 1;
    bool isFrenchTalking = 0;
    bool completedTotal[5] = {0, 0, 0, 0, 0};

    questionPts franceQuestions;
    questionPts tempCorrect;
    
    SetExitKey(KEY_NULL); //set exit key to make custom exit request
    bool exitWindowRequested = false;   // Flag to request window to exit
    bool exitWindow = false;

    // Set game FPS
    SetTargetFPS(60);   

    // Detect window close and main game loop
    while (!exitWindow)    
    {
        // Update variables here
        Vector2 mousePos = GetMousePosition();
        timer += GetFrameTime();
        if (timer >= 0.4f) 
        {
            timer = 0.0f;
            frame += 4;
        }

        frame = frame % 3;
        frameIntroCount = frameIntroCount + 1;

        if (WindowShouldClose() || IsKeyPressed(KEY_ESCAPE)) exitWindowRequested = true;

        if (exitWindowRequested) //Check if player has pressed exit key
        {
            if (IsKeyPressed(KEY_Y)) exitWindow = true; //check for player confirmation
            else if (IsKeyPressed(KEY_N)) exitWindowRequested = false;
        }

        // Begin drawing
        BeginDrawing();

        //Clear the colour of the background
        ClearBackground(RAYWHITE);

        //Check current screen state

         if (exitWindowRequested)
            {
                DrawTexture(exitBackground, 0, 0, WHITE);
                DrawText("Would you like to exit?", 280, 230, 30, WHITE);
                DrawText("[Y/N]", 430, 280, 40, ORANGE);
            }
        else 
        {
        switch(currentScreen)
        {
            case INTRO:
            {
                std::cout << " " << (frameIntroCount/30)  << " ";
                DrawTexture(mainBackground, 0, 0, WHITE);
            
                if (((frameIntroCount/10)) < 3)
                {
                    DrawTexture(introScreen1, 0, 0, WHITE);
                }
                else if (((frameIntroCount/10)) == 3)
                {
                    UnloadTexture(introScreen1);
                    DrawTexture(introScreen2, 0, 0, WHITE);
                }
                else if (((frameIntroCount/10)) == 4)
                {
                    UnloadTexture(introScreen2);
                    DrawTexture(introScreen3, 0, 0, WHITE);
                }
                else if (((frameIntroCount/10)) == 5)
                {
                    UnloadTexture(introScreen3);
                    DrawTexture(introScreen4, 0, 0, WHITE);
                }
                else if (((frameIntroCount/10)) == 6)
                {
                    UnloadTexture(introScreen4);
                    currentScreen = TITLE;
                }

            break;
            }
            case TITLE:
            renderMainMenu(mainBackground, startBtn, startBtnHover, mousePos, &currentScreen);
            break;

            case LEVELSELECT:
            DisableCursor();
            renderLevelSelection(map, star, &countryChoice, &currentScreen);

            //Check if any country game is completed
            (completedTotal[0]) ? DrawText("-Tutorial Completed", 30, 110, 20, GRAY) : DrawText("", 30, 110, 20, GRAY);
            (completedTotal[1]) ? DrawText("-Italy Completed", 30, 110, 20, GRAY) : DrawText("", 30, 110, 20, GRAY);
            (completedTotal[2]) ? DrawText("-France Completed", 30, 110, 20, GRAY) : DrawText("", 30, 110, 20, GRAY);
            (completedTotal[3]) ? DrawText("-Spain Completed", 30, 110, 20, GRAY) : DrawText("", 30, 110, 20, GRAY);
            (completedTotal[4]) ? DrawText("-Bulgaria Completed", 30, 110, 20, GRAY) : DrawText("", 30, 110, 20, GRAY);
            break;

            //Check chosen country
            case GAMEPLAY:
            switch (countryChoice) 
            {
                case 0:
                completedTotal[0] = 1;
                renderTutorial(&currentScreen, &rabbitPosition, &rabbitDirection, frame, &front, &frontIdle, &frontWalk1, &frontWalk2, &left, &left2, &leftWalk2, &right, &right2, &rightWalk2, &back, &backIdle, &backWalk1, &backWalk2, &tutorialBackground, &goal);
                break;

                case 1:
                completedTotal[1] = 1;
                renderItaly(&currentScreen, &rabbitBoatPosition, frame, &boatRabbit1, &boatRabbit2, &boatRabbit3, italyBackground1, italyBackground2, italyBackground3);
                break;

                case 2:
                renderFrance(&currentScreen, &isFrench, &isFrenchTalking, &franceBackground, &franceGirlIdle, &franceGirlTalk, &rabbitDetailed, &textbox, &franceDialogue, &firstColor, &secondColor, &franceDialogueCounter, &franceQuestions, &tempCorrect, &completedTotal[2]);
                break;

                case 3:
                completedTotal[3] = 1;
                renderSpain(&currentScreen, &rabbitPosition, &rabbitDirection, frame, &front, &left, &left2, &right, &right2, &back);
                break;

                case 4:
                completedTotal[4] = 1;
                renderBulgaria(&currentScreen, &rabbitPosition, &rabbitDirection, frame, &front, &frontIdle, &frontWalk1, &frontWalk2, &left, &left2, &leftWalk2, &right, &right2, &rightWalk2, &back, &backIdle, &backWalk1, &backWalk2, &bulgariaBackground, &rose);
                break;

                default:
                currentScreen = LEVELSELECT;
                break;
            }
            break;
        }
        }
        // End drawing
        EndDrawing();
    }

    //Unload thr map
    unloadMap(map, star);

    // Close window
    CloseWindow(); 
    
    return 0;
}