#include "iostream"
#include "stdio.h"
#include "raylib.h"
#include "utils.h"
#include "game.h"

using namespace std;

const char* titleText = "Tetris";
const int titleFontSize = 48;
const Color titleFontColor = LIGHTGRAY;

const int gameAreaBorderLineThickness = 5;

const int screenWidth = 600;
const int screenHeight = 800;

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
	
    InitWindow(screenWidth, screenHeight, "Tetris");
    SetTargetFPS(60);

    Game game = Game(screenWidth, screenHeight);


    while (!WindowShouldClose()) {
        BeginDrawing();

        ClearBackground(bgColor);
        game.Draw();
        DrawTitleText();

        EndDrawing();
    }
    
    CloseWindow();
    return 0;

}

