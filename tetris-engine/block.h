#pragma once
#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

class Block {
public:
	Block();
	void Draw();
	void Move(int rows, int cols);
	void Rotate();
	void UndoRotation();
	void Initialize(int cellSize, int cellMargin, int gameGridStartPosX, int gameGridStartPosY, int gameAreaBorderLineThickness);
	std::vector<Position> GetCellPosition();
	int id;
	std::map<int, std::vector<Position>> cells;
private:
	int cellSize;
	int cellMargin;
	int gameGridStartPosX;
	int gameGridStartPosY;
	int gameAreaBorderLineThickness;
	int rotationState;
	int rowOffset;
	int colOffset;
	std::vector<Color> colors;
};