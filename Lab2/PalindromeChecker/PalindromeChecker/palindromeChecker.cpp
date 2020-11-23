
#include <iostream>

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

int main(void) {
	char word[200];

	printf("Input: ");
	std::cin >> word;

	bool boo = isPalindrome(word, strlen(word));
	if (boo)
		printf("Input is a Palindrome\n");
	else
		printf("Input is not a Palindrome\n");
}