#include <stdlib.h>
#include <time.h>

#include "MainManager.h"
#include "Board.h"


int main() {

	srand(time(NULL));

	MainManager manager;

	manager.Game();

	return 0;
}