#include "../headers/include.hpp"
#include "../headers/level-select.hpp"

void renderLevelSelection(Texture2D map, Texture2D star, int* countryChoice, GameScreen* state) {
        DrawTexture(map, 0, 0, WHITE);
        
     if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) {
                *countryChoice+=1;
                checkCountry(countryChoice, star);
            }
            else if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) {
                *countryChoice-=1;
                checkCountry(countryChoice, star);
            }
            else {
                checkCountry(countryChoice, star);
                
                if (IsKeyPressed(KEY_ENTER)) {
                    *state = GAMEPLAY;
                }
            }

          
}

void checkCountry(int *countryChoice, Texture2D star) {
     switch (*countryChoice) {
           case 0:
            DrawText("TUTORIAL", 345, 40, 50, RAYWHITE);
            break;
            case 1:
            DrawText("ITALY", 370, 40, 50, RAYWHITE);
            DrawTexture(star, 455, 400, WHITE);
            break;
            case 2:
            DrawText("FRANCE", 370, 40, 50, RAYWHITE);
            DrawTexture(star, 290, 320, WHITE);
            break;
            case 3:
            DrawText("SPAIN", 370, 40, 50, RAYWHITE);
            DrawTexture(star, 170, 395, WHITE);
            break;
            case 4:
            DrawText("BULGARIA", 345, 40, 50, RAYWHITE);
            DrawTexture(star, 645, 380, WHITE);
            break;
            default:
             *countryChoice = 0;
            break;
            }
}

void unloadMap(Texture2D asset1, Texture2D asset2) {
    UnloadTexture(asset1);
    UnloadTexture(asset2); 
    ClearBackground(RAYWHITE);
}