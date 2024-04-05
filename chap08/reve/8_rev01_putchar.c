/*
putchar(getchar()) is a valid expression; what does it do? Is getchar(putchar())
also valid?
*/

#include <stdio.h>

int main(void) {
	putchar(getchar());
	// Input: Hello? Output: H

	// getchar(putchar()); // getchar() does not take any arguments
}
