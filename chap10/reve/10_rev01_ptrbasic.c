// What will this program print?
#include <stdio.h>

int main(void) {
	int ref[] = {8, 4, 0, 2};
	int *ptr;
	int index;
	// the pointer ptf is the same as ref
	for (index = 0, ptr = ref; index < 4; index++, ptr++)
		printf("%d %d\n", ref[index], *ptr);
	return 0;
}

// This would print:
// ref[0] = 8, *ptr = 8
// ref[1] = 4, *ptr = 4
// ref[2] = 0, *ptr = 0
// ref[3] = 2, *ptr = 2
