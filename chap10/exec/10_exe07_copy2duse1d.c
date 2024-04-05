// Write a program that initializes a two-dimensional array-of-double and uses
// one of the copy functions from exercise 2 to copy it to a second
// two-dimensional array. (Because a two-dimensional array is an array of
// arrays, a one-dimensional copy function can be used with each subarray.)

#include <stdio.h>
#define ROWS 3
#define COLS 4

void copy2d(double target[][COLS], const double source[][COLS], int rows);
void copy_1darr(double *target1, const double *source, int n);

int main(void) {
	double junk[ROWS][COLS] = {{2, 4, 6, 8}, {3, 5, 7, 9}, {12, 10, 8, 6}};
	double target[ROWS][COLS];
	copy2d(target, junk, ROWS);
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++)
			printf("%.0f\t", junk[i][j]);
		printf("\n");
	}
}

void copy2d(double target[][COLS], const double source[][COLS], int rows) {
	for (int i = 0; i < rows; i++)
		copy_1darr(target[i], source[i], COLS);
}

void copy_1darr(double *target1, const double *source, int n) {
	for (int i = 0; i < n; i++)
		target1[i] = source[i];
}
