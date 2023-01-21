#pragma once

#include <vector>
#include "MapPosition.h"

struct Cell {

	MapPosition position;

	char icon;

	int minesBorder;

	bool isSelected;
	bool hasMine;

	std::vector<Cell*> neighboursWithoutMine;

	void InitializeCell(int x, int y);
};