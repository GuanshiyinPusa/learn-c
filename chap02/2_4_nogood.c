/* nogood.c -- a program with errors */
#include <stdio.h>

int main(void) {
	// int n, int n2,int n3; /* Syntax error -- grammar erroe */
	int n, n2, n3;
	/*
	 * int n;
	 * int n2;
	 * int n3;
	 */

	/* This program has several errors */
	n = 5;
	n2 = n * n;
	n3 = n2 * n2;
	// printf("n = %d, n squared = %d, n cubed= %d\n",n,n2,n3) semantic error
	printf("n = %d, n squared = %d, n fourth power = %d\n", n, n2, n3);

	return 0;
}

/*
 * Output:
 * n = 5, n squared = 25, n fourth power = 625
 */
