#include <string>
#include "../headers/include.hpp"
#include "../headers/gameplay-scene.hpp"

using namespace std;

// France questions and aswers struct
struct franceTest 
{
    // Questions array
    string franceQuestions[7] = 
    {
        "The Alps run through France.", // True
        "France is the most visited country in the\nworld with 83 million tourists.", // True
        "Louis XIX was king of France for\njust 30 minutes.", // False
        "There are no stop signs in\nthe entire city of Paris.", // True
        "In France it is legal to name a pig Napoleon.", // False
        "The current president of France\nis Francois Hollande.", // False
        "In France you can marry a dead person.", // True
    }; 

    // Answers array
    bool franceAnswers[20] = {true, true, false, true, false, false, true};
    vector<bool> isCorrect = {0};
}franceVar;

// Initiliaze necessary variables
int testScore = 0;
int select = 0;
string newStr;

// Rabbit movement in tutorial
void renderRabbit(Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* frontIdle, Texture2D* frontWalk1, Texture2D* frontWalk2, Texture2D* left, Texture2D* left2, Texture2D* leftWalk2, Texture2D* right, Texture2D* right2, Texture2D* rightWalk2, Texture2D* back, Texture2D* backIdle, Texture2D* backWalk1, Texture2D* backWalk2) 
{   
    // Set X and Y coordinates
    Vector2 temp = *rabbitPosition;
    int radius = 92;


    // Navigate rabbit movement via Right key or D key
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) 
    {   
        // Check if the rabbit is in screen bounds
        if (temp.x < (GetScreenWidth() - radius)) 
        {
            temp.x += 2.0f;
            *rabbitPosition = temp;
        }

        // Draw right texture
        if (frame == 1) 
        {
            DrawTextureV(*right2, *rabbitPosition, WHITE);
        }
        
        else if (frame == 2) 
        {
            DrawTextureV(*right, *rabbitPosition, WHITE);
            temp.y -= 0.05f;
            *rabbitPosition = temp;
        }

        else if (frame == 3) 
        {
            DrawTextureV(*right2, *rabbitPosition, WHITE);
        }

        else 
        {
            temp.y += 0.05f;
            *rabbitPosition = temp;
            DrawTextureV(*rightWalk2, *rabbitPosition, WHITE);
        }

        *rabbitDirection = 1;
    }

    // Navigate rabbit movement via Left key or A key
    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) 
    {
        // Check if the rabbit is in screen bounds
        if (!(temp.x < 8))
        {
            temp.x -= 2.0f;
            *rabbitPosition = temp;
        }

        // Draw the appropiate texture (right or left)
        if (frame == 1) 
        {
            DrawTextureV(*left2, *rabbitPosition, WHITE);
        }
        
        else if (frame == 2) 
        {
            DrawTextureV(*left, *rabbitPosition, WHITE);
            temp.y -= 0.05f;
            *rabbitPosition = temp;
        }

        else if (frame == 3) 
        {
            DrawTextureV(*left2, *rabbitPosition, WHITE);
        }

        else 
        {
            temp.y += 0.05f;
            *rabbitPosition = temp;
            DrawTextureV(*leftWalk2, *rabbitPosition, WHITE);
        }
        
        *rabbitDirection = 2;
    }   

    // Navigate rabbit movement via Up key or W key
    else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) 
    {  
        // Check if the rabbit is in screen bounds
        if(!(temp.y < 3))
        {
            temp.y -= 2.0f;
            *rabbitPosition = temp;
        }
        
        // Draw the appropiate back texture
        if (frame == 1) 
        {
            DrawTextureV(*backWalk1, *rabbitPosition, WHITE);
        }

        else if (frame == 2) 
        {
            DrawTextureV(*backIdle, *rabbitPosition, WHITE);
            temp.y += 0.f;
            *rabbitPosition = temp;
        }

        else if (frame == 3) 
        {
            DrawTextureV(*backWalk2, *rabbitPosition, WHITE);
        }

        else 
        {
            DrawTextureV(*backWalk1, *rabbitPosition, WHITE);
        }

        *rabbitDirection = 3;
    }

    // Navigate rabbit movement via Down key or S key
    else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) 
    {
        // Check if the rabbit is in screen bounds
        if (temp.y < (GetScreenHeight() - radius)) 
        {
            temp.y += 2.0f;
            *rabbitPosition = temp;
        }

        // Draw the appropiate front texture
        if (frame == 1) 
        {
            DrawTextureV(*frontWalk1, *rabbitPosition, WHITE);
        }

        else if (frame == 2) 
        {
            DrawTextureV(*frontIdle, *rabbitPosition, WHITE);
            temp.y -= 0.4f;
            *rabbitPosition = temp;
        }

        else if (frame == 3) 
        {
            DrawTextureV(*frontWalk2, *rabbitPosition, WHITE);
        }

        else 
        {
            DrawTextureV(*frontWalk1, *rabbitPosition, WHITE);
        }

        *rabbitDirection = 4;
    }

    else 
    {
        // Draw the appropiate idle texture (right, left, back or front)
        switch (*rabbitDirection)
        {
            case 1:
            DrawTextureV(*right2, *rabbitPosition, WHITE);
            break;

            case 2:
            DrawTextureV(*left2,* rabbitPosition, WHITE);
            break;

            // Draw the appropiate back texture
            case 3:
            if (frame == 1 || frame == 3 || frame == 4)
            {
                DrawTextureV(*back, *rabbitPosition, WHITE);
            }
                
            else
            {
                DrawTextureV(*backIdle, *rabbitPosition, WHITE);
            }
            break;

            // Draw the appropiate front texture
            case 4:
            if (frame == 1 || frame == 3 || frame == 4)
            {
                DrawTextureV(*front, *rabbitPosition, WHITE);
            }
                
            else
            {
                DrawTextureV(*frontIdle, *rabbitPosition, WHITE);
            }
            break;
            
            default:
            if (frame == 1 || frame == 3)
            {
                DrawTextureV(*front, *rabbitPosition, WHITE);
            }
            
            else
            {
                DrawTextureV(*frontIdle, *rabbitPosition, WHITE);
            }
            break;
        }
    }
}

