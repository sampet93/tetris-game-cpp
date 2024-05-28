#include "iostream"
#include "stdio.h"
#include "raylib.h"

using namespace std;

const int screenWidth = 800;
const int screenHeight = 600;

const int gameGridWidth	= 12;
const int gameGridHeight = 18;

Color bgColor = Color{ 20, 160, 133, 255 };

int main() {
	
    InitWindow(screenWidth, screenWidth, "Raylib Window");

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(bgColor);
        EndDrawing();
    }
    
    CloseWindow();
    return 0;

}