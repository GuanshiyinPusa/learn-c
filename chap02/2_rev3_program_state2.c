/* program-state2.c -- What is the program state after line 7,8,9 */
#include <stdio.h>

int main(void) {
	int x, y;

	x = 10;
	y = 5;	   /* line 7 */
	y = x + y; /* line 8 */
	x = x * y; /* line 9 */
	printf("%d %d\n", x, y);
	return 0;
}

/*
 * Output:
 * 150 15
 */
