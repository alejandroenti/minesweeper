#include "Functionalities.h"

int GenerateRandom(int min, int max) {

	return min + rand() % (max + 1 - min);

}


bool CheckInput(int num) {

	return num >= MAP_SIZE || num < 0;
	
}