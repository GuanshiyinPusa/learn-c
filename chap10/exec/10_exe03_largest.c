// Write a function that returns the largest value stored in an array-of-int.
// Test the function in a simple program.
#include <stdio.h>
#define SIZE 5
int find_largest(int *array);
int find_largest2(int *array, int n);

int main(void) {
	int array[SIZE] = {13, 3, 5, 4, 7};
	printf("%d\n", find_largest(array));
}

int find_largest(int *array) {
	int largest = array[0];
	int i = 1;
	while (array[i] != -1) {
		if (*(array + i) > largest) {
			largest = array[i];
		}
		i++;
	}
	return largest;
}

int find_largest2(int *array, int n) {
	int largest = array[0];
	for (int i = 1; i < n; i++) {
		if (*(array + i) > largest) {
			largest = array[i];
		}
	}
	return largest;
}
