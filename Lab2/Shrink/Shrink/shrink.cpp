
#include <iostream>

void shrinkArray(int arr[], int len) {
	int tempIndex = 0;
	for (int i = 0; i < len; i += 2) {
		arr[tempIndex] = arr[i] + arr[i + 1];
		tempIndex++;
	}
}

int main(void) {
	int arr[200] = { 5, 5, 11, 9, 8, 4, 2, 4, 1 };
	shrinkArray(arr, 200);
	printf("\narr:\n");
	for (int i = 0; i < (sizeof(arr) / sizeof(*arr)); i++) {
		printf("%d ", arr[i]);
	}
	printf("\nDONE\n");
}