/* fgets2.c -- using fgets() and fputs() */
#include <stdio.h>
#define STLEN 10

int main(void) {
	char words[STLEN];

	puts("Enter strings (empty line to quit):");
	while ((fgets(words, STLEN, stdin) != NULL && words[0] != '\n'))
		fputs(words, stdout);
	puts("Done.");

	return 0;
}

// Enter strings (empty line to quit):
// By the way, the gets() function
// By the way, the gets() function
// also returns a null pointer if it
// also returns a null pointer if it
// encounters end-of-file.
// encounters end-of-file.
// Done.
