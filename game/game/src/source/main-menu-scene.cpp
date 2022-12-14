#include "../headers/include.hpp"
#include "../headers/main-menu-scene.hpp"

// Main menu function
void renderMainMenu(Texture2D mainBackground, Texture2D button, Texture2D buttonHover, Vector2 mousePos, GameScreen* state) 
{
    // Draw the texture of the menu
    DrawTexture(mainBackground,0, 0, WHITE);
    DrawTexture(button, 280, 312, WHITE);

    Rectangle btnCollide = {280, 312, 360, 70};

    // Check if the cursor is over menu options
    if (CheckCollisionPointRec(mousePos, btnCollide)) 
    {
        // UnloadTexture(button);
        DrawTexture(buttonHover, 280, 312, WHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
        {
            *state = LEVELSELECT;
        }
    }
    
    if (IsKeyReleased(KEY_ENTER)) 
    {
        *state = LEVELSELECT;
    }
}

// Unload textures from the menu
void unloadMenu(Texture2D asset1, Texture2D asset2, Texture2D asset3) 
{
    UnloadTexture(asset1);
    UnloadTexture(asset2);
    UnloadTexture(asset3);
    
    ClearBackground(RAYWHITE);
}