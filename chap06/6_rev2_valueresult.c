/* Given that value is an int, what output would the following loop produce? */
/* What problems would there be if value were double instead of int? */
#include <stdio.h>
int main(void) {
	int value;
	for (value = 36; value > 0; value /= 2)
		printf("%3d", value);
	printf("\n");
	double value1 = 0.0;
	for (value1 = 36; value1 > 0; value1 /= 2)
		printf("%3f", value1);
	printf("\n");
}

// Output:
// For int value:
// 36 18  9  4  2  1

// For double value:
// 36.00000018.0000009.0000004.0000002.0000001.000000
