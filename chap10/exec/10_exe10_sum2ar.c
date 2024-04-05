// Write a function that sets each element in an array to the sum of the
// corresponding elements in two other arrays. That is, if array 1 has the
// values 2, 4, 5, and 8 and array 2 has the values 1, 0, 4, and 6, the function
// assigns array 3 the values 3, 4, 9, and 14. The function should take three
// array names and an array size as arguments. Test the function in a simple
// program.

#include <stdio.h>
#define SIZE 4
void sum_arrays(int array1[], int array2[], int sum_array[], int size);
void print_arr(int array[], int size);

int main(void) {
	int array1[SIZE] = {2, 4, 5, 8};
	int array2[SIZE] = {1, 0, 4, 6};

	int sum[SIZE];
	sum_arrays(array1, array2, sum, SIZE);
	print_arr(sum, SIZE);
}

void print_arr(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d\t", array[i]);
	}
	printf("\n");
}

void sum_arrays(int array1[], int array2[], int sum_array[], int size) {
	for (int i = 0; i < size; i++) {
		sum_array[i] = array1[i] + array2[i];
	}
}
