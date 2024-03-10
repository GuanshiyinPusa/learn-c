/* first.c -- first c program */
#include <stdio.h>

int main(void) /* a simple program */
{
	int num; /* define a variable called num */
	num = 1; /* assign a value to num */

	printf("I am a simple "); /* use the printf() function */
	printf("computer. \n");
	printf("My favorite number is %d because it is first.\n", num);

	return 0;
}

/*
 * Output:
 * I am a simple computer.
 * My favorite number is 1 because it is first.
 */
