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
	int ClearFullRows();
private:
	int rows;
	int cols;
	int cellSize;
	int startPosX;
	int startPosY;
	int cellMargin;
	int borderThickness;
	std::vector<Color> colors;
	void DrawBorder();
	bool IsRowFull(int row);
	void ClearRow(int row);
	void MoveRowDown(int row, int rows);
};