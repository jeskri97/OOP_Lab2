#pragma once

#include <iostream>
#include <string>
#include <vector>

bool isSorted(int* arr, int count);
int* handleInput(std::string str);
void sortCheck();

void reverseChar(char* str);
bool isPalindrome(const char* word, int length);
void palindromeChecker();

void array2D();

void swapSort(int& a, int& b, int& c, bool ascending);

int swapSort();

void shrinkArray(int arr[], int len);
void shrink();

class VecDatabase {
private:
	std::vector<std::string> data;

	// All letters to lowercase.
	std::string toLower(std::string input);

	std::vector<std::string> findWord(std::string input);
public:
	// Constructor
	VecDatabase() {}
	// Destructor
	~VecDatabase() {}

	void setWord(std::string word);

	// Removes all names from the vector, after confirming.
	void initialiseDatabase();

	// Incert a new value to the vector.
	void insert();

	// Print all values containing the incerted string.
	void search();

	// Deletes the incerted value from the vector if found.
	void deleteVal();

	// Prints the contents of the vector.
	void print();
};
VecDatabase vecDatabaseMenuLoop(VecDatabase database);