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

	color("yellow");
	std::cout << " ------------------- M I N E S W E E P E R --------------------\n" << std::endl;
	color("");

	for (int i = 0; i < MAP_SIZE; i++) {
		if (i == 0) {
			std::cout << "      " << i << "  ";
		}
		else {
			std::cout << "   " << i << "  ";
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < MAP_SIZE; i++) {

		for (int j = 0; j < MAP_SIZE; j++) {
			if (j == 0) {
				std::cout << "    +---+";
			}
			else {
				std::cout << " +---+";
			}
		}
		std::cout << std::endl;

		std::cout << " " << i << " ";

		for (int j = 0; j < MAP_SIZE; j++) {
			std::cout << " | ";
			
			switch (board[i][j]->icon) {
				case '0':
					color("cyan");
					std::cout << board[i][j]->icon;
					color("");
					break;
				case '1':
					color("blue");
					std::cout << board[i][j]->icon;
					color("");
					break;
				case '2':
					color("green");
					std::cout << board[i][j]->icon;
					color("");
					break;
				case '3':
					color("yellow");
					std::cout << board[i][j]->icon;
					color("");
					break;
				case '4':
					color("magenta");
					std::cout << board[i][j]->icon;
					color("");
					break;
				case 'M':
					color("red");
					std::cout << board[i][j]->icon;
					color("");
					break;
				default:
					std::cout << board[i][j]->icon;
			}
				
			std::cout<< " |";
		}
		std::cout << std::endl;

		for (int j = 0; j < MAP_SIZE; j++) {
			if (j == 0) {
				std::cout << "    +---+";
			}
			else {
				std::cout << " +---+";
			}
		}
		std::cout << "\n";
	}

}

void Board::PrintAllBoard() {

	DiscoverBoard();

	for (int i = 0; i < MAP_SIZE; i++) {
		if (i == 0) {
			std::cout << "      " << i << "  ";
		}
		else {
			std::cout << "   " << i << "  ";
		}
	}
	std::cout << std::endl;

	for (int i = 0; i < MAP_SIZE; i++) {

		for (int j = 0; j < MAP_SIZE; j++) {
			if (j == 0) {
				std::cout << "    +---+";
			}
			else {
				std::cout << " +---+";
			}
		}
		std::cout << std::endl;

		std::cout << " " << i << " ";

		for (int j = 0; j < MAP_SIZE; j++) {
			std::cout << " | ";

			switch (board[i][j]->icon) {
			case '0':
				color("cyan");
				std::cout << board[i][j]->icon;
				color("");
				break;
			case '1':
				color("blue");
				std::cout << board[i][j]->icon;
				color("");
				break;
			case '2':
				color("green");
				std::cout << board[i][j]->icon;
				color("");
				break;
			case '3':
				color("yellow");
				std::cout << board[i][j]->icon;
				color("");
				break;
			case '4':
				color("magenta");
				std::cout << board[i][j]->icon;
				color("");
				break;
			case 'M':
				color("red");
				std::cout << board[i][j]->icon;
				color("");
				break;
			default:
				std::cout << board[i][j]->icon;
			}

			std::cout << " |";
		}
		std::cout << std::endl;

		for (int j = 0; j < MAP_SIZE; j++) {
			if (j == 0) {
				std::cout << "    +---+";
			}
			else {
				std::cout << " +---+";
			}
		}
		std::cout << "\n";
	}

}

void Board::DiscoverBoard() {

	for (int i = 0; i < MAP_SIZE; i++) {
		for (int j = 0; j < MAP_SIZE; j++) {
			if (board[i][j]->hasMine) {
				board[i][j]->icon = 'M';
				continue;
			}
			CheckBorderCellGameOver(board[i][j]);
		}
	}

}

bool Board::CheckIfHasMine(int x, int y) {

	return board[y][x]->hasMine;

}

void Board::CheckBorderCell(Cell* cell, int& cellsSelected) {

	if (cell->isSelected) {
		return;
	}

	CheckRigthBorderCell(cell);
	CheckLeftBorderCell(cell);
	CheckTopBorderCell(cell);
	CheckBottomBorderCell(cell);

	cell->isSelected = true;
	cellsSelected++;
	cell->icon = cell->minesBorder + '0';

	if (cell->minesBorder != 0) {
		return;
	}

	for (int i = 0; i < cell->neighboursWithoutMine.size(); i++) {
		CheckBorderCell(cell->neighboursWithoutMine[i], cellsSelected);
	}

}

