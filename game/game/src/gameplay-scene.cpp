#include "include.hpp"
#include "gameplay-scene.hpp"

void renderGameplayScene(Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back) {

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
            DrawTextureV(*right, *rabbitPosition, WHITE);
            break;

            case 2:
            DrawTextureV(*left,* rabbitPosition, WHITE);
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