void renderRabbitBoat(Vector2* rabbitPosition, int frame, Texture2D* front, Texture2D* front2, Texture2D* front3) 
{   
    // Set X and Y coordinates
    Vector2 temp = *rabbitPosition;

    if(temp.x >= (GetScreenWidth() - 200))
    {
        ClearBackground(DARKGRAY);
        DrawText("THAT'S IT!", GetScreenWidth() / 4, GetScreenHeight() / 3, 70, GRAY);
    }

    // Navigate rabbit boat movement via Right key or D key
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) 
    {   
        // Check if the rabbit is in screen bounds
        if (temp.x < (GetScreenWidth() - 200)) 
        {
            //Move quicker when going forward
            temp.x += 2.0f; 
            *rabbitPosition = temp;
        }
    }

    // Navigate rabbit movement via Left key or A key
    else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) 
    {
        // Check if the rabbit is in screen bounds
        if (!(temp.x < 0))
        {
            temp.x -= 1.5f;
            *rabbitPosition = temp;
        }
    }   
    
    // Navigate rabbit movement via Up key or W key
    else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) 
    {  
        // Check if the rabbit is in screen bounds
        if(!(temp.y < 220))
        {
            temp.y -= 1.5f;
            *rabbitPosition = temp;
        }

    }

    // Navigate rabbit movement via Down key or S key
    else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) 
    {
        // Check if the rabbit is in screen bounds
        if (temp.y < (GetScreenHeight() - 125)) 
        {
            temp.y += 1.5f;
            *rabbitPosition = temp;
        }
    }

   if (frame == 1 || frame == 3)
        {
            DrawTextureV(*front, *rabbitPosition, WHITE);
        }
        else if (frame == 2) 
        {
            DrawTextureV(*front2, *rabbitPosition, WHITE);
        }
        else
        {
            DrawTextureV(*front3, *rabbitPosition, WHITE);
        }
}

