#include <stdio.h>

int main(void) {
	int n, m;
	n = 30;
	while (++n <= 33)
		printf("%d|", n);
	// Output: 31|32|33|
	n = 30;
	do
		printf("%d|", n);
	// Output: 30|31|32|33|
	while (++n <= 33); // Nothing happens here
	printf("\n***\n"); // Output: ***
	for (n = 1; n * n < 200; n += 4)
		printf("%d\n", n);
	// Output:
	// 1
	// 5
	// 9
	// 13
	printf("\n***\n");						  // Output: ***
	for (n = 2, m = 6; n < m; n *= 2, m += 2) // n = 2, m = 6; n = 4, m = 8; n =
											  // 8, m = 10 n = 16, m 12;
		printf("%d %d\n", n, m);
	// Output:
	// 2 6
	// 4 8
	// 8 10
	printf("\n***\n"); // Output: ***
	for (n = 5; n > 0; n--) {
		for (m = 0; m <= n; m++)
			printf("="); // Output:
						 // ======
						 // =====
						 // ====
						 // ===
						 // ==
						 // =
		printf("\n");
	}
	return 0;
}

// Output:
// 31|32|33|30|31|32|33|
// ***
// 1
// 5
// 9
// 13
//
// ***
// 2 6
// 4 8
// 8 10
//
// ***
// ======
// =====
// ====
// ===
// ==
