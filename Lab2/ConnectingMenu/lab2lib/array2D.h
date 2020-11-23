#pragma once

#include <iostream>
#include <vector>
#include <time.h>

void array2D() {
	// Set the starting seed for generating random numbers.
	srand(time(NULL));
	int row, colu;
	std::vector<std::vector<int>> intVector;

	// Receive input from user.
	printf("Number of rows: ");
	std::cin >> row;
	printf("Number of colums: ");
	std::cin >> colu;

	for (int currentRow = 0; currentRow < row; currentRow++) {
		std::vector<int> vec;
		int sum = 0;
		for (int currentColu = 0; currentColu < colu; currentColu++) {
			// Get a random number from 0 to 9.
			// Incert that number to the vector.
			vec.push_back(rand() % 10);
			sum += vec[currentColu];
		}
		// Add the sum of the row to the end of the vector.
		vec.push_back(sum);
		// Add the vector to the intVector.
		intVector.push_back(vec);
	}

	std::vector<int> sumVec;
	for (int currentColu = 0; currentColu < colu + 1; currentColu++) {
		int sum = 0;
		for (int currentRow = 0; currentRow < row; currentRow++) {
			sum += intVector[currentRow][currentColu];
		}
		// Ternary operator, if last column add double value.
		sumVec.push_back(sum * ((currentColu == colu) ? 2 : 1));
	}
	intVector.push_back(sumVec);

	for (int i = 0; i < intVector.size(); i++) {
		for (int j = 0; j < intVector.at(i).size(); j++) {
			printf("%d\t", intVector[i][j]);
		}
		printf("\n");
	}
}
