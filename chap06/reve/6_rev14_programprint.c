#include <stdio.h>

int main(void) {
	int k;
	for (k = 1, printf("%d: Hi!\n", k); printf("k = %d\n", k), k * k < 26;
		 k += 2, printf("Now k is %d\n", k))
		printf("k is %d in the loop\n", k);
	return 0;
}

// Output:
// 1: Hi!
// k = 1
// k is 1 in the loop
// Now k is 3
// k = 3
// k is 3 in the loop
// Now k is 5
// k = 5
// k is 5 in the loop
// Now k is 7
// k = 7
//
// Notes: for loop: for (initialization; condition; update) { body }
//       The initialization is executed once, then the condition is checked.
//       If the condition is true, the body is executed, then the update is
//       executed, then the condition is checked again. If the condition is
//       false, the loop is exited. The body is executed at least once if the
//       condition is true. The initialization, condition, and update can be
//       any valid C statement. The body can be any valid C statement or block.
//       The body can be empty, in which case the semicolon is required.
