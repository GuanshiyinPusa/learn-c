/*
Rewrite the program in Review Question 9 so that it exhibits the same behavior
but does not use a continue or a goto.
*/

#include <stdio.h>

int main(void) {
	char ch;
	while ((ch = getchar()) != '#') {
		if (ch != '\n') { // Replaces the first continue if ch is not newline
			printf("Step 1\n");
			if (ch != 'c') { // Replaces the second continue if ch is not 'c'
				if (ch == 'b') {
					break; // Breaks the loop if ch is 'b'
				} else {
					if (ch == 'h') {
						printf("Step 3\n");
					} else {
						// Only executes if ch is not 'h'
						printf("Step 2\n");
						printf("Step 3\n");
					}
				}
			}
		}
	}
	printf("Done\n");
	return 0;
}
