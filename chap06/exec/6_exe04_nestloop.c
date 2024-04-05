/*
Use nested loops to produce the following pattern:
A
BC
DEF
GHIJ
KLMNO
PQRSTU
*/

#include <stdio.h>

int main(void) {
	char currentChar = 'A'; // Start from 'A'

	// There are 6 lines in total
	for (int i = 1; i <= 6; i++) {
		// On line i, print i characters
		for (int j = 1; j <= i; j++) {
			printf("%c", currentChar);
			currentChar++; // Move to the next character
		}
		printf("\n"); // Move to the next line after printing each line
	}

	return 0;
}
