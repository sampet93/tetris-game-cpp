#include "iostream"
#include "stdio.h"
#include "raylib.h"
#include "utils.h"
#include "grid.h"
#include "blocks.cpp"

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

int main() {

    // Game score
    unsigned int score = 0;
	
    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    int gameGridStartPosX = calculateCenterPos(gameGridWidth * gridSize, screenWidth);
    int gameGridStartPosY = calculateCenterPos(gameGridHeight * gridSize, screenHeight);

    Grid grid = Grid(gameGridWidth, gameGridHeight, gridSize, gameGridStartPosX, gameGridStartPosY);
    grid.Print();

    LBlock lBlock = LBlock();
    lBlock.Move(0, 0);

    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(bgColor);

        grid.Draw();
        lBlock.Draw();

        DrawTitleText();

        EndDrawing();
    }
    
    CloseWindow();
    return 0;

}

