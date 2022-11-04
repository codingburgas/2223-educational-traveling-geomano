#include "include.hpp"
#include "gameplay-scene.hpp"
#include <string>

using namespace std;

struct franceTest {
    string franceQuestions[7] = 
    {
        "The Alps run through France.", //True
        "France is the most visited country in the\nworld with 83 million tourists.", //True
        "Louis XIX was king of France for\njust 30 minutes.", //False
        "There are no stop signs in\nthe entire city of Paris.", //True
        "In France it is legal to name a pig Napoleon.", //False
        "The current president of France\nis Francois Hollande.", //False
        "In France you can marry a dead person.", // True
    }; 

    bool franceAnswers[7] = {true, true, false, true, false, false, true};
}franceVar;

int testScore = 0;
int select = 0;
string newStr;

void renderRabbit(Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back) {
            Vector2 temp = *rabbitPosition;

            int radius = 92;

            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) 
            {
                if (temp.x < (GetScreenWidth() - radius)) 
                {
                    temp.x += 2.0f;
                    *rabbitPosition = temp;
                }

                if (frame == 1) {
                    DrawTextureV(*right, *rabbitPosition, WHITE);
                }
                else {
                    DrawTextureV(*right2, *rabbitPosition, WHITE);
                }
                *rabbitDirection = 1;

            }

            else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) 
            {
                if (temp.x != 8)
                {
                    temp.x -= 2.0f;
                    *rabbitPosition = temp;
                }

                 if (frame == 1) {
                    DrawTextureV(*left, *rabbitPosition, WHITE);
                    }
                else {
                    DrawTextureV(*left2, *rabbitPosition, WHITE);
                }
                *rabbitDirection = 2;
            }   

            else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) 
            {  
                if(temp.y != 8)
                {
                    temp.y -= 2.0f;
                    *rabbitPosition = temp;
                }
                    
                DrawTextureV(*back, *rabbitPosition, WHITE);
                *rabbitDirection = 3;
            }

            else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
            {
                if (temp.y < (GetScreenHeight() - radius))
                {
                    temp.y += 2.0f;
                    *rabbitPosition = temp;
                }

                DrawTextureV(*front, *rabbitPosition, WHITE);
                *rabbitDirection = 4;
            }

            else {

            switch (*rabbitDirection) {

            case 1:
            DrawTextureV(*right2, *rabbitPosition, WHITE);
            break;

            case 2:
            DrawTextureV(*left2,* rabbitPosition, WHITE);
            break;

            case 3:
            DrawTextureV(*back, *rabbitPosition, WHITE);
            break;

            case 4:
            DrawTextureV(*front,* rabbitPosition, WHITE);
            break;
            
            default:
            DrawTextureV(*front,* rabbitPosition, WHITE);
            break;
            }
        }
}

void renderTutorial(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back, Texture2D* background, Texture2D* goal) {
    Vector2 temp = *rabbitPosition;
    Rectangle goalLocation = {850, 400, 500, 500};

    DrawTexture(*background, 0, 0, WHITE);
    DrawTexture(*goal, 850, 400, WHITE);
    renderRabbit(rabbitPosition, rabbitDirection, frame, front, left, left2, right, right2, back);
    DrawText("Use WASD/ARROW KEYS to move. Use ENTER to confirm. Reach the star to proceed.", 40, 70, 20, GRAY);

        if (CheckCollisionCircleRec(temp, 85 , goalLocation))
        {
            *state = LEVELSELECT;
            rabbitPosition ->x = 440; 
            rabbitPosition ->y = 420;
            *rabbitDirection = 3;
        }
}

void renderItaly(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back) {

}

 void correctAnswerFrance(int indexCounter) {
     if(select == 1 && franceVar.franceAnswers[indexCounter] == true)
    {
       if(IsKeyPressed(KEY_ENTER))
        {
            testScore++;
        }  
    }

    if(select == 2 && franceVar.franceAnswers[indexCounter] == false)
    {
       if(IsKeyPressed(KEY_ENTER))
        {
            testScore++;
        }  
    }
}

