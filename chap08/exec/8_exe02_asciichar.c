/*
Write a program that reads input as a stream of characters until encountering
EOF. Have the program print each input character and its ASCII decimal value.
Note that characters preceding the space character in the ASCII sequence are
nonprinting characters. Treat them specially. If the nonprinting character is a
newline or tab, print \n or \t, respectively. Otherwise, use control-character
notation. For instance, ASCII 1 is Ctrl+A, which can be displayed as ^A. Note
that the ASCII value for A is the value for Ctrl+A plus 64. A similar relation
holds for the other nonprinting characters. Print 10 pairs per line, except
start a fresh line each time a newline character is encountered. (Note: The
operating system may have special interpretations for some control characters
and keep them from reaching the program.)
*/

#include <stdio.h>

int main() {
	char ch;
	int count = 0;

	while ((ch = getchar()) != EOF) {
		// Handle non-printing characters
		if (ch < ' ') {
			switch (ch) {
			case '\n':
				printf("\\n [%d] ", ch);
				count = 0; // Reset count for a new line
				break;
			case '\t':
				printf("\\t [%d] ", ch);
				break;
			default:
				// Control characters (e.g., ^A for Ctrl+A)
				printf("^%c [%d] ", ch + 64, ch);
			}
		} else {
			// Print printable characters
			printf("%c [%d] ", ch, ch);
		}

		count++;
		if (count >= 10) { // Check if 10 pairs have been printed
			printf("\n");
			count = 0; // Reset count for a new line
		}
	}

	return 0;
}
