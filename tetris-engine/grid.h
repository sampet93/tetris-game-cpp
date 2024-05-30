#pragma once
#include "raylib.h"
#include <vector>

class Grid {
public:
	Grid();
	Grid(int gridWidth, int gridHeight, int cellSize, int cellMargin, int startPosX, int startPosY);
	std::vector<std::vector<int>> grid;
	void Initialize();
	void Print();
	void Draw();
	bool IsCellOutside(int row, int col);
	bool IsCellEmpty(int row, int col);
private:
	int rows;
	int cols;
	int cellSize;
	int startPosX;
	int startPosY;
	int cellMargin;
	int borderThickness;
	void DrawBorder();
	std::vector<Color> colors;
};