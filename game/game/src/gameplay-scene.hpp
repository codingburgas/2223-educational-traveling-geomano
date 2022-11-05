#pragma once
#include "include.hpp"

void correctAnswerFrance(int* indexCounter, Color* firstColor, Color* secondColor, int* dialogueProgress);
void renderRabbit(Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back);
void renderTutorial(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back, Texture2D* background, Texture2D* goal);
void renderItaly(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back);
void renderFrance(GameScreen* state, bool* isFrench, bool* isFrenchTalking, Texture2D* background, Texture2D* girlIdle, Texture2D* girlTalk, Texture2D* rabbitIdle, Texture2D* textbox, int* dialogueProgress, Color *firstColor, Color *secondColor, int* indexCounter, questionPts* isCorrect, questionPts* tempCorrect, bool* isCompleted);
void renderSpain(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back);
void renderBulgaria(GameScreen* state, Vector2* rabbitPosition, int* rabbitDirection, int frame, Texture2D* front, Texture2D* left, Texture2D* left2, Texture2D* right, Texture2D* right2, Texture2D* back, Texture2D* background, Texture2D* goal);
void collisionCheck(Rectangle rec, Vector2* rabbitPosition, int *rabbitDirection, int radius);