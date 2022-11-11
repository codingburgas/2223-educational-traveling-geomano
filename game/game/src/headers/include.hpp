#pragma once

#include <iostream>
#include "raylib.h"
#include "rlgl.h"

typedef enum GameScreen {TITLE, LEVELSELECT, GAMEPLAY} GameScreen;
class questionPts {
        public:
        bool Q1 = false;
        bool Q2 = false;
        bool Q3 = false;
        bool Q4 = false;
        bool Q5 = false;
        bool Q6 = false;
        bool Q7 = false;
    };