// rows2.c -- using dependent nested loops
#include <stdio.h>

int main(void) {
	const int ROWS = 6;
	const int CHARS = 6;
	int row;
	char ch;
	for (row = 0; row < ROWS; row++) {
		for (ch = ('A' + row); ch < ('A' + CHARS); ch++)
			printf("%c", ch);
		printf("\n");
	}
	return 0;
}

// Output:
// ABCDEF
// BCDEF
// CDEF
// DEF
// EF
// F

// Note:
// A ascii 65
// B ascii 66
// C ascii 67
// D ascii 68
// E ascii 69
// F ascii 70
