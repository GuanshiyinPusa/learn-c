/* for_wild.c */
#include <stdio.h>

int main(void) {
	int x;
	int y = 55;
	for (x = 1; y <= 75; y = (++x * 5) + 50)
		printf("%10d %10d\n", x, y);
	return 0;
}

// Output:
//      1         55
//      2         60
//      3         65
//      4         70
//      5         75
