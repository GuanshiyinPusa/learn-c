// Write a program that initializes a two-dimensional 3×5 array-of-double and
// uses a VLA- based function to copy it to a second two-dimensional array. Also
// provide a VLA-based function to display the contents of the two arrays. The
// two functions should be capable, in general, of processing arbitrary N×M
// arrays. (If you don’t have access to a VLA-capable compiler, use the
// traditional C approach of functions that can process an N×5 array).

#include <stdio.h>
void copy_arr(
	int rows, int cols, double target[rows][cols], double source[rows][cols]);
void print_arr(int rows, int cols, double arr[rows][cols]);

void print_arr(int rows, int cols, double arr[rows][cols]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++)
			printf("%.1f\t", arr[i][j]);
		printf("\n");
	}
}

void copy_arr(
	int rows, int cols, double target[rows][cols], double source[rows][cols]) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			target[i][j] = source[i][j];
}

int main(void) {
	double array[3][5] = {
		{1.1, 1.2, 1.3, 1.4, 1.5},
		{2.1, 2.2, 2.3, 2.4, 2.5},
		{3.1, 3.2, 3.3, 3.4, 3.5}};
	double target[3][5];
	print_arr(3, 5, array);
	copy_arr(3, 5, target, array);
	print_arr(3, 5, target);
}
