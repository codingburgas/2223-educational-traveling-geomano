#include "include.hpp"
#include "gameplay-scene.hpp"

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
            rabbitPosition ->x = 960/2; 
            rabbitPosition ->y = 524/2;
        }
}

void renderItaly(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back) {

}

void renderFrance(GameScreen* state, bool* isFrench, bool* isFrenchTalking, Texture2D* background, Texture2D* girlIdle, Texture2D* girlTalk, Texture2D* rabbitIdle, Texture2D* textbox, int* dialogueProgress) {
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
   }
   
   switch(*dialogueProgress) {
    case 1:
    *isFrenchTalking = 1;
    DrawText("Welcome!", 130, 420, 35, WHITE);
    break;
    default:
    *isFrenchTalking = 0;
    break;
   }
}

void renderSpain(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back) {

}

void renderBulgaria(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back) {

}