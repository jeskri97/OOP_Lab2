
#include <iostream>
#include <string>
#include <vector>
#include <time.h>
#include <algorithm>

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

void reverseChar(char* str) {
	std::reverse(str, str + strlen(str));
}
bool isPalindrome(const char* word, int length) {
	char word2[200];
	char currentLetter;
	int index = 0;
	while (word[index]) {
		currentLetter = word[index];
		word2[index] = toupper(currentLetter);
		index++;
	}

	bool isPalinBool = true;
	for (int i = 0; i < length / 2; i++) {
		if (word2[i] != word2[length - i - 1])
			isPalinBool = false;
	}
	return isPalinBool;
}
void palindromeChecker() {
	char word[200];

	printf("\nWrite a word.\nInput: ");
	std::cin >> word;

	bool boo = isPalindrome(word, strlen(word));
	if (boo)
		printf("Input is a Palindrome\n");
	else
		printf("Input is not a Palindrome\n");
}

void array2D() {
	// Set the starting seed for generating random numbers.
	srand(time(NULL));
	int row, colu;
	std::vector<std::vector<int>> intVector;

	// Receive input from user.
	printf("\nNumber of rows: ");
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

void swapSort(int& a, int& b, int& c, bool ascending) {
	if (ascending) {
		// smallest to biggest
		// 1 2 3
		if (a > c) {
			int temp = a;
			a = c;
			c = temp;
		}
		if (b < a) {
			int temp = b;
			b = a;
			a = temp;
		}
		if (b > c) {
			int temp = b;
			b = c;
			c = temp;
		}
	}
	else {
		// Biggest to smallest
		// 3 2 1
		if (a < c) {
			int temp = a;
			a = c;
			c = temp;
		}
		if (b > a) {
			int temp = b;
			b = a;
			a = temp;
		}
		if (b < c) {
			int temp = b;
			b = c;
			c = temp;
		}
	}
}

int swapSort() {
	int num1, num2, num3;
	bool ascend;

	printf("(Write 0 to end)\nNumber 1: ");
	std::cin >> num1;
	if (num1 == 0) {
		printf("Bye Bye\n");
		return 0;
	}
	printf("Number 2: ");
	std::cin >> num2;
	printf("Number 3: ");
	std::cin >> num3;
	printf("Ascending or Descending (1/0): ");
	std::cin >> ascend;

	swapSort(num1, num2, num3, ascend);

	printf("\n%d %d %d\n", num1, num2, num3);
}

void shrinkArray(int arr[], int len) {
	int tempIndex = 0;
	for (int i = 0; i < len; i += 2) {
		arr[tempIndex] = arr[i] + arr[i + 1];
		tempIndex++;
	}
}
void shrink() {
	int arr[200] = { 5, 5, 11, 9, 8, 4, 2, 4, 1 };
	printf("\nArray before shrink:\n");
	for (int i = 0; i < (sizeof(arr) / sizeof(*arr)); i++) {
		printf("%d ", arr[i]);
	}
	shrinkArray(arr, 200);
	printf("\nArray after shrink:\n");
	for (int i = 0; i < (sizeof(arr) / sizeof(*arr)); i++) {
		printf("%d ", arr[i]);
	}
	printf("\nDONE\n");
}

class VecDatabase {
private:
	std::vector<std::string> data;

	// All letters to lowercase.
	std::string toLower(std::string input) {
		// convert string to lower case
		int toLower(int c);
		std::for_each(input.begin(), input.end(), [](char& c) {
			c = ::tolower(c);
			});
		return input;
	}

	std::vector<std::string> findWord(std::string input) {
		std::vector<std::string> output;
		int wordNumber = 1;
		for (int i = 0; i < data.size(); i++) {
			size_t found = data[i].find(input);
			if (found != std::string::npos) {
				printf("Found word %d: %s\n", wordNumber, data[i].c_str());
				output.push_back(data[i]);
				wordNumber++;
			}
		}
		printf("\n");
		return output;
	}
public:
	// Constructor
	VecDatabase() {}
	// Destructor
	~VecDatabase() {}

	void setWord(std::string word) {
		word = this->toLower(word);
		data.push_back(word);
	}

	// Removes all names from the vector, after confirming.
	void initialiseDatabase() {
		bool input;
		printf("\nAre you sure you want to delete all data?\n1: Yes\n0: No\nInput: ");
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (input)
		{
		case 0:
			printf("Aborting operation\n");
			break;
		case 1:
			printf("Deleting data\n");
			data.clear();
			printf("Done\n");
			break;
		default:
			printf("Invalid value\n");
			break;
		}
	}

	// Incert a new value to the vector.
	void insert() {
		std::string word;
		printf("Write a word: ");
		std::getline(std::cin, word);
		word = this->toLower(word);
		data.push_back(word);
	}

	// Print all values containing the incerted string.
	void search() {
		std::string word;
		printf("Search: ");
		std::getline(std::cin, word);
		word = this->toLower(word);
		this->findWord(word);
	}

	// Deletes the incerted value from the vector if found.
	void deleteVal() {
		std::string word;
		int input;
		printf("Search word to delete: ");
		std::getline(std::cin, word);
		word = this->toLower(word);

		std::vector<std::string> targets = this->findWord(word);
		printf("Write the number of the word to delete: ");
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		for (int i = 0; i < data.size(); i++) {
			if (data[i] == targets[input - 1])
				data.erase(data.begin() + i);
		}
	}

	// Prints the contents of the vector.
	void print() {
		for (int i = 0; i < data.size(); i++) {
			printf("\n%s", data[i].c_str());
		}
		printf("\n");
	}
};
VecDatabase vecDatabaseMenuLoop(VecDatabase database) {
	char input;
	bool programOn = true;
	while (programOn) {
		printf("\nVector Database Menu\n\n0: QUIT\n1: Initialise Database\n2: Insert\n3: Search\n4: Delete\n5: Print\n\nInput: ");
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		switch (input)
		{
		case '1':
			database.initialiseDatabase();
			break;
		case '2':
			database.insert();
			break;
		case '3':
			database.search();
			break;
		case '4':
			database.deleteVal();
			break;
		case '5':
			database.print();
			break;
		case '0':
			printf("\nGood Bye\n");
			programOn = false;
			break;
		default:
			printf("Invalid value\n");
			break;
		}
	}
	return database;
}