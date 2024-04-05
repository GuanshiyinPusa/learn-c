//* two_fun.c -- a program using two functions in one file */
#include <stdio.h>

// function declaration
void butler(void); /* ANSI/ISO C function prototyping */

int main(void) {
	printf("I will summon the butler function.\n");
	butler();
	printf("Yes. Bring me some tea and writeable DVDs.\n");

	return 0;
}

void butler(void) /* start of function definition */
{
	printf("You rang, Sir?\n");
}

/*
 * Output:
 * I will summon the butler function.
 * You rang, Sir?
 * Yes. Bring me some tea and writeable DVDs.
 */
