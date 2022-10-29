#include "include.hpp"
#include "main-menu-scene.hpp"

void renderMainMenu(Texture2D mainBackground, Texture2D button, Texture2D buttonHover, Vector2 mousePos, GameScreen* state) {
    DrawTexture(mainBackground,0, 0, WHITE);
    DrawTexture(button, 280, 312, WHITE);

    Rectangle btnCollide = {280, 312, 360, 70};

     if (CheckCollisionPointRec(mousePos, btnCollide)) {
         //UnloadTexture(button);
         DrawTexture(buttonHover, 280, 312, WHITE);

        if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            *state = LEVELSELECT;
        }
     }
    if (IsKeyReleased(KEY_ENTER)) {
        *state = LEVELSELECT;
    }
}

void unloadMenu(Texture2D asset1, Texture2D asset2, Texture2D asset3) {
    UnloadTexture(asset1);
    UnloadTexture(asset2);
    UnloadTexture(asset3);
    
    ClearBackground(RAYWHITE);
}