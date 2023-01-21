#include "MainManager.h"

void MainManager::Start() {

	board.InitializeBoard();
	GenerateMines(&board, mines);

}

void MainManager::Game() {

	int userX = 0;
	int userY = 0;

	bool isPlaying = true;

	while (isPlaying) {

		board.PrintBoard();

		if (!DemandInput(userX, userY)) {
			system("pause");
			system("cls");
			continue;
		};

		if (board.CheckIfHasMine(userX, userY)) {
			system("cls");
			isPlaying = false;
			//board.GameOverPrintBoard();
			std::cout << "Cagaste" << std::endl;
		}

		SelectCell(board.board[userY][userX]);

		system("pause");
		system("cls");
	}

}

void MainManager::GenerateMines(Board* b, std::vector<Cell*> mines) {

	for (int i = 0; i < TOTAL_MINES; i++) {

		bool valid = true;

		do {

			valid = true;

			int positionX = GenerateRandom(0, MAP_SIZE - 1);
			int positionY = GenerateRandom(0, MAP_SIZE - 1);

			for (int j = 0; j < mines.size() && valid; j++) {
				valid &= !((mines[j]->position.x == positionX) && (mines[j]->position.y == positionY));
			}

			if (valid) {
				b->board[positionY][positionX]->icon = 'M';
				b->board[positionY][positionX]->hasMine = true;
				mines.push_back(b->board[positionY][positionX]);
			}

		} while (!valid);
	}
}

bool MainManager::DemandInput(int& x, int& y) {

	
	
	std::cout << "\n\n";

	std::cout << "Enter the position you want to check" << std::endl;
	std::cout << "Enter X: ";
	std::cin >> x;

	if (CheckInput(x)) {
		std::cout << "Invalid X coordinate" << std::endl;
		return false;
	}

	std::cout << "Enter Y: ";
	std::cin >> y;

	if (CheckInput(y)) {
		std::cout << "Invalid Y coordinate" << std::endl;
		return false;
	}

	if (board.board[y][x]->isSelected) {
		std::cout << "Coordinate already selected... Try again!" << std::endl;
		return false;
	}

	return true;
}

void MainManager::SelectCell(Cell* cell) {

	board.CheckBorderCell(cell);

}