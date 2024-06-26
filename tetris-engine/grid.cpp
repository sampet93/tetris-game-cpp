#include "grid.h"
#include "raylib.h"
#include "colors.h"
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
	cellMargin = 1;
	grid.resize(rows, std::vector<int>(cols, 0));

	Initialize();
	colors = GetCellColors();
}

Grid::Grid(int gridWidth, int gridHeight, int cellSize, int cellMargin, int startPosX, int startPosY)
	: cols(gridWidth), rows(gridHeight), cellSize(cellSize),  cellMargin(cellMargin), startPosX(startPosX), startPosY(startPosY) {
	cellMargin = 2;
	borderThickness = 5;
	grid.resize(rows, std::vector<int>(cols, 0));

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

bool Grid::IsCellOutside(int row, int col)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols) {
		return false;
	}

	return true;
}

bool Grid::IsCellEmpty(int row, int col)
{
	if (grid[row][col] == 0) {
		return true;
	}
	return false;
}

int Grid::ClearFullRows()
{
	int completed = 0;

	for (int row = rows - 1; row >= 0; row--)
	{
		if (IsRowFull(row)) {
			ClearRow(row);
			completed++;
		}
		else if (completed > 0) {
			MoveRowDown(row, completed);
		}
	}
	return 0;
}

void Grid::DrawBorder() {
	Rectangle gameAreaRect;
	gameAreaRect.x = startPosX - borderThickness;
	gameAreaRect.y = startPosY - borderThickness;
	gameAreaRect.width = cols * cellSize + borderThickness + borderThickness + cellMargin;
	gameAreaRect.height = rows * cellSize + borderThickness + borderThickness + cellMargin;

	DrawRectangleLinesEx(gameAreaRect, borderThickness, LIGHTGRAY);
}

bool Grid::IsRowFull(int row)
{
	for (int col = 0; col < cols; col++) {
		if (grid[row][col] == 0) {
			return false;
		}
	}

	return true;
}

void Grid::ClearRow(int row)
{
	for (int col = 0; col < cols; col++) {
		grid[row][col] = 0;
	}
}

void Grid::MoveRowDown(int row, int rows)
{
	for (int col = 0; col < cols; col++) {
		grid[row + rows][col] = grid[row][col];
		grid[row][col] = 0;
	}
}