void resetAllLevels(Vector2 *rabbitPosition, int* rabbitDirection, Vector2 *rabbitBoatPosition,  Vector2 *fish1Position, Vector2 *fish2Position, Vector2 *fish3Position, questionPts *isCorrect, int* dialogueProgress)
{
    Vector2 rabbitTempPosition;
    Vector2 rabbitBoatTempPosition;
    Vector2 fish1TempPosition;
    Vector2 fish2TempPosition;
    Vector2 fish3TempPosition;

    rabbitTempPosition = { 440, 420 }; 
    *rabbitPosition = rabbitTempPosition;
    *rabbitDirection = 3;

    rabbitBoatTempPosition = { 0, 295 }; 
    fish1TempPosition = { 700, 320 };
    fish2TempPosition = { 1400, 420 };
    fish3TempPosition = { 2100, 400 };
    *rabbitBoatPosition = rabbitBoatTempPosition;
    *fish1Position = fish1TempPosition;
    *fish2Position = fish2TempPosition;
    *fish3Position = fish3TempPosition;

    isCorrect->Q1 = 0;
    isCorrect->Q2 = 0;
    isCorrect->Q3 = 0;
    isCorrect->Q4 = 0;
    isCorrect->Q5 = 0;
    isCorrect->Q6 = 0;
    isCorrect->Q7 = 0;

    testScore = 0;
    *dialogueProgress = 0;
}
// Tutorial function
void renderTutorial(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* frontIdle, Texture2D* frontWalk1, Texture2D* frontWalk2, Texture2D* left, Texture2D* left2, Texture2D* leftWalk2, Texture2D* right, Texture2D* right2, Texture2D* rightWalk2, Texture2D* back, Texture2D* backIdle, Texture2D* backWalk1, Texture2D* backWalk2, Texture2D* background, Texture2D* goal, bool* isCompleted) 
{
    // Set X and Y coordinates
    Vector2 temp = *rabbitPosition;

    // Star coordinates
    Rectangle goalLocation = {850, 400, 500, 500};

    //Draw necessary textures
    DrawTexture(*background, 0, 0, WHITE);
    DrawTexture(*goal, 850, 400, WHITE);

    renderRabbit(rabbitPosition, rabbitDirection, frame, front, frontIdle, frontWalk1, frontWalk2, left, left2, leftWalk2, right, right2, rightWalk2, back, backIdle, backWalk1, backWalk2);
    
    DrawText("Use WASD/ARROW KEYS to move. Use ENTER to confirm. Reach the star to proceed.", 40, 70, 20, GRAY);

    // Check if the star has been reached
    if (CheckCollisionCircleRec(temp, 85 , goalLocation))
    {
        *state = LEVELSELECT;
        rabbitPosition ->x = 440; 
        rabbitPosition ->y = 420;
        *rabbitDirection = 3;
    }
}

