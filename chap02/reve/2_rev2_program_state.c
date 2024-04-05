/* program_state.c -- What is the program state after line 7,8,9 */
#include <stdio.h>

int main(void) {
	int a, b;

	a = 5;
	b = 2; /* line 7 */
	b = a; /* line 8 */
	a = b; /* line 9 */
	printf("%d %d\n", b, a);
	return 0;
}

/*
 * Output:
 * 5 5
 */
