#include <stdio.h>

int main(void) {
	int x = 0;
	while (++x < 3)
		printf("%4d", x);
}

// Output:
//   1   2
