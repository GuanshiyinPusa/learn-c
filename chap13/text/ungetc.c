#include <stdio.h>

int main() {
	int ch;

	// Read a character from stdin
	ch = getchar();

	// If the character is not EOF, push it back into the input stream
	if (ch != EOF) {
		printf("Read character: %c\n", ch);

		// Push the character back into the input stream
		ungetc(ch, stdin);
	}

	// Now, read the character again
	ch = getchar();

	// Print the character read after pushing it back
	printf("Read character again: %c\n", ch);

	return 0;
}
