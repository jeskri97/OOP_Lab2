
#include <iostream>

#include "lab2lib.h"

int main() {
	char input;
	bool programOn = true;
	VecDatabase database;
	while (programOn) {
		printf("\nChoose a task (0 to end)\nTask 1 (SortCheck)\nTask 2 (Palindrome)\nTask 3 (2D array)");
		printf("\nTask 4 (Swap sort)\nTask 5 (Shrink)\nTask 6 (Vector database)\n");
		printf("\nInput: ");
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (input)
		{
		case '1':
			sortCheck();
			break;
		case '2':
			palindromeChecker();
			break;
		case '3':
			array2D();
			break;
		case '4':
			swapSort();
			break;
		case '5':
			shrink();
			break;
		case '6':
			database = vecDatabaseMenuLoop(database);
			break;
		case '0':
			printf("Good Bye!\n");
			programOn = false;
			break;
		default:
			break;
		}
	}
}
