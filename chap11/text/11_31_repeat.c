/* repeat.c -- main() with arguments */
#include <stdio.h>

int main(int argc, char *argv[]) {
	int count;

	printf("The command line has %d arguments:\n", argc - 1);
	for (count = 1; count < argc; count++)
		printf("%d: %s\n", count, argv[count]);
	printf("\n");

	return 0;
}

// Compile and Output:
// [text]$ clang 11_31_repeat.c -o repeat
// [text]$ ./repeat Resistance is futile
// The command line has 3 arguments:
// 1: Resistance
// 2: is
// 3: futile
