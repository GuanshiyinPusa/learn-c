/* skiptwo.c -- skips over first two integers of input */
#include <stdio.h>

int main(void) {
	int n;

	printf("Please enter three integers:\n");
	scanf("%*d %*d %d", &n);
	printf("The last integer was %d\n", n);

	return 0;
}

// Output:
// Please enter three integers:
// 1 2 3
// The last integer was 3
