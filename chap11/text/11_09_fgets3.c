/* fgets3.c -- using fgets() */
#include <stdio.h>
#define STLEN 10

int main(void) {
	char words[STLEN];
	int i;

	puts("Enter strings (empty line to quit):");
	while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n') {
		i = 0;
		while (words[i] != '\n' && words[i] != '\0')
			i++;
		if (words[i] == '\n')
			words[i] = '\0';
		else // must have words[i] == '\0'
			while (getchar() != '\n')
				continue;
		puts(words);
	}
	puts("done");

	return 0;
}

// Output:
// Enter strings (empty line to quit):
// By the way, the gets() function
// By the way, the gets() function
// also returns a null pointer if it
// also returns a null pointer if it
// encounters end-of-file.
// encounters end-of-file.
// Done.
