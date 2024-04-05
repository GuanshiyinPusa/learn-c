// What is the value of *ptr and of *(ptr + 2) in each case?
// a.
// int *ptr;
// int torf[2][2] = {12, 14, 16};
// ptr = torf[0];

// b.
// int *ptr;
// int fort[2][2] = {{12}, {14, 16}};
// ptr = fort[0];

#include <stdio.h>

int main(void) {
	int *ptr;
	int torf[2][2] = {12, 14, 16};				// {{12, 14},{16, 0}}
	printf("%d\t%d\n", torf[0][0], torf[0][1]); // ptr = {12, 14}
	ptr = torf[0];

	int *n_ptr;
	int fort[2][2] = {{12}, {14, 16}};			// {{12, 0}, {14, 16}}
	printf("%d\t%d\n", fort[0][0], fort[0][1]); // ptr = {12, 0}
	n_ptr = fort[0];

	return 0;
}
