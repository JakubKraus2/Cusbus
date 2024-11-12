#include "main.h"

int main(void) {
	int size = getArraySize();
	int* array = makeArray(size);
	printArray(array, size);
	free(array);
	return 0;
	
}

int getArraySize(void) {
	int size = 0;
	printf_s("Enter the size of the array: ");
	scanf_s("%d", &size);
	return size;
}

int* makeArray(int size) {
	int* array = new int[size];
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100;
	}
	return array;
}

void printArray(int* array, int size) {
	for (int i = 0; i < size; i++) {
		printf_s("%d ", array[i]);
	}
	printf_s("\n");
}