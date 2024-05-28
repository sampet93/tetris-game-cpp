#pragma once
class Grid {
public:
	Grid();
	int grid[20][10];
	void Initialize();
	void Print();
	void Draw();
private:
	int rows;
	int cols;
	int cellSize;
};