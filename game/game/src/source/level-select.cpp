#include "../headers/include.hpp"
#include "../headers/level-select.hpp"

void renderLevelSelection(Texture2D map, Texture2D star, int* countryChoice, GameScreen* state) 
{
    DrawTexture(map, 0, 0, WHITE);

    // Naigate country choice    
    if (IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D)) 
    {
        *countryChoice+=1;
        checkCountry(countryChoice, star);
    }

    else if(IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A)) 
    {
        *countryChoice-=1;
        checkCountry(countryChoice, star);
    }

    else 
    {
        // Check which is the chosen country
        checkCountry(countryChoice, star);
        
        // Start the game of the chosen country
        if (IsKeyPressed(KEY_ENTER)) 
        {
            *state = GAMEPLAY;
        }
    }      
}

// Check country function
void checkCountry(int *countryChoice, Texture2D star) 
{
    switch (*countryChoice) 
    {
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

// Unload map textures
void unloadMap(Texture2D asset1, Texture2D asset2) 
{
    UnloadTexture(asset1);
    UnloadTexture(asset2); 

    // Set the background colour to raywhite
    ClearBackground(RAYWHITE);
}