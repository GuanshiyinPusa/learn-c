// pnt_add.c -- pointer addition
#include <stdio.h>
#define SIZE 4

int main(void) {
	short dates[SIZE];
	short *pti;
	short index;
	double bills[SIZE];
	double *ptf;

	pti = dates; // assign address of array to pointer
	ptf = bills;

	printf("%23s %15s\n", "short", "double");
	for (index = 0; index < SIZE; index++)
		printf("pointers + %d: %10p %10p\n", index, pti + index, ptf + index);
	return 0;
}

// see that short takes 2 bytes, and double takes 8
// Output:
//                   short          double
// pointers + 0: 0x7ffd0b5582b8 0x7ffd0b5582c0
// pointers + 1: 0x7ffd0b5582ba 0x7ffd0b5582c8
// pointers + 2: 0x7ffd0b5582bc 0x7ffd0b5582d0
// pointers + 3: 0x7ffd0b5582be 0x7ffd0b5582d8
