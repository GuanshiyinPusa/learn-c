// Write a program that prompts the user to enter three sets of five double
// numbers each. (You may assume the user responds correctly and doesn’t enter
// non-numeric data.) The program should accomplish all of the following: a.
// Store the information in a 3×5 array. b. Compute the average of each set of
// five values. c. Compute the average of all the values. d. Determine the
// largest value of the 15 values. e. Report the results. Each major task should
// be handled by a separate function using the traditional C approach to
// handling arrays. Accomplish task “b” by using a function that computes and
// returns the average of a one-dimensional array; use a loop to call this
// function three times. The other tasks should take the entire array as an
// argument, and the functions performing tasks “c” and “d” should return the
// answer to the calling program.

#include <stdio.h>
#define ROWS 3
#define COLS 5

void fill_array_vla(int rows, int cols, double array[rows][cols]);
void print_array_vla(int rows, int cols, double array[rows][cols]);
double average_linearray_vla(int cols, double array[cols]);
double average_allarray_vla(int rows, int cols, double array[rows][cols]);
double largest_vla(int rows, int cols, double array[rows][cols]);

int main(void) {
	double array[ROWS][COLS];
	double average_line, average_all, largest_num;
	fill_array_vla(ROWS, COLS, array);
	print_array_vla(ROWS, COLS, array);
	for (int i = 0; i < ROWS; i++) {
		average_line = average_linearray_vla(COLS, array[i]);
		printf("Line %d's average is %.2f\n", i, average_line);
	}
	average_all = average_allarray_vla(ROWS, COLS, array);
	printf("The average of all is %.2f\n", average_all);
	largest_num = largest_vla(ROWS, COLS, array);
	printf("The largest of all is %.2f\n", largest_num);
}

void print_array_vla(int rows, int cols, double array[rows][cols]) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%.0lf\t", array[i][j]);
		}
		printf("\n");
	}
}

void fill_array_vla(int rows, int cols, double array[rows][cols]) {
	printf("Please enter %d x %d values for the array:\n", rows, cols);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("Enter value for element at position (%d, %d): ", i + 1,
				   j + 1);
			scanf("%lf", &array[i][j]);
		}
	}
}

double average_linearray_vla(int cols, double array[cols]) {
	double set_sum = 0;
	for (int j = 0; j < cols; j++) {
		set_sum += array[j];
	}
	return set_sum / cols;
}

double average_allarray_vla(int rows, int cols, double array[rows][cols]) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			sum += array[i][j];
		}
	}
	return sum / (rows * cols);
}

double largest_vla(int rows, int cols, double array[rows][cols]) {
	double largest = array[0][0];
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (array[i][j] > largest) {
				largest = array[i][j];
			}
		}
	}
	return largest;
}
