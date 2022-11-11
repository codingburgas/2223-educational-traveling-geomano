#include <string>
#include "../headers/include.hpp"
#include "../headers/gameplay-scene.hpp"

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

    bool franceAnswers[20] = {true, true, false, true, false, false, true, false, false, false, false, false, false};
}franceVar;

int testScore = 0;
int select = 0;
string newStr;

void renderRabbit(Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* frontIdle, Texture2D* frontWalk1, Texture2D* frontWalk2, Texture2D* left, Texture2D* left2, Texture2D* leftWalk2, Texture2D* right, Texture2D* right2, Texture2D* rightWalk2, Texture2D* back, Texture2D* backIdle, Texture2D* backWalk1, Texture2D* backWalk2) {
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
                    DrawTextureV(*right2, *rabbitPosition, WHITE);
                    }
                else if (frame == 2) {
                    DrawTextureV(*right, *rabbitPosition, WHITE);
                    temp.y -= 0.3f;
                    *rabbitPosition = temp;
                }
                else if (frame == 3) {
                    DrawTextureV(*right2, *rabbitPosition, WHITE);
                }
                else {
                    temp.y += 0.3f;
                    *rabbitPosition = temp;
                    DrawTextureV(*rightWalk2, *rabbitPosition, WHITE);
                }
                *rabbitDirection = 1;
            }

            else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) 
            {
                if (!(temp.x < 8))
                {
                    temp.x -= 2.0f;
                    *rabbitPosition = temp;
                }

                if (frame == 1) {
                    DrawTextureV(*left2, *rabbitPosition, WHITE);
                    }
                else if (frame == 2) {
                    DrawTextureV(*left, *rabbitPosition, WHITE);
                    temp.y -= 0.3f;
                    *rabbitPosition = temp;
                }
                else if (frame == 3) {
                    DrawTextureV(*left2, *rabbitPosition, WHITE);
                }
                else {
                    temp.y += 0.3f;
                    *rabbitPosition = temp;
                    DrawTextureV(*leftWalk2, *rabbitPosition, WHITE);
                }
                *rabbitDirection = 2;
            }   

            else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {  
                if(!(temp.y < 3))
                {
                    temp.y -= 2.0f;
                    *rabbitPosition = temp;
                }
                    
                if (frame == 1) {
                    DrawTextureV(*backWalk1, *rabbitPosition, WHITE);
                    }
                else if (frame == 2) {
                    DrawTextureV(*backIdle, *rabbitPosition, WHITE);
                    temp.y += 0.4f;
                    *rabbitPosition = temp;
                }
                else if (frame == 3) {
                    DrawTextureV(*backWalk2, *rabbitPosition, WHITE);
                }
                else {
                    DrawTextureV(*backWalk1, *rabbitPosition, WHITE);
                }
                *rabbitDirection = 3;
            }

            else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {
                if (temp.y < (GetScreenHeight() - radius)) {
                    temp.y += 2.0f;
                    *rabbitPosition = temp;
                }

               if (frame == 1) {
                    DrawTextureV(*frontWalk1, *rabbitPosition, WHITE);
                    }
                else if (frame == 2) {
                    DrawTextureV(*frontIdle, *rabbitPosition, WHITE);
                    temp.y -= 0.4f;
                    *rabbitPosition = temp;
                }
                else if (frame == 3) {
                    DrawTextureV(*frontWalk2, *rabbitPosition, WHITE);
                }
                else {
                    DrawTextureV(*frontWalk1, *rabbitPosition, WHITE);
                }
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
            if (frame == 1 || frame == 3 || frame == 4)
                DrawTextureV(*back, *rabbitPosition, WHITE);
            else 
                DrawTextureV(*backIdle, *rabbitPosition, WHITE);

            break;

            case 4:
            if (frame == 1 || frame == 3 || frame == 4)
                DrawTextureV(*front, *rabbitPosition, WHITE);
            else 
                DrawTextureV(*frontIdle, *rabbitPosition, WHITE);

            break;
            
            default:
             if (frame == 1 || frame == 3)
                DrawTextureV(*front, *rabbitPosition, WHITE);
            else 
                DrawTextureV(*frontIdle, *rabbitPosition, WHITE);
            break;
            }
        }
}

void renderTutorial(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* frontIdle, Texture2D* frontWalk1, Texture2D* frontWalk2, Texture2D* left, Texture2D* left2, Texture2D* leftWalk2, Texture2D* right, Texture2D* right2, Texture2D* rightWalk2, Texture2D* back, Texture2D* backIdle, Texture2D* backWalk1, Texture2D* backWalk2, Texture2D* background, Texture2D* goal) {
    Vector2 temp = *rabbitPosition;
    Rectangle goalLocation = {850, 400, 500, 500};

    DrawTexture(*background, 0, 0, WHITE);
    DrawTexture(*goal, 850, 400, WHITE);
    renderRabbit(rabbitPosition, rabbitDirection, frame, front, frontIdle, frontWalk1, frontWalk2, left, left2, leftWalk2, right, right2, rightWalk2, back, backIdle, backWalk1, backWalk2);
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

 void optionPickFrance(int indexCounter, Color* firstColor, Color* secondColor) {

    if(IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W))
    {
        *firstColor = ORANGE;
        *secondColor = WHITE;
        select = 1;
    }
    else if(IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S))
    {
        *firstColor = WHITE;
        *secondColor = ORANGE;
        select = 2;
    }
}

