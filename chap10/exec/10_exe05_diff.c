// Write a function that returns the difference between the largest and smallest
// elements of an array-of-double. Test the function in a simple program.

#include <stdio.h>
double diff_between_large_small(double *array, int size);

int main(void) {
	printf(
		"%f\n",
		diff_between_large_small((double[]){1.2, 2.3, 3.4, 5.6, 1.0}, 5));
}

double diff_between_large_small(double *array, int size) {
	if (size <= 0) {
		return 0;
	}
	double largest = array[0];
	double smallest = array[0];
	for (int i = 0; i < size; i++) {
		if (array[i] > largest) {
			largest = array[i];
		} else if (array[i] < smallest) {
			smallest = array[i];
		}
	}
	return largest - smallest;
}
