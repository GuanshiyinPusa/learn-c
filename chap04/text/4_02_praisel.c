/* praisel.c -- uses an assortment of strings */
#include <stdio.h>
#define PRAISE "You are an extraordinary being."

int main(void) {
	char name[40];

	printf("What's your name? ");
	scanf("%s", name); // only read the first word, space will be treated as the
					   // end of the input
	printf("Hello, %s. %s\n", name, PRAISE);

	return 0;
}

/*
 * Output:
 * What's your name? John Doe
 * Hello, John. You are an extraordinary being.
 */
