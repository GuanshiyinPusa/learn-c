/*
Redo exercise 4 using a switch.
*/
#include <stdio.h>

int main(void) {
	char c;
	int n_sub = 0;

	while ((c = getchar()) != '#') {
		switch (c) {
		case '.': // If the character is a dot
			printf("!");
			n_sub++;
			break;
		case '!': // If the character is an exclamation mark
			printf("!!");
			n_sub++;
			break;
		default: // For all other characters
			printf("%c", c);
			break;
		}
	}

	printf("\nNumber of substitutions: %d\n", n_sub);
	return 0;
}
