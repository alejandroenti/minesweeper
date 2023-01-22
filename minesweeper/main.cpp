#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#include "MainManager.h"


int main() {

	srand(time(NULL));

	MainManager manager;

	manager.Game();

	return 0;
}