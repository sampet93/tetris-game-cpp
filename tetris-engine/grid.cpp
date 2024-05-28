#include "grid.h"
#include "raylib.h"
#include <iostream>
#include <vector>

Grid::Grid() {
	rows = 18;
	cols = 12;
	cellSize = 30;
	startPosX = 0;
	startPosY = 0;
	cellMargin = 2;
	borderThickness = 5;

	Initialize();
	colors = GetCellColors();
}

Grid::Grid(int gridWidth, int gridHeight, int cellSize, int startPosX, int startPosY)
	: cols(gridWidth), rows(gridHeight), cellSize(cellSize), startPosX(startPosX), startPosY(startPosY) {
	cellMargin = 2;
	borderThickness = 5;

	Initialize();
	colors = GetCellColors();
}

void Grid::Initialize() {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			grid[row][col] = 0;
		}
	}
}

void Grid::Print() {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			std::cout << grid[row][col] << " ";
		}

		std::cout << std::endl;
	}
}

void Grid::Draw() {
	for (int row = 0; row < rows; row++) {
		for (int col = 0; col < cols; col++) {
			int cellValue = grid[row][col];
			DrawRectangle(startPosX + col * cellSize + cellMargin, startPosY + row * cellSize + cellMargin, cellSize - cellMargin, cellSize - cellMargin, colors[cellValue]);
		}
	}

	DrawBorder();
}

void Grid::DrawBorder() {
	Rectangle gameAreaRect;
	gameAreaRect.x = startPosX - borderThickness;
	gameAreaRect.y = startPosY - borderThickness;
	gameAreaRect.width = cols * cellSize + borderThickness + borderThickness + cellMargin;
	gameAreaRect.height = rows * cellSize + borderThickness + borderThickness + cellMargin;

	DrawRectangleLinesEx(gameAreaRect, borderThickness, LIGHTGRAY);
}

std::vector<Color> Grid::GetCellColors() {
	Color emptyCellColor = Color{ 19, 153, 130, 255 }; // Light green

	return { emptyCellColor };
}