/* Write a program that reads characters from the standard input to end-of-file.
For each character, have the program report whether it is a letter. If it is a
letter, also report its numerical location in the alphabet. For example, c and C
would both be letter 3. Incorporate a function that takes a character as an
argument and returns the numerical location if the character is a letter and
that returns –1 otherwise. */

#include <ctype.h>

int charPositionInAlphabet(char ch) {
	// Convert character to lowercase using tolower
	ch = tolower(ch);

	// Check if the character is a lowercase letter
	if (ch >= 'a' && ch <= 'z') {
		// Subtract ASCII value of 'a' and add 1 to get the position in the
		// alphabet
		return ch - 'a' + 1;
	}

	// If the character is not a letter, return an error code (e.g., 0)
	return -1;
}
