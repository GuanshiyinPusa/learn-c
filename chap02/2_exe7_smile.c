/* smile.c -- a program that uses function to print smile! */
#include <stdio.h>

// function declaration
void smile(void);

int main(void) {
	// print Smile!Smile!Smile!
	smile();
	smile();
	smile();
	printf("\n");

	// print Smile!Smile!
	smile();
	smile();
	printf("\n");

	// print Smile!
	smile();
	printf("\n");

	return 0;
}

void smile(void) { printf("Smile!"); }

/*
 * Output:
 * Smile!Smile!Smile!
 * Smile!Smile!
 * Smile!
 */
