/* print1.c -- display some properties of printf() */
#include <stdio.h>

int main(void) {
	int ten = 10;
	int two = 2;

	printf("Doing it right: ");
	printf("%d minus %d is %d\n", ten, 2, ten - two);
	printf("Doing it wrong: ");
	printf("%d minus %d is %d\n", ten); // forget two arguments

	return 0;
}

/*
 * Output:
 * Doing it right: 10 minus 2 is 8
 * Doing it wrong: 10 minus 2 is 8
 */
