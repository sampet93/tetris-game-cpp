#include "game.h"
#include "utils.h"
#include <random>
#include <vector>

Game::Game(int screenWidth, int screenHeight) : screenWidth(screenWidth), screenHeight(screenHeight) {
	gameGridWidth = 12;
	gameGridHeight = 18;
	cellSize = 30;
	cellMargin = 3;
	gameAreaBorderLineThickness = 5;
	gameGridStartPosX = calculateCenterPos(gameGridWidth * cellSize, screenWidth);
	gameGridStartPosY = calculateCenterPos(gameGridHeight * cellSize, screenHeight);
	grid = Grid(gameGridWidth, gameGridHeight, cellSize, cellMargin, gameGridStartPosX, gameGridStartPosY);
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

	randomBlock.Initialize(cellSize, cellMargin, gameGridStartPosX, gameGridStartPosY, gameAreaBorderLineThickness);

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

void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();
	switch (keyPressed)
	{
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		break;
	case KEY_UP:
		RotateBlock();
		break;
	default:
		break;
	}
}

void Game::MoveBlockLeft() {
	currentBlock.Move(0, -1);

	if (IsBlockOutside()) {
		currentBlock.Move(0, 1);
	}
}

void Game::MoveBlockRight()
{
	currentBlock.Move(0, 1);

	if (IsBlockOutside()) {
		currentBlock.Move(0, -1);
	}
}

void Game::MoveBlockDown()
{
	currentBlock.Move(1, 0);

	if (IsBlockOutside()) {
		currentBlock.Move(-1, 0	);
	}
}

void Game::RotateBlock()
{
	currentBlock.Rotate();

	if (IsBlockOutside()) {
		currentBlock.UndoRotation();
	}
}

bool Game::IsBlockOutside()
{
    std::vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		if (grid.IsCellOutside(item.row, item.col)) {
			return true;
		}
	}
	return false;
}