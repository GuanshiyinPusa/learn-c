// Write a program that declares a 3×5 array of int and initializes it to some
// values of your choice. Have the program print the values, double all the
// values, and then display the new values. Write a function to do the
// displaying and a second function to do the doubling. Have the functions take
// the array name and the number of rows as arguments.

#include <stdio.h>
#define ROWS 3
#define COLS 5
void print_array(int rows, int cols, int array[rows][cols]);
void double_array(int rows, int cols, int array[rows][cols]);

int main(void) {
	int junk[ROWS][COLS] = {
		{2, 4, 6, 8, 10}, {3, 5, 7, 9, 11}, {12, 10, 8, 6, 4}};
	print_array(ROWS, COLS, junk);
	printf("\n");
	double_array(ROWS, COLS, junk);
	print_array(ROWS, COLS, junk);
}

void print_array(int rows, int cols, int array[rows][cols]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d\t", array[i][j]);
		}
		printf("\n");
	}
}

void double_array(int rows, int cols, int array[rows][cols]) {
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			array[i][j] *= 2;
}
