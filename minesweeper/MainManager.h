#pragma once

#include <iostream>
#include <vector>

#include "Functionalities.h"
#include "Color.h"
#include "Board.h"
#include "Cell.h"

enum GameScene { START, BOARD, GAMEOVER };

struct MainManager {

	GameScene currentScene;
	Board board;
	std::vector<Cell*> mines;
	int cellsSelected;


	void Game();
	void StartGame();
	void GenerateMines(Board* b, std::vector<Cell*> mines);
	bool DemandInput(int& x, int& y);
	void SelectCell(Cell* cell);
};