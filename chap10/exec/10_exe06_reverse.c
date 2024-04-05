// Write a function that reverses the contents of an array of double and test it
// in a simple program.

#include <stdio.h>
void reverse_array(double *array, int size);
#define SIZE 5

int main(void) {
	double result[SIZE] = {1.2, 3.4, 4.5, 5.6, 7.8};
	reverse_array(result, SIZE);
	for (int i = 0; i < SIZE; i++) {
		printf("%lf\t", result[i]);
	}
	printf("\n");
	return 0;
}

void reverse_array(double *array, int size) {
	double temp;
	for (int i = 0; i < size / 2; i++) {
		temp = array[i];
		array[i] = array[size - i - 1];
		array[size - i - 1] = temp;
	}
}
