#include "include.hpp"
#include "gameplay-scene.hpp"

void renderGameplayScene(Vector2* rabbitPosition, int* rabbitDirection, Texture2D* front, Texture2D* left, Texture2D* right, Texture2D* back) {

            Vector2 temp = *rabbitPosition;

            if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
                temp.x += 2.0f;
                *rabbitPosition = temp;

                DrawTextureV(*right, *rabbitPosition, WHITE);
                *rabbitDirection = 1;

            }
            else if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
                temp.x -= 2.0f;
                *rabbitPosition = temp;

                DrawTextureV(*left, *rabbitPosition, WHITE);
                *rabbitDirection = 2;
            }   
            else if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W)) {
                temp.y -= 2.0f;
                *rabbitPosition = temp;

                DrawTextureV(*back, *rabbitPosition, WHITE);
                *rabbitDirection = 3;
            }

            else if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S)) {

            temp.y += 2.0f;
            *rabbitPosition = temp;

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