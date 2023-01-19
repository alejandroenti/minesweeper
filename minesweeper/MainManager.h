#pragma once

#include <iostream>
#include <vector>

#include "Functioanlities.h"
#include "Board.h"
#include "Cell.h"

struct MainManager {

	Board board;
	std::vector<Cell*> mines;

	void Start();
	void Game();
	void GenerateMines(Board* b, std::vector<Cell*> mines);
	bool DemandInput(int x, int y);
};