// postage.c -- first-class postage rates
#include <stdio.h>
int main(void) {
	const int FIRST_OZ = 46; // 2013 rate
	const int NEXT_OZ = 20;	 // 2013 rate

	int ounces, cost;

	printf(" ounces cost\n");
	for (ounces = 1, cost = FIRST_OZ; ounces <= 16; ounces++, cost += NEXT_OZ)
		printf("%5d $%4.2f\n", ounces, cost / 100.0);

	return 0;
}

// Output:
//  ounces cost
//  1 $0.46
//  2 $0.66
//  3 $0.86
//  4 $1.06
//  5 $1.26
//  6 $1.46
//  7 $1.66
//  8 $1.86
//  9 $2.06
// 10 $2.26
// 11 $2.46
// 12 $2.66
// 13 $2.86
// 14 $3.06
// 15 $3.26
// 16 $3.46
