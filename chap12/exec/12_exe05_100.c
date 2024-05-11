// Write a program that generates a list of 100 random numbers in the range 1–10
// in sorted decreasing order. (You can adapt the sorting algorithm from Chapter
// 11, “Character Strings and String Functions,” to type int. In this case, just
// sort the numbers themselves.)
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 100

void generate_random_numbers(int array[], int size);
void sort_decreasing(int array[], int size);
void swap(int *a, int *b);

int main(void) {
	int numbers[SIZE];

	// Seed the random number generator
	srand(time(NULL));

	// Generate random numbers
	generate_random_numbers(numbers, SIZE);

	// Sort numbers in decreasing order
	sort_decreasing(numbers, SIZE);

	// Print the sorted numbers
	printf("Sorted numbers in decreasing order:\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", numbers[i]);
	}
	printf("\n");

	return 0;
}

// Function to generate random numbers in the range 1–10
void generate_random_numbers(int array[], int size) {
	for (int i = 0; i < size; i++) {
		array[i] =
			rand() % 10 + 1; // Generates a random number between 1 and 10
	}
}

// Function to sort numbers in decreasing order
void sort_decreasing(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] < array[j + 1]) {
				swap(&array[j], &array[j + 1]);
			}
		}
	}
}

// Function to swap two integers
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
