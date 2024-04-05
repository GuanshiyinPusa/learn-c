/*
Write a program that reads input until encountering the # character and then
reports the number of spaces read, the number of newline characters read, and
the number of all other characters read.
*/

#include <stdio.h>

int main(void) {
	char c;
	int n_space = 0;
	int n_newline = 0;
	int n_rest = 0;
	while ((c = getchar()) != '#') {
		if (c == ' ')
			n_space++;
		else if (c == '\n')
			n_newline++;
		else
			n_rest++;
	}
	printf("number of space: %d\n", n_space);
	printf("number of newline: %d\n", n_newline);
	printf("number of rest char: %d\n", n_rest);
	return 0;
}

// Output:
// read input#?
// number of space: 1
// number of newline: 0
// number of rest char: 9
