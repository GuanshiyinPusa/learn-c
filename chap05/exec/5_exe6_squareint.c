/*
Now modify the program of Programming Exercise 5 so that it computes the sum of
the squares of the integers. (If you prefer, how much money you receive if you
get $1 the first day, $4 the second day, $9 the third day, and so on. This looks
like a much better deal!) C doesn’t have a squaring function, but you can use
the fact that the square of n is n * n.
*/
#include <stdio.h>

int main(void) {
	int num;
	printf("Enter an integer: ");
	scanf("%d", &num);
	int sum = 0;
	int count = 0;
	while (count++ < num)
		sum += count * count;
	printf("The sum of the squares of the first %d integers is %d\n", num, sum);
	return 0;
}

// Output:
// Enter an integer: 5
// The sum of the squares of the first 5 integers is 55
