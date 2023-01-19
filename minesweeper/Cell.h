#pragma once

#include "MapPosition.h"

struct Cell {

	MapPosition position;

	char icon;

	int minesBorder;

	bool isSelected;
	bool hasMine;

	void InitializeCell(int x, int y);
};