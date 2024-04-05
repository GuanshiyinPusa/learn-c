/*
Using if else statements, write a program that reads input up to #, replaces
each period with an exclamation mark, replaces each exclamation mark initially
present with two exclamation marks, and reports at the end the number of
substitutions it has made.
*/
#include <stdio.h>

int main(void) {
	char c;
	int n_sub = 0;
	while ((c = getchar()) != '#') {
		if (c == '.') {
			printf("!");
			n_sub++;
		} else if (c == '!') {
			printf("!!");
			n_sub++;
		} else {
			printf("%c", c);
		}
	}
	printf("\nnumber of substitutions: %d\n", n_sub);
	return 0;
}

// Output:
// Hello. World!#
// Hello! World!!
// number of substitutions: 2
