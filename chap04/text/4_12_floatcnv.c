/* floatcnv.c -- mismatched floating-point conversions */
#include <stdio.h>

int main(void) {
	float n1 = 3.0;
	double n2 = 3.0;
	long n3 = 2000000000;
	long n4 = 1234567890;

	printf("%.1e %.1e %.1e %.1e\n", n1, n2, n3, n4);
	printf("%ld %ld\n", n3, n4);
	printf("%ld %ld %ld %ld\n", n1, n2, n3, n4);

	return 0;
}

// Output:
// 3.0e+00 3.0e+00 3.0e+00 5.6e-67
// 2000000000 1234567890
// 2000000000 1234567890 2000000000 100
