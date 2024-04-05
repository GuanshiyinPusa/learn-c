
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
// fill_array
void fill_array(double (*array)[COLS], int rows);
// print_array
void print_array(double (*array)[COLS], int rows);
// average_linearray
double average_linearray(double *array, int cols);
// average_allarray
double average_allarray(double (*array)[COLS], int rows);
// largest
double largest(double (*array)[COLS], int rows);

int main(void) {
	double array[ROWS][COLS];
	double average_line, average_all, largest_num;
	fill_array(array, ROWS);
	print_array(array, ROWS);
	for (int i = 0; i < ROWS; i++) {
		average_line = average_linearray(*array + i, COLS);
		printf("Line %d's average is %.2f\n", i, average_line);
	}
	average_all = average_allarray(array, ROWS);
	printf("The average of all is %.2f\n", average_all);
	largest_num = largest(array, ROWS);
	printf("The largest of all is %.2f\n", largest_num);
}

void print_array(double (*array)[COLS], int rows) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("%.0lf\t", *(*(array + i) + j));
		}
		printf("\n");
	}
}

void fill_array(double (*array)[COLS], int rows) {
	printf("Please enter %d x %d values for the array:\n", rows, COLS);
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			printf("Enter value for element at position (%d, %d): ", i + 1,
				   j + 1);
			scanf("%lf", (*(array + i) + j));
		}
	}
}

double average_linearray(double *array, int cols) {
	double set_sum = 0;
	for (int j = 0; j < cols; j++)
		set_sum += *(array + j);
	return set_sum / cols;
}

double average_allarray(double (*array)[COLS], int rows) {
	double sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			sum += *(*(array + i) + j);
		}
	}
	return sum / (rows * COLS);
}

double largest(double (*array)[COLS], int rows) {
	double largest = **array;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < COLS; j++) {
			if (*(*(array + i) + j) > largest) {
				largest = *(*(array + i) + j);
			}
		}
	}
	return largest;
}
