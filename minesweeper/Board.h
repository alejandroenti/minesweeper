#pragma once

#include <iostream>

#include "Functionalities.h"
#include "Cell.h"

struct Board {

	Cell* board[MAP_SIZE][MAP_SIZE];

	void InitializeBoard();
	void PrintBoard();

};