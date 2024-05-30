#pragma once
#include "grid.h"
#include "blocks.cpp"

class Game {
public:
	Game(int screenWidth, int screenHeight);
	Grid grid;
	Block GetRandomBlock();
	std::vector<Block> GetAllBlocks();
	void Draw();
	void HandleInput();
	void MoveBlockLeft();
	void MoveBlockRight();
	void MoveBlockDown();
private:
	std::vector<Block> blocks;
	Block currentBlock;
	Block nextBlock;
	bool gameOver;
	bool IsBlockOutside();
	bool BlockFits();
	void RotateBlock();
	void SetLock();
	void Reset();
	int screenWidth;
	int screenHeight;
	int	gameGridWidth;
	int	gameGridHeight;
	int	gameGridStartPosX;
	int gameGridStartPosY;
	int cellSize;
	int cellMargin;
	int gameAreaBorderLineThickness;
};