void renderFrance(GameScreen* state, bool* isFrench, bool* isFrenchTalking, Texture2D* background, Texture2D* girlIdle, Texture2D* girlTalk, Texture2D* rabbitIdle, Texture2D* textbox, int* dialogueProgress, Color *firstColor, Color *secondColor, int* indexCounter, questionPts* isCorrect, questionPts* tempCorrect, bool* isCompleted) {
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
    
    std::cout << *dialogueProgress - 3 << " " << select << endl;

   if(IsKeyPressed(KEY_ENTER)) {
    *dialogueProgress += 1;
    *firstColor = WHITE;
    *secondColor = WHITE;

       if(IsKeyPressed(KEY_ENTER))
        {
            switch (*dialogueProgress)
            {
            case 4:
            if (select == 1)
               { isCorrect->Q1 = 1;}
                
                break;
            
             case 5:
            if (select == 1)
               { isCorrect->Q2 = 1;}

                break;
            
             case 6:
            if (select == 2)
                {isCorrect->Q3 = 1;}

                break;

             case 7:
            if (select == 1)
                {isCorrect->Q4 = 1;}

                break;

             case 8:
            if (select == 2)
                {isCorrect->Q5 = 1;}

                break;

             case 9:
            if (select == 2)
                {isCorrect->Q6 = 1;}

                break;

             case 10:
            if (select == 1)
               { isCorrect->Q7 = 1;}

                break;

            default:
                break;
            }
        }  
    }

    const char* temp;

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
    temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();

    optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
    
    DrawText(temp, 130, 420, 25, WHITE);
    DrawText("True", 740, 415, 35, *firstColor);
    DrawText("False", 740, 450, 35, *secondColor);
    break;

    case 4:
    temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();

    optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
    
    DrawText(temp, 130, 420, 25, WHITE);
    DrawText("True", 740, 415, 35, *firstColor);
    DrawText("False", 740, 450, 35, *secondColor);
    break;

    case 5:
    temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();

    optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
    
    DrawText(temp, 130, 420, 25, WHITE);
    DrawText("True", 740, 415, 35, *firstColor);
    DrawText("False", 740, 450, 35, *secondColor);
    break;

    case 6:
     temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();

    optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
    
    DrawText(temp, 130, 420, 25, WHITE);
    DrawText("True", 740, 415, 35, *firstColor);
    DrawText("False", 740, 450, 35, *secondColor);
    break;

    case 7:
    temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();

    optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
    
    DrawText(temp, 130, 420, 25, WHITE);
    DrawText("True", 740, 415, 35, *firstColor);
    DrawText("False", 740, 450, 35, *secondColor);
    break;

    case 8:
     temp = franceVar.franceQuestions[*dialogueProgress-3].c_str();

    optionPickFrance(*dialogueProgress-3, firstColor, secondColor);
    
    DrawText(temp, 130, 420, 25, WHITE);
    DrawText("True", 740, 415, 35, *firstColor);
    DrawText("False", 740, 450, 35, *secondColor);
    break;

    case 9:
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

    newStr = to_string(testScore);
    temp = newStr.c_str();
    DrawText(temp, 480, 420, 25, YELLOW);

    if(testScore > 5)
    DrawText("You passed!", 520, 423, 20, GRAY);
    isCorrect->Q1 = 0;
    isCorrect->Q2 = 0;
    isCorrect->Q3 = 0;
    isCorrect->Q4 = 0;
    isCorrect->Q5 = 0;
    isCorrect->Q6 = 0;
    isCorrect->Q7 = 0;
    
    if(tempCorrect->Q1 == 1) {
        DrawText("Q1", 300, 460, 20, ORANGE);
    }else {
        DrawText("Q1", 300, 460, 20, GRAY);
    }

    if(tempCorrect->Q2 == 1) {
        DrawText("Q2", 340, 460, 20, ORANGE);
    }else {
        DrawText("Q2", 340, 460, 20, GRAY);
    }

    if(tempCorrect->Q3 == 1) {
        DrawText("Q3", 380, 460, 20, ORANGE);
    }else {
        DrawText("Q3", 380, 460, 20, GRAY);
    }

    if(tempCorrect->Q4 == 1) {
        DrawText("Q4", 420, 460, 20, ORANGE);
    }else {
        DrawText("Q4", 420, 460, 20, GRAY);
    }

    if(tempCorrect->Q5 == 1) {
        DrawText("Q5", 460, 460, 20, ORANGE);
    }else {
        DrawText("Q5", 460, 460, 20, GRAY);
    }

    if(tempCorrect->Q6 == 1) {
        DrawText("Q6", 500, 460, 20, ORANGE);
    }else {
        DrawText("Q6", 500, 460, 20, GRAY);
    }

    if(tempCorrect->Q7 == 1) {
        DrawText("Q7", 540, 460, 20, ORANGE);
    }else {
        DrawText("Q7", 540, 460, 20, GRAY);
    }

    break;
    case 12:
    if (testScore > 5) {
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

void renderSpain(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back) {

}

void renderBulgaria(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* frontIdle, Texture2D* frontWalk1, Texture2D* frontWalk2, Texture2D* left, Texture2D* left2, Texture2D* leftWalk2, Texture2D* right, Texture2D* right2, Texture2D* rightWalk2, Texture2D* back, Texture2D* backIdle, Texture2D* backWalk1, Texture2D* backWalk2, Texture2D* background, Texture2D* goal) {
    DrawTexture(*background, 0, 0, WHITE);
    renderRabbit(rabbitPosition, rabbitDirection, frame, front, frontIdle, frontWalk1, frontWalk2, left, left2, leftWalk2, right, right2, rightWalk2, back, backIdle, backWalk1, backWalk2);
    std::cout << rabbitPosition->x << " " << rabbitPosition->y << std::endl;

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