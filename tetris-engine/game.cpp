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
	gameOver = false;
	score = 0;
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
	return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), ZBlock(), TBlock() };
}

void Game::Draw() {
	grid.Draw();
	currentBlock.Draw();
}

int Game::GetScore()
{
	return score;
}

void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();

	if (gameOver && keyPressed != 0) {
		gameOver = false;
		Reset();
	}

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
	if (!gameOver) {
		currentBlock.Move(0, -1);

		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.Move(0, 1);
		}
	}
}

void Game::MoveBlockRight()
{
	if (!gameOver) {
		currentBlock.Move(0, 1);

		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.Move(0, -1);
		}
	}
}

void Game::MoveBlockDown()
{
	if (!gameOver) {
		currentBlock.Move(1, 0);

		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.Move(-1, 0);
			SetLock();
		}
	}
}

void Game::RotateBlock()
{
	if (!gameOver) {
		currentBlock.Rotate();

		if (IsBlockOutside() || BlockFits() == false) {
			currentBlock.UndoRotation();
		}
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

bool Game::BlockFits()
{
	std::vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		if (grid.IsCellEmpty(item.row, item.col) == false) {
			return false;
		}
	}
	return true;
}

void Game::SetLock() {
	std::vector<Position> tiles = currentBlock.GetCellPosition();
	for (Position item : tiles)
	{
		grid.grid[item.row][item.col] = currentBlock.id;
	}

	currentBlock = nextBlock;

	if (BlockFits() == false) {
		gameOver = true;
	}

	nextBlock = GetRandomBlock();

	grid.ClearFullRows();
}

void Game::Reset() {
	grid.Initialize();
	blocks = GetAllBlocks();
	currentBlock = GetRandomBlock();
	nextBlock = GetRandomBlock();
	score = 0;
}