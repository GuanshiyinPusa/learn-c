// What is the value of **ptr and of **(ptr + 1) in each case?
// a.
// int (*ptr)[2];
// int torf[2][2] = {12, 14, 16};
// ptr = torf;

// b.
// int (*ptr)[2];
// int fort[2][2] = { {12}, {14,16} };
// ptr = fort;

#include <stdio.h>

int main(void) {
	int(*ptr)[2];				   // 2D array
	int torf[2][2] = {12, 14, 16}; // {{12, 14}, {16, 0}}
	// printf("%d\t%d\n", torf[0][0], torf[0][1]);
	ptr = torf; // ptr = torf = address of {12, 14}, **ptr = 12
				// ptr + 1 = address of {16, 0}, **(ptr + 1) = 16
	printf("%d\t%d\n", **ptr, **(ptr + 1)); // 12   16

	int(*n_ptr)[2];
	int fort[2][2] = {{12}, {14, 16}}; // {{12, 0}, {14, 16}}
	n_ptr = fort; // n_ptr = torf = address of {12, 0}, **n_ptr = 12
				  // n_ptr + 1 = address of {14, 16}, **(n_ptr + 1) = 14
	printf("%d\t%d\n", **n_ptr, **(n_ptr + 1)); // 12   14
	return 0;
}