void renderFrance(GameScreen* state, bool* isFrench, bool* isFrenchTalking, Texture2D* background, Texture2D* girlIdle, Texture2D* girlTalk, Texture2D* rabbitIdle, Texture2D* textbox, int* dialogueProgress, Color *firstColor, Color *secondColor, bool* isCompleted) {
   DrawTexture(*background, 0, 0, WHITE);
   DrawTexture(*rabbitIdle, 600, 70, WHITE);

   if (*isFrench == 1 && *isFrenchTalking == 1) {
        DrawTexture(*girlTalk, 40, 40, WHITE);
   }
   else if (*isFrench == 1 && *isFrenchTalking == 0) {
        DrawTexture(*girlIdle, 40, 40, WHITE);
   }
   else {
   }

   DrawTexture(*textbox, 0, 355, WHITE);

   if(IsKeyPressed(KEY_ENTER)) {
    *dialogueProgress += 1;
    *firstColor = WHITE;
    *secondColor = WHITE;
   }

    const char* temp;
    int indexCounter = 0;

   switch(*dialogueProgress) {
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
    temp = franceVar.franceQuestions[indexCounter].c_str();

    if(IsKeyPressed(KEY_DOWN))
    {
        *firstColor = WHITE;
        *secondColor = ORANGE;
        select = 2;
    }

    if(IsKeyPressed(KEY_UP))
    {
        *firstColor = ORANGE;
        *secondColor = WHITE;
        select = 1;
    }

    correctAnswerFrance(indexCounter);
    
    DrawText(temp, 130, 420, 25, WHITE);
    DrawText("True", 740, 415, 35, *firstColor);
    DrawText("False", 740, 450, 35, *secondColor);
    break;

    case 4:
    indexCounter+=1;
    temp = franceVar.franceQuestions[indexCounter].c_str();

    if(IsKeyPressed(KEY_DOWN))
    {
        *firstColor = WHITE;
        *secondColor = ORANGE;
    }

    if(IsKeyPressed(KEY_UP))
    {
        *firstColor = ORANGE;
        *secondColor = WHITE;
    }

   correctAnswerFrance(indexCounter);

    DrawText(temp, 130, 420, 25, WHITE);
    DrawText("True", 740, 415, 35, *firstColor);
    DrawText("False", 740, 450, 35, *secondColor);
    break;

    case 5:
    indexCounter+=2;
    temp = franceVar.franceQuestions[indexCounter].c_str();

    if(IsKeyPressed(KEY_DOWN))
    {
        *firstColor = WHITE;
        *secondColor = ORANGE;
    }

    if(IsKeyPressed(KEY_UP))
    {
        *firstColor = ORANGE;
        *secondColor = WHITE;
    }

    correctAnswerFrance(indexCounter);

    DrawText(temp, 130, 420, 25, WHITE);
    DrawText("True", 740, 415, 35, *firstColor);
    DrawText("False", 740, 450, 35, *secondColor);
    break;

    case 6:
    indexCounter+=3;
    temp = franceVar.franceQuestions[indexCounter].c_str();

    if(IsKeyPressed(KEY_DOWN))
    {
        *firstColor = WHITE;
        *secondColor = ORANGE;
    }

    if(IsKeyPressed(KEY_UP))
    {
        *firstColor = ORANGE;
        *secondColor = WHITE;
    }

    correctAnswerFrance(indexCounter);

    DrawText(temp, 130, 420, 25, WHITE);
    DrawText("True", 740, 415, 35, *firstColor);
    DrawText("False", 740, 450, 35, *secondColor);
    break;

    case 7:
    indexCounter+=4;
    temp = franceVar.franceQuestions[indexCounter].c_str();

    if(IsKeyPressed(KEY_DOWN))
    {
        *firstColor = WHITE;
        *secondColor = ORANGE;
    }

    if(IsKeyPressed(KEY_UP))
    {
        *firstColor = ORANGE;
        *secondColor = WHITE;
    }

    correctAnswerFrance(indexCounter);

    DrawText(temp, 130, 420, 25, WHITE);
    DrawText("True", 740, 415, 35, *firstColor);
    DrawText("False", 740, 450, 35, *secondColor);
    break;

    case 8:
    indexCounter+=5;
    temp = franceVar.franceQuestions[indexCounter].c_str();

    if(IsKeyPressed(KEY_DOWN))
    {
        *firstColor = WHITE;
        *secondColor = ORANGE;
    }

    if(IsKeyPressed(KEY_UP))
    {
        *firstColor = ORANGE;
        *secondColor = WHITE;
    }

    correctAnswerFrance(indexCounter);

    DrawText(temp, 130, 420, 25, WHITE);
    DrawText("True", 740, 415, 35, *firstColor);
    DrawText("False", 740, 450, 35, *secondColor);
    break;

    case 9:
    *isFrenchTalking = 0;
    temp = "You have received ";
    DrawText(temp, 130, 420, 25, GRAY);

    newStr = to_string(testScore);
    temp = newStr.c_str();

    if (testScore == 0) {
     DrawText("no", 370, 420, 25, GRAY);
    }
    else {
    DrawText(temp, 370, 420, 25, ORANGE);
    }
    if(testScore == 1)
    {
        temp = "carrot.";
    }


    else if(testScore == 7)
    {
        DrawText("Brilliant, you have received all the 7 carrots", 150, 420, 25, WHITE);
    }
    
    break;
    case 10:
    *dialogueProgress = 0;
    if (testScore > 5) {
        *isCompleted = true;
    }
    *state = LEVELSELECT;
    testScore = 0;

    default:
    *isFrenchTalking = 0;
    break;
   }
}

void renderSpain(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back) {

}

void renderBulgaria(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back, Texture2D* background, Texture2D* goal) {
    DrawTexture(*background, 0, 0, WHITE);
    renderRabbit(rabbitPosition, rabbitDirection, frame, front, left, left2, right, right2, back);
    std::cout << rabbitPosition->x << " " << rabbitPosition->y << std::endl;

    Rectangle collision1 = {50, 335, 30, 105};
    Rectangle collision2 = {5, 135, 90, 30};
    Rectangle collision3 = {60, 40, 105, 30};
    Rectangle collision4 = {95, 235, 70, 30};
    Rectangle collision5 = {150, 340, 30, 320};
    //Rectangle collision6 = {60, 40, 105, 30};

    collisionCheck(collision1, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision2, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision3, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision4, rabbitPosition, rabbitDirection, 20);
    collisionCheck(collision5, rabbitPosition, rabbitDirection, 20);
}

void collisionCheck(Rectangle rec, Vector2* rabbitPosition, int *rabbitDirection, int radius) {
    Vector2 temp = *rabbitPosition;
    if (CheckCollisionCircleRec(temp, radius, rec)) {
        if (*rabbitDirection == 1) {
            temp.x -= 2.0f;
            *rabbitPosition = temp;
        }
        else if (*rabbitDirection == 2) {
            temp.x += 2.0f;
            *rabbitPosition = temp;
        }
        else if (*rabbitDirection == 3) {
            temp.y += 2.0f;
            *rabbitPosition = temp;
        }
        else  {
            temp.y -= 2.0f;
            *rabbitPosition = temp;
        }
    }
}