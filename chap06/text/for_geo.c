/* for_geo.c */
#include <stdio.h>

int main(void) {
	double debt;
	for (debt = 100.0; debt < 150.0; debt = debt * 1.1)
		printf("Your debt is now $%.2f.\n", debt);
	return 0;
}

// Output:
// Your debt is now $100.00.
// Your debt is now $110.00.
// Your debt is now $121.00.
// Your debt is now $133.10.
// Your debt is now $146.41.
