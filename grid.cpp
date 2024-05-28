#include "grid.h"
#include <iostream>

Grid::Grid() {
	rows = 20;
	cols = 10;
	cellSize = 30;

	Initialize();
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
			std::cout << grid[row][col] << " ";
		}
		
		std::cout << std::endl;
	}
}