void Board::CheckBorderCellGameOver(Cell* cell) {

	if (cell->isSelected) {
		return;
	}

	CheckRigthBorderCell(cell);
	CheckLeftBorderCell(cell);
	CheckTopBorderCell(cell);
	CheckBottomBorderCell(cell);

	cell->icon = cell->minesBorder + '0';

}

void Board::CheckRigthBorderCell(Cell* cell) {

	if (cell->position.x == 9) {
		return;
	}

	if (cell->position.y == 0) {
		for (int i = cell->position.y; i <= cell->position.y + 1; i++) {
			if (CheckIfHasMine(cell->position.x + 1, i)) {
				cell->minesBorder++;
				continue;
			}

			if (!board[i][cell->position.x + 1]->isSelected) {
				cell->neighboursWithoutMine.push_back(board[i][cell->position.x + 1]);
			}
			
		}
		return;
	}

	if (cell->position.y == 9) {
		for (int i = cell->position.y - 1; i <= cell->position.y; i++) {
			if (CheckIfHasMine(cell->position.x + 1, i)) {
				cell->minesBorder++;
				continue;
			}

			if (!board[i][cell->position.x + 1]->isSelected) {
				cell->neighboursWithoutMine.push_back(board[i][cell->position.x + 1]);
			}
		}
		return;
	}


	for (int i = cell->position.y - 1; i <= cell->position.y + 1; i++) {
		if (CheckIfHasMine(cell->position.x + 1, i)) {
			cell->minesBorder++;
			continue;
		}

		if (!board[i][cell->position.x + 1]->isSelected) {
			cell->neighboursWithoutMine.push_back(board[i][cell->position.x + 1]);
		}
	}
}

void Board::CheckLeftBorderCell(Cell* cell) {

	if (cell->position.x == 0) {
		return;
	}

	if (cell->position.y == 0) {
		for (int i = cell->position.y; i <= cell->position.y + 1; i++) {
			if (CheckIfHasMine(cell->position.x - 1, i)) {
				cell->minesBorder++;
				continue;
			}

			if (!board[i][cell->position.x - 1]->isSelected) {
				cell->neighboursWithoutMine.push_back(board[i][cell->position.x - 1]);
			}
		}
		return;
	}

	if (cell->position.y == 9) {
		for (int i = cell->position.y - 1; i <= cell->position.y; i++) {
			if (CheckIfHasMine(cell->position.x - 1, i)) {
				cell->minesBorder++;
				continue;
			}

			if (!board[i][cell->position.x - 1]->isSelected) {
				cell->neighboursWithoutMine.push_back(board[i][cell->position.x - 1]);
			}
		}
		return;
	}


	for (int i = cell->position.y - 1; i <= cell->position.y + 1; i++) {
		if (CheckIfHasMine(cell->position.x - 1, i)) {
			cell->minesBorder++;
			continue;
		}

		if (!board[i][cell->position.x - 1]->isSelected) {
			cell->neighboursWithoutMine.push_back(board[i][cell->position.x - 1]);
		}
	}
}

void Board::CheckTopBorderCell(Cell* cell) {

	if (cell->position.y == 0) {
		return;
	}
	
	if (CheckIfHasMine(cell->position.x, cell->position.y - 1)) {
		cell->minesBorder++;
		return;
	}

	if (!board[cell->position.y - 1][cell->position.x]->isSelected) {
		cell->neighboursWithoutMine.push_back(board[cell->position.y - 1][cell->position.x]);
	}

}

void Board::CheckBottomBorderCell(Cell* cell) {

	if (cell->position.y == 9) {
		return;
	}

	if (CheckIfHasMine(cell->position.x, cell->position.y + 1)) {
		cell->minesBorder++;
		return;
	}

	if (!board[cell->position.y + 1][cell->position.x]->isSelected) {
		cell->neighboursWithoutMine.push_back(board[cell->position.y + 1][cell->position.x]);
	}
}