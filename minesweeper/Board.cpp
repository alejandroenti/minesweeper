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