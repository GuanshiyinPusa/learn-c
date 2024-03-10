#include <stdio.h>
int main(void) {
	int x = 100;
	while (x++ < 103)
		printf("%4d\n", x);
	printf("%4d\n", x);
}

// Output:
// 101
// 102
// 103
// 104
