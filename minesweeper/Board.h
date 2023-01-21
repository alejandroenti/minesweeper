#pragma once

#include <iostream>
#include <vector>

#include "Functionalities.h"
#include "Cell.h"

struct Board {

	Cell* board[MAP_SIZE][MAP_SIZE];

	void InitializeBoard();
	void PrintBoard();
	bool CheckIfHasMine(int x, int y);
	void CheckBorderCell(Cell* cell);
	void CheckRigthBorderCell(Cell* cell);
	void CheckLeftBorderCell(Cell* cell);
	void CheckTopBorderCell(Cell* cell);
	void CheckBottomBorderCell(Cell* cell);
};
