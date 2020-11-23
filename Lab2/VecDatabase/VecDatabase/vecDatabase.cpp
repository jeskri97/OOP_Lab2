
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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

void menuLoop(VecDatabase database) {
	char input;
	bool programOn = true;
	while (programOn) {
		printf("\nMenu\n\n1: Initialise Database\n2: Insert\n3: Search\n4: Delete\n5: Print\n6: QUIT\n\nInput: ");
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
		case '6':
			printf("\nGood Bye\n");
			programOn = false;
			break;
		default:
			printf("Invalid value\n");
			break;
		}
	}
}

int main(void) {
	VecDatabase database;
	database.setWord("teemu");
	database.setWord("teppo");
	database.setWord("kalle");
	database.setWord("en kort mening");
	menuLoop(database);
}