#include "Cell.h"

void Cell::InitializeCell(int x, int y) {

	position.x = x;
	position.y = y;

	icon = 'X';

	isSelected = false;
	hasMine = false;

}