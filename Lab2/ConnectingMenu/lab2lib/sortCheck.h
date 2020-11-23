#pragma once

#include <iostream>
#include <string>

bool isSorted(int* arr, int count) {
	for (int i = 1; i <= count; i++) {
		//std::cout << "Element " << i-1 << " : " << arr[i-1] << std::endl;
		if (i == count || arr[i] <= 0)
			return true;
		else if (arr[i] < arr[i - 1])
			return false;
	}
}

int* handleInput(std::string str) {
	int index = 0;
	static int arr[200];

	std::string number = "";
	for (auto x : str)
	{
		if (x == ' ')
		{
			arr[index] = std::stoi(number);
			index++;
			//std::cout << number << std::endl;
			number = "";
		}
		else {
			number = number + x;
		}
	}
	return arr;
}

void sortCheck() {
	std::string input;
	printf("\nWrite a series of positiv numbers.\nMinimum value 1.\nPut a space between each number.\n\nInput: ");
	std::getline(std::cin, input);
	bool boo = isSorted(handleInput(input), 200);
	if (boo)
		printf("Is Sorted: true\n");
	else
		printf("Is Sorted: false\n");
}