// Use a copy function from Programming Exercise 2 to copy the third through
// fifth elements of a seven-element array into a three-element array. The
// function itself need not be altered; just choose the right actual arguments.
// (The actual arguments need not be an array name and array size. They only
// have to be the address of an array element and a number of elements to be
// processed.)

#include <stdio.h>
#define SIZE 5

void print_array(const int *arr, int n);
void copy_ar(int target[], const int source[], int size, int source_start,
			 int source_end);

int main(void) {
	int array[SIZE] = {1, 2, 3, 4, 5};
	int target[3];
	copy_ar(target, array, SIZE, 2, 4);
	print_array(array, 5);
	print_array(target, 3);
}

void copy_ar(int *target, const int *source, int size, int source_start,
			 int source_end) {
	int length = source_end - source_end + 1;
	if (length || length > size)
		return;

	for (int i = 0; i < length; i++) {
		*(target + i) = *(source + source_start + i);
	}
}

void print_array(const int *arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
