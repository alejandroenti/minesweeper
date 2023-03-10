#pragma once

#include <iostream>
#include <vector>

#include "Functionalities.h"
#include "Color.h"
#include "Cell.h"

struct Board {

	Cell* board[MAP_SIZE][MAP_SIZE];

	void InitializeBoard();
	void PrintBoard();
	void PrintAllBoard();
	void DiscoverBoard();
	bool CheckIfHasMine(int x, int y);
	void CheckBorderCell(Cell* cell, int& cellsSelected);
	void CheckBorderCellGameOver(Cell* cell);
	void CheckRigthBorderCell(Cell* cell);
	void CheckLeftBorderCell(Cell* cell);
	void CheckTopBorderCell(Cell* cell);
	void CheckBottomBorderCell(Cell* cell);
};
