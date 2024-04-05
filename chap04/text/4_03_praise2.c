/* praise2.c */
// try %u or %lu specifiers if your implementation does not recognize %zd
#include <stdio.h>
#include <string.h> // provides prototype for strlen()
#define PRAISE "You are an extraordinary being."

int main(void) {
	char name[40];

	printf("What's your name? ");
	scanf("%s", name);
	printf("Hello, %s. %s\n", name, PRAISE);
	printf("Your name of %zd letters occupies %zd memory cells.\n",
		   strlen(name), sizeof name);
	printf("The phrase of praise has %zd letters ", strlen(PRAISE));
	printf("and occupies %zd memory cells.\n", sizeof PRAISE);

	return 0;
}

/*
 * Output:
 * What's your name? John
 * Hello, John. You are an extraordinary being.
 * Your name of 4 letters occupies 40 memory cells.
 * The phrase of praise has 27 letters and occupies 28 memory cells.
 */
