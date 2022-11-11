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
    GameScreen currentScreen = TITLE;

    // Assets initialization
    Texture2D mainBackground = LoadTexture("../src/assets/main-menu-bg.png");   
    Texture2D map = LoadTexture("../src/assets/level-select-map.png");
    Texture2D tutorialBackground = LoadTexture("../src/assets/tutorial-bg.png");
    Texture2D franceBackground = LoadTexture("../src/assets/france-bg.png");
    Texture2D bulgariaBackground = LoadTexture("../src/assets/bulgaria-maze.png");
    
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
    
    // Initilize the necessary variables

    // X and Y position of the rabbit
    Vector2 rabbitPosition = { 440, 420 };
    
    Color firstColor = WHITE;
    Color secondColor = WHITE;

    int frame = 0;
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
    
    // Set game FPS
    SetTargetFPS(60);   

    // Detect window close and main game loop
    while (!WindowShouldClose())    
    {
        // Update the variables here
        Vector2 mousePos = GetMousePosition();
        timer += GetFrameTime();
        if (timer >= 0.4f) 
        {
            timer = 0.0f;
            frame += 4;
        }

        frame = frame % 3;

        // Begin drawing
        BeginDrawing();

        //Clear the colour of the background
        ClearBackground(RAYWHITE);

        //Check what is the current state of the screen
        switch(currentScreen)
        {
            case TITLE:
            renderMainMenu(mainBackground, startBtn, startBtnHover, mousePos, &currentScreen);
            break;

            case LEVELSELECT:
            DisableCursor();
            unloadMenu(mainBackground, startBtn, startBtnHover);
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
                renderItaly(&currentScreen, &rabbitPosition, &rabbitDirection, frame, &front, &left, &left2, &right, &right2, &back);
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

        // End drawing
        EndDrawing();
    }

    //Unload thr map
    unloadMap(map, star);

    // Close window
    CloseWindow(); 
    
    return 0;
}