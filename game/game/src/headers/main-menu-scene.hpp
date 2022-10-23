#pragma once
#include "include.hpp"

Image backgroundImg = LoadImage("src/assets/main-menu-bg1.png");  

void loadMainMenuAssets(){
    ImageResize(&backgroundImg, 1920, 1080); 
}

Texture2D mainBackground = LoadTextureFromImage(backgroundImg); // Convert image to texture

void loadMainMenu(){
    DrawTexture(mainBackground, 0, 0, BLACK);
    UnloadImage(backgroundImg); //Unload image
    
}

void unloadMainMenu(){
    UnloadTexture(mainBackground);
}