/* What’s the difference among the following?
printf("Hello, %s\n", name);
fprintf(stdout, "Hello, %s\n", name);
fprintf(stderr, "Hello, %s\n", name); */

// Correct:
// The first is just a shorthand notation for the second; the third writes to
// the standard error. Normally, the standard error is directed to the same
// place as the standard output, but the standard error is not affected by
// standard output redirection.
#include <stdio.h>

int main(void) {
	char name[20] = "GuanshiyinPusa";
	printf("Hello, %s\n", name);
	// printf() is a library function that writes
	// formatted output to stdout
	fprintf(stdout, "Hello, %s\n", name);
	// fprintf() is a library function that
	// writes formatted output to a stream -- stdout.
	fprintf(stderr, "Hello, %s\n", name);
	// stderr is a file stream that writes
	// error messages to the console
}