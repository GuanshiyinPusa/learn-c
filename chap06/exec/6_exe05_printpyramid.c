/*
Have a program request the user to enter an uppercase letter. Use nested loops
to produce a pyramid pattern like this:
	A
   ABA
  ABCBA
 ABCDCBA
ABCDEDCBA
*/
// DONE: For loop 5 lines
// Done: For each line, print space, print A to currentchar, and then
// currentchar to A

#include <stdio.h>

int main(void) {
	const char startChar = 'A';
	const char endChar = 'E';

	for (char currentChar = startChar; currentChar <= endChar; currentChar++) {
		// Calculate the number of spaces needed for alignment
		int numSpaces = endChar - currentChar;

		// Print leading spaces for alignment
		for (int space = 0; space < numSpaces; space++) {
			printf(" ");
		}

		// Print ascending part of the pattern
		for (char charToPrint = startChar; charToPrint < currentChar;
			 charToPrint++) {
			printf("%c", charToPrint);
		}

		// Print the peak and descending part of the pattern
		for (char charToPrint = currentChar; charToPrint >= startChar;
			 charToPrint--) {
			printf("%c", charToPrint);
		}

		// Move to the next line
		printf("\n");
	}

	return 0;
}
