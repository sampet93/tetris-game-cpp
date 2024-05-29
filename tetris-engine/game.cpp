#include "game.h"
#include "utils.h"
#include <random>

Game::Game(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight) {
	gameGridWidth = 12;
	gameGridHeight = 18;
	cellSize = 30;
	gameAreaBorderLineThickness = 5;
	gameGridStartPosX = calculateCenterPos(gameGridWidth * cellSize, screenWidth);
	gameGridStartPosY = calculateCenterPos(gameGridHeight * cellSize, screenHeight);
	grid = Grid(gameGridWidth, gameGridHeight, cellSize, gameGridStartPosX, gameGridStartPosY);
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
}

Block Game::GetRandomBlock() {
	if (blocks.empty()) {
		blocks = GetAllBlocks();
	}

	int randomIndex = rand() % blocks.size();
	Block randomBlock = blocks[randomIndex];
	blocks.erase(blocks.begin() + randomIndex);

	return randomBlock;
}

std::vector<Block> Game::GetAllBlocks() {
	return { IBlock(), JBlock(), LBlock(), OBlock(), IBlock(), SBlock(), ZBlock(), TBlock() };
}

void Game::Draw() {
	grid.Draw();
	currentBlock.Draw();
}