// Italy function
void renderItaly(GameScreen* state, Vector2* rabbitPosition, Vector2* fish1Position, Vector2* fish2Position, Vector2* fish3Position, int frame, Texture2D* front, Texture2D* front2, Texture2D* front3, Texture2D background1, Texture2D background2, Texture2D background3, Texture2D fish1, Texture2D fish2, Texture2D fish3, Texture2D fish1ani, Texture2D fish2ani, Texture2D fish3ani, bool* isCompleted) 
{
    if (frame == 1) 
    {
        DrawTexture(background1, 0, 0, WHITE);
    }
    else if (frame == 2)
    {
        DrawTexture(background3, 0, 0, WHITE);
    }
    else if (frame == 3)
    {
        DrawTexture(background2, 0, 0, WHITE);
    }
    else
    {
        DrawTexture(background2, 0, 0, WHITE);
    }

    // Add temporary vector to save fishes' location
    Vector2 rabbitTempPosition = *rabbitPosition;
    Vector2 fish1TempPosition = *fish1Position;
    Vector2 fish2TempPosition = *fish2Position;
    Vector2 fish3TempPosition = *fish3Position;

    Rectangle rabbitCollision = {rabbitTempPosition.x, rabbitTempPosition.y, 380, 60};
    Rectangle fish1Collision = {fish1TempPosition.x, fish1TempPosition.y, 140, 60};
    Rectangle fish2Collision = {fish2TempPosition.x, fish2TempPosition.y, 140, 60};
    Rectangle fish3Collision = {fish3TempPosition.x, fish3TempPosition.y, 140, 60};
    
    // Check if there is a collision between the boat and the first fish
     if (CheckCollisionRecs(rabbitCollision, fish1Collision)) 
    {
       //return everything to default position
       rabbitTempPosition = { 0, 295 }; 
       fish1TempPosition = { 700, 320 };
       fish2TempPosition = { 1400, 420 };
       fish3TempPosition = { 2100, 400 };
       *rabbitPosition = rabbitTempPosition;
       *fish1Position = fish1TempPosition;
       *fish2Position = fish1TempPosition;
       *fish3Position = fish1TempPosition;

       //go back to level selection
       *state = LEVELSELECT; 
    }
    else //else make fish 1 move
    {
        fish1TempPosition.x -= 1.8f;
        *fish1Position = fish1TempPosition;
    }

    // Check if there is a collision between the boat and the second fish
    if (CheckCollisionRecs(rabbitCollision, fish2Collision)) 
    {
       //return everything to default position
       rabbitTempPosition = { 0, 295 }; 
       fish1TempPosition = { 700, 320 };
       fish2TempPosition = { 1400, 420 };
       fish3TempPosition = { 2100, 400 };
       *rabbitPosition = rabbitTempPosition;
       *fish1Position = fish1TempPosition;
       *fish2Position = fish1TempPosition;
       *fish3Position = fish1TempPosition;

       //go back to level selection
       *state = LEVELSELECT; 
    }
    else //else make fish 2 move
    {
        fish2TempPosition.x -= 1.8f;
        *fish2Position = fish2TempPosition;
    }

    // Check if there is a collision between the boat and the third fish
    if (CheckCollisionRecs(rabbitCollision, fish3Collision)) 
    {
       //return everything to default position
       rabbitTempPosition = { 0, 295 }; 
       fish1TempPosition = { 700, 320 };
       fish2TempPosition = { 1400, 420 };
       fish3TempPosition = { 2100, 400 };
       *rabbitPosition = rabbitTempPosition;
       *fish1Position = fish1TempPosition;
       *fish2Position = fish1TempPosition;
       *fish3Position = fish1TempPosition;

       //go back to level selection
       *state = LEVELSELECT; 
    }
    else //else make fish 3 move
    {
        fish3TempPosition.x -= 1.8f;
        *fish3Position = fish3TempPosition;
    }
     
    if (frame == 1 || frame == 3) 
    {
        DrawTextureV(fish1, *fish1Position, WHITE);
        DrawTextureV(fish2, *fish2Position, WHITE);
        DrawTextureV(fish3, *fish3Position, WHITE);
    }
    else
    {
        DrawTextureV(fish1ani, *fish1Position, WHITE);
        DrawTextureV(fish2ani, *fish2Position, WHITE);
        DrawTextureV(fish3ani, *fish3Position, WHITE);
    }

    renderRabbitBoat(rabbitPosition, frame, front, front2, front3);
}

// Function used to reset colours and point counters of chosen answers in France quiz
void optionPickFrance(int indexCounter, Color* firstColor, Color* secondColor) 
{
    // Check if TRUE is selected
    if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
    {
        *firstColor = ORANGE;
        *secondColor = WHITE;
        select = 1;
    }

    // Check if FALSE is selected
    else if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
    {
        *firstColor = WHITE;
        *secondColor = ORANGE;
        select = 2;
    }
}

