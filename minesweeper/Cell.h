#pragma once

#include "MapPosition.h"

struct Cell {

	MapPosition position;

	char icon;

	bool isSelected;
	bool hasMine;

	void InitializeCell(int x, int y);
};