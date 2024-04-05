/*
Write a program that reads input until encountering #. Have the program print
each input character and its ASCII decimal code. Print eight character-code
pairs per line. Suggestion: Use a character count and the modulus operator (%)
to print a newline character for every eight cycles of the loop.
*/

#include <stdio.h>

int main(void) {
	char c;
	int count = 0;
	while ((c = getchar()) != '#') {
		printf("%c: %d\t", c, c);
		count++;
		if (count % 8 == 0)
			printf("\n");
	}
	return 0;
}

// Output:
// n h m #
// n: 110   : 32   h: 104   : 32   m: 109   : 32