// France quiz function
void renderFrance(GameScreen* state, bool* isFrench, bool* isFrenchTalking, Texture2D* background, Texture2D* girlIdle, Texture2D* girlTalk, Texture2D* rabbitIdle, Texture2D* textbox, int* dialogueProgress, Color *firstColor, Color *secondColor, int* indexCounter, questionPts* isCorrect, questionPts* tempCorrect, bool* isCompleted) {
   //Draw necessary textures
   DrawTexture(*background, 0, 0, WHITE);
   DrawTexture(*rabbitIdle, 600, 70, WHITE);

   // Check if state of the game is the girl's speech
   if (*isFrench == 1 && *isFrenchTalking == 1) 
   {
        DrawTexture(*girlTalk, 40, 40, WHITE);
   }

   else if (*isFrench == 1 && *isFrenchTalking == 0) 
   {
        DrawTexture(*girlIdle, 40, 40, WHITE);
   }

   DrawTexture(*textbox, 0, 355, WHITE);
    
   std::cout << *dialogueProgress - 3 << " " << select << endl;
   
   // Check if the quiz has been started
   if(IsKeyPressed(KEY_ENTER)) 
   {
        *dialogueProgress += 1;
        *firstColor = WHITE;
        *secondColor = WHITE;

        if(IsKeyPressed(KEY_ENTER))
        {
            switch (*dialogueProgress)
            {
                case 4:

                // Check the correct answer of question 1
                if (select == 1)
                {   
                    isCorrect->Q1 = 1;
                }
                else
                {
                    isCorrect->Q1 = 0;
                }
                break;
                
                // Check the correct answer of question 2
                case 5:
                if (select == 1)
                { 
                    isCorrect->Q2 = 1;
                }
                else
                {
                    isCorrect->Q2 = 0;
                }
                break;
                
                // Check the correct answer of question 3
                case 6:
                if (select == 2)
                {
                    isCorrect->Q3 = 1;
                }
                else
                {
                    isCorrect->Q3 = 0;
                }
                break;

                // Check the correct answer of question 4
                case 7:
                if (select == 1)
                {
                    isCorrect->Q4 = 1;
                }
                else
                {
                    isCorrect->Q4 = 0;
                }
                break;

                // Check the correct answer of question 5
                case 8:
                if (select == 2)
                {
                    isCorrect->Q5 = 1;
                }
                else
                {
                    isCorrect->Q5 = 0;
                }
                break;

                // Check the correct answer of question 6
                case 9:
                if (select == 2)
                {
                    isCorrect->Q6 = 1;
                }
                else
                {
                    isCorrect->Q6 = 0;
                }
                break;

                // Check the correct answer of question 7
                case 10:
                if (select == 1)
                { 
                    isCorrect->Q7 = 1;
                }
                else
                {
                    isCorrect->Q7 = 0;
                }
                break;

                default:
                break;
            }  
        }
    }

    const char* temp;

    switch(*dialogueProgress) 
    {   
        // Speech before the quiz
        case 1:
        *isFrenchTalking = 1;

        DrawText("Welcome!", 130, 420, 35, WHITE);
        DrawText("I have some questions for you!", 130, 450, 35, WHITE);
        break;

        case 2:
        *isFrenchTalking = 0;

        DrawText("(Score over 5 to complete successfully!)", 130, 430, 32, GRAY);
        break;

        case 3:
        *isFrenchTalking = 1;

        // Convert questions from string to character in order to be drawn
        temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();

        optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
        
        DrawText(temp, 130, 420, 25, WHITE);
        DrawText("True", 740, 415, 35, *firstColor);
        DrawText("False", 740, 450, 35, *secondColor);
        break;

        case 4:
        // Convert questions from string to character in order to be drawn
        temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();

        optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
        
        DrawText(temp, 130, 420, 25, WHITE);
        DrawText("True", 740, 415, 35, *firstColor);
        DrawText("False", 740, 450, 35, *secondColor);
        break;

        case 5:
        // Convert questions from string to character in order to be drawn
        temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();

        optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
        
        DrawText(temp, 130, 420, 25, WHITE);
        DrawText("True", 740, 415, 35, *firstColor);
        DrawText("False", 740, 450, 35, *secondColor);
        break;

        case 6:
        // Convert questions from string to character in order to be drawn
        temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();

        optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
        
        DrawText(temp, 130, 420, 25, WHITE);
        DrawText("True", 740, 415, 35, *firstColor);
        DrawText("False", 740, 450, 35, *secondColor);
        break;

        case 7:
        // Convert questions from string to character in order to be drawn
        temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();

        optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
        
        DrawText(temp, 130, 420, 25, WHITE);
        DrawText("True", 740, 415, 35, *firstColor);
        DrawText("False", 740, 450, 35, *secondColor);
        break;

        case 8:
        // Convert questions from string to character in order to be drawn
        temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();

        optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
        
        DrawText(temp, 130, 420, 25, WHITE);
        DrawText("True", 740, 415, 35, *firstColor);
        DrawText("False", 740, 450, 35, *secondColor);
        break;

        case 9:
        // Convert questions from string to character in order to be drawn
        temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();
        
        optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
        
        DrawText(temp, 130, 420, 25, WHITE);
        DrawText("True", 740, 415, 35, *firstColor);
        DrawText("False", 740, 450, 35, *secondColor);
        break;

        case 10:
        DrawText("That's it!", 130, 440, 35, WHITE);
        break;

        case 11:
        *isFrenchTalking = 0;
        
        // Summarize and compare the given answers with the correct answers
        DrawText("Correct:", 400, 420, 25, ORANGE);
        
            if(isCorrect->Q1) 
        {
            DrawText("Q1", 300, 460, 20, ORANGE);
            franceVar.isCorrect[0] = 1;
        }
        else 
        {
            DrawText("Q1", 300, 460, 20, GRAY);
            franceVar.isCorrect[0] = 0;
        }

        if(isCorrect->Q2) 
        {
            DrawText("Q2", 340, 460, 20, ORANGE);
            franceVar.isCorrect[1] = 1;
        }
        else 
        {
            DrawText("Q2", 340, 460, 20, GRAY);
            franceVar.isCorrect[1] = 0;
        }

        if(isCorrect->Q3) 
        {
            DrawText("Q3", 380, 460, 20, ORANGE);
           franceVar.isCorrect[2] = 1;
        }
        else 
        {
            DrawText("Q3", 380, 460, 20, GRAY);
            franceVar.isCorrect[2] = 0;
        }

        if(isCorrect->Q4) 
        {
            DrawText("Q4", 420, 460, 20, ORANGE);
            franceVar.isCorrect[3] = 1;
        }
        else 
        {
            DrawText("Q4", 420, 460, 20, GRAY);
            franceVar.isCorrect[3] = 1;
        }

        if(isCorrect->Q5) 
        {
            DrawText("Q5", 460, 460, 20, ORANGE);
            franceVar.isCorrect[4] = 1;
        }
        else 
        {
            DrawText("Q5", 460, 460, 20, GRAY);
            franceVar.isCorrect[4] = 0;
        }

        if(isCorrect->Q6) 
        {
            DrawText("Q6", 500, 460, 20, ORANGE);
            franceVar.isCorrect[5] = 1;
        }
        else 
        {
            DrawText("Q6", 500, 460, 20, GRAY);
            franceVar.isCorrect[5] = 0;
        }

        if(isCorrect->Q7)
        {
            DrawText("Q7", 540, 460, 20, ORANGE);
            franceVar.isCorrect[6] = 1;
        }
        else 
        {
            DrawText("Q7", 540, 460, 20, GRAY);
            franceVar.isCorrect[6] = 0;
        }

        break;

        case 12:
        if(franceVar.isCorrect[0])
        {
            testScore += 1;
            franceVar.isCorrect[0] = 0;
        }
        if(franceVar.isCorrect[1])
        {
            testScore += 1;
            franceVar.isCorrect[1] = 0;
        }
        if(franceVar.isCorrect[2])
        {
            testScore += 1;
            franceVar.isCorrect[2] = 0;
        }
        if(franceVar.isCorrect[3])
        {
            testScore += 1;
            franceVar.isCorrect[3] = 0;
        }
        if(franceVar.isCorrect[4])
        {
            testScore += 1;
            franceVar.isCorrect[4] = 0;
        }
        if(franceVar.isCorrect[5])
        {
            testScore += 1;
            franceVar.isCorrect[5] = 0;
        }
        if(franceVar.isCorrect[6])
        {
            testScore += 1;
            franceVar.isCorrect[6] = 0;
        }
        if(franceVar.isCorrect[7])
        {
            testScore += 1;
            franceVar.isCorrect[7] = 0;
        }

        if (testScore > 5) 
        {
            *isCompleted = true;
        }

        isCorrect->Q1 = 0;
        isCorrect->Q2 = 0;
        isCorrect->Q3 = 0;
        isCorrect->Q4 = 0;
        isCorrect->Q5 = 0;
        isCorrect->Q6 = 0;
        isCorrect->Q7 = 0;

        *state = LEVELSELECT;
        testScore = 0;
        *dialogueProgress = 0;

        default:
        *isFrenchTalking = 0;
        break;
    }
}

