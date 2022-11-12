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
    bool franceAnswers[20] = {true, true, false, true, false, false, true, false, false, false, false, false, false};
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

// Tutorial function
void renderTutorial(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* frontIdle, Texture2D* frontWalk1, Texture2D* frontWalk2, Texture2D* left, Texture2D* left2, Texture2D* leftWalk2, Texture2D* right, Texture2D* right2, Texture2D* rightWalk2, Texture2D* back, Texture2D* backIdle, Texture2D* backWalk1, Texture2D* backWalk2, Texture2D* background, Texture2D* goal) 
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
void renderItaly(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back) 
{

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
                break;
                
                // Check the correct answer of question 2
                case 5:
                if (select == 1)
                { 
                    isCorrect->Q2 = 1;
                }
                break;
                
                // Check the correct answer of question 3
                case 6:
                if (select == 2)
                {
                    isCorrect->Q3 = 1;
                }
                break;

                // Check the correct answer of question 4
                case 7:
                if (select == 1)
                {
                    isCorrect->Q4 = 1;
                }
                break;

                // Check the correct answer of question 5
                case 8:
                if (select == 2)
                {
                    isCorrect->Q5 = 1;
                }
                break;

                // Check the correct answer of question 6
                case 9:
                if (select == 2)
                {
                    isCorrect->Q6 = 1;
                }
                break;

                // Check the correct answer of question 7
                case 10:
                if (select == 1)
                { 
                    isCorrect->Q7 = 1;
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
        *tempCorrect = *isCorrect;
        break;

        case 11:
        *isFrenchTalking = 0;
        
        // Summarize and compare the given answers with the correct answers
        DrawText("Correct:", 370, 420, 25, ORANGE);

        if(isCorrect->Q1 == 1)
        testScore += 1;

        if(isCorrect->Q2 == 1)
        testScore += 1;

        if(isCorrect->Q3 == 1)
        testScore += 1;

        if(isCorrect->Q4 == 1)
        testScore += 1;

        if(isCorrect->Q5 == 1)
        testScore += 1;

        if(isCorrect->Q6 == 1)
        testScore += 1;

        if(isCorrect->Q7 == 1)
        testScore += 1;

        // Convert int to character in order to be drawn
        newStr = to_string(testScore);
        temp = newStr.c_str();
        DrawText(temp, 480, 420, 25, YELLOW);

        // Check if the score is above 5
        if(testScore > 5)
        {
            DrawText("You passed!", 520, 423, 20, GRAY);

            isCorrect->Q1 = 0;
            isCorrect->Q2 = 0;
            isCorrect->Q3 = 0;
            isCorrect->Q4 = 0;
            isCorrect->Q5 = 0;
            isCorrect->Q6 = 0;
            isCorrect->Q7 = 0;
        }

        // Highlight correct answers
        if(tempCorrect->Q1 == 1) 
        {
            DrawText("Q1", 300, 460, 20, ORANGE);
        }
        else 
        {
            DrawText("Q1", 300, 460, 20, GRAY);
        }

        if(tempCorrect->Q2 == 1) 
        {
            DrawText("Q2", 340, 460, 20, ORANGE);
        }
        else 
        {
            DrawText("Q2", 340, 460, 20, GRAY);
        }

        if(tempCorrect->Q3 == 1) 
        {
            DrawText("Q3", 380, 460, 20, ORANGE);
        }
        else 
        {
            DrawText("Q3", 380, 460, 20, GRAY);
        }

        if(tempCorrect->Q4 == 1) 
        {
            DrawText("Q4", 420, 460, 20, ORANGE);
        }
        else 
        {
            DrawText("Q4", 420, 460, 20, GRAY);
        }

        if(tempCorrect->Q5 == 1) 
        {
            DrawText("Q5", 460, 460, 20, ORANGE);
        }
        else 
        {
            DrawText("Q5", 460, 460, 20, GRAY);
        }

        if(tempCorrect->Q6 == 1) 
        {
            DrawText("Q6", 500, 460, 20, ORANGE);
        }
        else 
        {
            DrawText("Q6", 500, 460, 20, GRAY);
        }

        if(tempCorrect->Q7 == 1) 
        {
            DrawText("Q7", 540, 460, 20, ORANGE);
        }
        else 
        {
            DrawText("Q7", 540, 460, 20, GRAY);
        }
        break;

        case 12:
        if (testScore > 5) 
        {
            *isCompleted = true;
        }

        *state = LEVELSELECT;
        testScore = 0;
        *dialogueProgress = 0;

        default:
        *isFrenchTalking = 0;
        break;
    }
}

// Spain function
void renderSpain(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back) 
{

}

// Bulgaria function
void renderBulgaria(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* frontIdle, Texture2D* frontWalk1, Texture2D* frontWalk2, Texture2D* left, Texture2D* left2, Texture2D* leftWalk2, Texture2D* right, Texture2D* right2, Texture2D* rightWalk2, Texture2D* back, Texture2D* backIdle, Texture2D* backWalk1, Texture2D* backWalk2, Texture2D* background, Texture2D* goal) 
{
    // Draw background texture
    DrawTexture(*background, 0, 0, WHITE);

    renderRabbit(rabbitPosition, rabbitDirection, frame, front, frontIdle, frontWalk1, frontWalk2, left, left2, leftWalk2, right, right2, rightWalk2, back, backIdle, backWalk1, backWalk2);
    std::cout << rabbitPosition->x << " " << rabbitPosition->y << std::endl;

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