#include "iostream"
#include "stdio.h"
#include "raylib.h"
#include "utils.h"

using namespace std;

const char* titleText = "Tetris";
const int titleFontSize = 48;
const Color titleFontColor = LIGHTGRAY;

const int screenWidth = 600;
const int screenHeight = 800;

const int gameGridWidth	= 12;
const int gameGridHeight = 18;
const int gridSize = 30;
const int gameAreaBorderLineThickness = 5;

Color bgColor = Color{ 20, 160, 133, 255 };
Color gameAreaBorderColor = LIGHTGRAY;

void DrawTitleText() {
    int textWidth = MeasureText(titleText, titleFontSize);
    int textHeight = textWidth;

    int textPosX = calculateCenterPos(textWidth, screenWidth);
    int textPosY = 25;

    DrawText(titleText, textPosX, textPosY, titleFontSize, titleFontColor);
}

void DrawGameArea() {
    Rectangle gameAreaRect;
    gameAreaRect.x = calculateCenterPos(gameGridWidth * gridSize, screenWidth);
    gameAreaRect.y = calculateCenterPos(gameGridHeight * gridSize, screenHeight);
    gameAreaRect.width = gameGridWidth * gridSize;
    gameAreaRect.height = gameGridHeight * gridSize;

    DrawRectangleLinesEx(gameAreaRect, gameAreaBorderLineThickness, gameAreaBorderColor);
}

int main() {


    // Game score
    unsigned int score = 0;
	
    InitWindow(screenWidth, screenHeight, "Tetris");

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(bgColor);

        DrawGameArea();

        DrawTitleText();

        EndDrawing();
    }
    
    CloseWindow();
    return 0;

}

