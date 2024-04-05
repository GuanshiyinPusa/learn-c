// Write a function that returns the index of the largest value stored in an
// array-of-double. Test the function in a simple program.
#include <stdio.h>
int find_largest_index(double *array, int size);

int main(void) {
	printf("%d\n",
		   find_largest_index((double[]){2.4, 3.4, 5.7, 7.2, 0.1, 0.2}, 6));
}

int find_largest_index(double *array, int size) {
	if (size <= 0) {
		return 0;
	}
	int largest_index = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] > array[largest_index]) {
			largest_index = i;
		}
	}
	return largest_index;
}
