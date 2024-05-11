// ~ bitwise negation, flip 1 to 0 and 0 to 1
#include <stdio.h>

void print_binary(int num);

int main(void) {
	int val = 1000;
	int val2 = 10000;
	print_binary(val);
	// printf("%d\n", ~val);
	// print_binary(~val);
	print_binary(val2);
	// & and: two 1 is 1
	// sth cool: val &= 0377 is val = val & 0377
	/* printf("%d\n", (val) & (val2));
	print_binary((val) & (val2));
	print_binary(768); */
	// | or: one or two 1 is 1
	// sth cool: val |= 0377 is val = val | 0377
	/* printf("%d\n", (val) | (val2));
	print_binary((val) | (val2)); */
	// ^ exlusive or: only one 1 makes 1, two 1 is 0
	// sth cool: val ^=0377 is val = val ^ 0377
	printf("%d\n", (val) ^ (val2));
	print_binary((val) ^ (val2));
	return 0;
}

void print_binary(int num) {
	unsigned int mask =
		1 << (sizeof(int) * 8 - 1); // start with the most significant bit

	for (; mask; mask >>= 1) { // shift the mask right after each iteration
		printf(
			"%d",
			(num & mask) ? 1 : 0); // print 1 if the bit is set, 0 otherwise
	}
	printf("\n");
}