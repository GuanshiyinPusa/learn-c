/*
Write a program that prints a table with each line giving an integer, its
square, and its cube. Ask the user to input the lower and upper limits for the
table. Use a for loop.
*/

#include <stdio.h>

int main(void) {
	int lower, upper;
	printf("What is lower?\n");
	scanf("%d", &lower);

	printf("What is upper?\n");
	scanf("%d", &upper);

	for (; lower <= upper; lower++)
		printf("%d\t%d\t%d\n", lower, lower * lower, lower * lower * lower);
	return 0;
}
