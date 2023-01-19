#include "Board.h"

void Board::InitializeBoard() {

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			board[i][j] = new Cell;
			board[i][j]->InitializeCell(j, i);
		}
	}

}

void Board::PrintBoard() {

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			std::cout << " +-----+";
		}
		std::cout << std::endl;

		for (int j = 0; j < MAP_SIZE; j++) {
			std::cout << " |     |";
		}
		std::cout << "\n";

		for (int j = 0; j < MAP_SIZE; j++) {
			std::cout << " |  " << board[i][j]->icon << "  |";
		}
		std::cout << std::endl;

		for (int j = 0; j < MAP_SIZE; j++) {
			std::cout << " |     |";
		}
		std::cout << "\n";

		for (int j = 0; j < MAP_SIZE; j++) {
			std::cout << " +-----+";
		}
		std::cout << "\n";
	}

}

bool Board::CheckIfHasMine(int x, int y) {

	return board[y][x]->hasMine;

}

void Board::CheckBorderCell(Cell* cell) {

	//CHeckRightBorderCell()
	//CHeckLeftBorderCell()
	//CHeckTopBorderCell()
	//CHeckRBottomBorderCell()
	
	if (cell->position.x == 0) {

		if (cell->position.y == 0) {
			
			(CheckIfHasMine(cell->position.x + 1, cell->position.y)) ? cell->minesBorder++ : 0;
			(CheckIfHasMine(cell->position.x + 1, cell->position.y + 1)) ? cell->minesBorder++ : 0;
			(CheckIfHasMine(cell->position.x, cell->position.y + 1)) ? cell->minesBorder++ : 0;
			
			return;
		}

		if (cell->position.y == 9) {
			(CheckIfHasMine(cell->position.x + 1, cell->position.y)) ? cell->minesBorder++ : 0;
			(CheckIfHasMine(cell->position.x + 1, cell->position.y - 1)) ? cell->minesBorder++ : 0;
			(CheckIfHasMine(cell->position.x, cell->position.y - 1)) ? cell->minesBorder++ : 0;
			
			return;
		}

		(CheckIfHasMine(cell->position.x, cell->position.y + 1)) ? cell->minesBorder++ : 0;
		(CheckIfHasMine(cell->position.x + 1, cell->position.y + 1)) ? cell->minesBorder++ : 0;
		(CheckIfHasMine(cell->position.x + 1, cell->position.y)) ? cell->minesBorder++ : 0;
		(CheckIfHasMine(cell->position.x + 1, cell->position.y - 1)) ? cell->minesBorder++ : 0;
		(CheckIfHasMine(cell->position.x, cell->position.y - 1)) ? cell->minesBorder++ : 0;

		return;
	}

	

}