// Spain function
void renderSpain(GameScreen* state, int* choice, bool completedTotal[], Texture2D background, Texture2D rabbit, Texture2D outfit1, Texture2D outfit2, Texture2D outfit3, Texture2D outfit4, Texture2D outfit5, Texture2D outfit6, Texture2D outfit7)
{
    EnableCursor();
    DrawTexture(background, 0, 0, WHITE);
    DrawTexture(rabbit, 170, -70, WHITE);

     if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) 
    {
        *choice+=1;
    }
    else if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) 
    {
        *choice-=1;
    }

    switch(*choice) {
        case -1:
        *choice = 0;
        break;

        case 0:
        break;

        case 1:
        DrawTexture(outfit1, 170, -70, WHITE);
        break;

        case 2:
        DrawTexture(outfit2, 170, -70, WHITE);
        break;

        case 3:
        if (completedTotal[0])
        {
            DrawTexture(outfit3, 170, -70, WHITE);
        }
        else
        {
            *choice = 4;
        }
        break;

        case 4:
        if (completedTotal[3])
        {
            DrawTexture(outfit4, 170, -70, WHITE);
        }
        else
        {
            *choice = 5;
        }

        case 5:
        if (completedTotal[2])
        {
            DrawTexture(outfit5, 170, -70, WHITE);
        }
        else
        {
            *choice = 6;
        }
        break;

        case 6:
        if (completedTotal[4])
        {
            DrawTexture(outfit6, 170, -70, WHITE);
        }
        else
        {
            *choice = 7;
        }
        break;

        case 7:
        if (completedTotal[2])
        {
            DrawTexture(outfit5, 170, -70, WHITE);
        }
        else
        {
            *choice = 8;
        }
        break;

        case 8:
        if (completedTotal[5])
        {
            DrawTexture(outfit5, 170, -70, WHITE);
        }
        else
        {
            *choice = 0;
        }
        break;

        default:
        break;
        
    }   
}

