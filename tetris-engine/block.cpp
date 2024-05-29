#include "block.h"

Block::Block() {
	cellSize = 30;
	rotationState = 0;
	colors = GetCellColors();
	rowOffset = 0;
	colOffset = 0;
	gameGridStartPosX = 0;
	gameGridStartPosY = 0;
	gameAreaBorderLineThickness = 5;
	cellMargin = 0;
}

void Block::Draw() {
	std::vector<Position> tiles = GetCellPosition();

	for (Position item : tiles) {
		DrawRectangle(gameGridStartPosX + item.col * cellSize + cellMargin, gameGridStartPosY + item.row * cellSize + cellMargin, cellSize - cellMargin, cellSize - cellMargin, colors[id]);
	}
}


void Block::Move(int rows, int cols) {
	rowOffset += rows;
    colOffset += cols;
}

void Block::Rotate()
{
	rotationState++;

	if (rotationState == (int) cells.size()) {
		rotationState = 0;
	}
}

void Block::UndoRotation()
{
	rotationState--;

	if (rotationState == -1) {
		rotationState = cells.size() - 1;
	}
}

void Block::Initialize(int cellSize, int cellMargin, int gameGridStartPosX, int gameGridStartPosY, int gameAreaBorderLineThickness)
{
	this->cellSize = cellSize;
	this->cellMargin = cellMargin;
	this->gameGridStartPosX = gameGridStartPosX;
	this->gameGridStartPosY = gameGridStartPosY;
	this->gameAreaBorderLineThickness = gameAreaBorderLineThickness;
}

std::vector<Position> Block::GetCellPosition() {
	std::vector<Position> tiles = cells[rotationState];
	std::vector<Position> movedTiles;
	for (Position item : tiles) {
		Position newPos = Position(item.row + rowOffset, item.col + colOffset);
		movedTiles.push_back(newPos);
	}

	return movedTiles;
}