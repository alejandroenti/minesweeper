#include "MainManager.h"

void MainManager::StartGame() {

	board.InitializeBoard();
	GenerateMines(&board, mines);
	cellsSelected = 0;

}

void MainManager::Game() {

	currentScene = START;

	bool isPlaying = true;
	int userX = 0;
	int userY = 0;

	while (isPlaying) {

		switch (currentScene) {
		case START:
			color("yellow");
			std::cout << " -------------------- M I N E S W E E P E R--------------------\n" << std::endl;
			color("");
			std::cout << " Welcome to my incredible MineSweeper Game. Here you will face \n";
			std::cout << " a 10x10 matrix where 10 mines are hidden all over the board.\n" << std::endl;
			std::cout << " Will you be able to avoid all the mines or will they find you" << std::endl;
			std::cout << " first?\n\n" << std::endl;
			currentScene = BOARD;
			StartGame();
			system("pause");
			system("cls");
			break;

		case BOARD:

			board.PrintBoard();

			if (!DemandInput(userX, userY)) {
				system("pause");
				system("cls");
				continue;
			};

			if (board.CheckIfHasMine(userX, userY)) {
				currentScene = GAMEOVER;
			}

			SelectCell(board.board[userY][userX]);

			if (cellsSelected == 90) {
				currentScene = GAMEOVER;
				
			}

			system("pause");
			system("cls");
			

		break;

		case GAMEOVER:

			char playAgain;

			color("yellow");
			std::cout << " ------------------- M I N E S W E E P E R --------------------\n" << std::endl;
			color("");

			if (cellsSelected == 90) {
				color("green");
				std::cout << " Congratulations, you win!! :)\n\n";
				color("");
			}
			else {
				color("red");
				std::cout << " Oh no! You felt the pressure :(\n\n";
				color("");
			}

			std::cout << " This is the complete board:\n\n";
			board.PrintAllBoard();

			std::cout << "\n Would you like to play another game? [Y/n] ";
			std::cin >> playAgain;

			if (playAgain == 'y' || playAgain == 'Y') {
				system("cls");
				currentScene = START;
				continue;
			}

			isPlaying = false;
			system("cls");
			std::cout << " See you next time!" << std::endl;
			
			break;
		}
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
				b->board[positionY][positionX]->hasMine = true;
				mines.push_back(b->board[positionY][positionX]);
			}

		} while (!valid);
	}
}

bool MainManager::DemandInput(int& x, int& y) {
	
	std::cout << "\n\n";

	std::cout << " Enter the position you want to check" << std::endl;
	std::cout << " Enter X: ";
	std::cin >> x;

	if (CheckInput(x)) {
		color("red");
		std::cout << " [!] Invalid X coordinate" << std::endl;
		color("");
		return false;
	}

	std::cout << " Enter Y: ";
	std::cin >> y;

	if (CheckInput(y)) {
		color("red");
		std::cout << " [!] Invalid Y coordinate" << std::endl;
		color("");
		return false;
	}

	if (board.board[y][x]->isSelected) {
		color("red");
		std::cout << " [!] Coordinate already selected... Try again!" << std::endl;
		color("");
		return false;
	}

	color("green");
	std::cout << " [*] Coordinate selected (" << x << " , " << y << ")" << std::endl;
	color("");
	return true;
}

void MainManager::SelectCell(Cell* cell) {

	board.CheckBorderCell(cell, cellsSelected);

}