// Bulgaria function
void renderBulgaria(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* frontIdle, Texture2D* frontWalk1, Texture2D* frontWalk2, Texture2D* left, Texture2D* left2, Texture2D* leftWalk2, Texture2D* right, Texture2D* right2, Texture2D* rightWalk2, Texture2D* back, Texture2D* backIdle, Texture2D* backWalk1, Texture2D* backWalk2, Texture2D* background, Texture2D* goal) 
{
    // Draw background texture
    DrawTexture(*background, 0, 0, WHITE);

    renderRabbit(rabbitPosition, rabbitDirection, frame, front, frontIdle, frontWalk1, frontWalk2, left, left2, leftWalk2, right, right2, rightWalk2, back, backIdle, backWalk1, backWalk2);

    // Initiliaze maze rectangles
    Rectangle collision1 = {50, 335, 30, 105};
    Rectangle collision2 = {5, 135, 90, 30};
    Rectangle collision3 = {60, 40, 125, 30};
    Rectangle collision4 = {155, 80, 30, 260};
    Rectangle collision5 = {95, 235, 30, 15};
    Rectangle collision6 = {200, 130, 80, 25};
    Rectangle collision7 = {205, 330, 400, 15};
    Rectangle collision8 = {265, 235, 25, 105};
    Rectangle collision9 = {375, 235, 25, 105};
    Rectangle collision10 = {375, 235, 120, 20};
    Rectangle collision11 = {255, 0, 30, 40};
    Rectangle collision12 = {365, 0, 30, 40};
    Rectangle collision13 = {490, 365, 30, 80};
    Rectangle collision14 = {560, 240, 50, 100};
    Rectangle collision15 = {355, 30, 125, 25};
    Rectangle collision16 = {465, 65, 30, 45};
    Rectangle collision17 = {585, 0, 30, 35};
    Rectangle collision18 = {680, 40, 30, 180};
    Rectangle collision19 = {680, 45, 110, 30};
    Rectangle collision20 = {680, 230, 130, 25};
    Rectangle collision21 = {780, 0, 30, 135};
    Rectangle collision22 = {360, 140, 245, 25};
    Rectangle collision23 = {680, 355, 55, 90};
    Rectangle collision24 = {680, 330, 125, 15};

    // Check if the rabbit has touched the obstacles
    collisionCheck(collision1, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision2, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision3, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision4, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision5, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision6, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision7, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision8, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision9, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision10, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision11, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision12, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision13, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision14, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision15, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision16, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision17, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision18, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision19, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision20, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision21, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision22, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision23, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision24, rabbitPosition, rabbitDirection, 20);
}

// Collision check function
void collisionCheck(Rectangle rec, Vector2* rabbitPosition, int *rabbitDirection, int radius) 
{
    // Set X and Y coordinates
    Vector2 temp = *rabbitPosition;

    if (CheckCollisionCircleRec(temp, radius, rec)) 
    {
        //Check what is the rabbit direction and set movement speed
        if (*rabbitDirection == 1) 
        {
            temp.x -= 2.0f;
            *rabbitPosition = temp;
        }

        else if (*rabbitDirection == 2) 
        {
            temp.x += 2.0f;
            *rabbitPosition = temp;
        }

        else if (*rabbitDirection == 3) 
        {
            temp.y += 2.0f;
            *rabbitPosition = temp;
        }

        else  
        {
            temp.y -= 2.0f;
            *rabbitPosition = temp;
        }
    }
}