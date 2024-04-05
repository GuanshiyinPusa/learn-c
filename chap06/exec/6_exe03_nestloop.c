/*
Use nested loops to produce the following pattern:
F
FE
FED
FEDC
FEDCB
FEDCBA
*/

#include <stdio.h>

int main(void) {
	// The outer loop runs 6 times for 6 lines.
	for (char lineEnd = 'F'; lineEnd >= 'A'; lineEnd--) {
		// The inner loop starts with 'F' and goes until it reaches the current
		// lineEnd character.
		for (char cap_f = 'F'; cap_f >= lineEnd; cap_f--) {
			printf("%c", cap_f);
		}
		printf("\n"); // Move to the next line after printing each line.
	}
	return 0;
}
