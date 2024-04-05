
#include <stdio.h>

int main(void) {
	int weight, height;
	scanf("%d %d", &weight, &height);

	// Simplified and corrected the logic
	if (weight < 100 && height > 64) {
		if (height >= 72) {
			printf("You are very tall for your weight.\n");
		} else {
			printf("You are tall for your weight.\n");
		}
	} else if (weight > 300 && height < 48) {
		printf("You are quite short for your weight.\n");
	}

	return 0;
}

// Output:
// 99 65
// You are tall for your weight.
// 99 72
// You are very tall for your weight.
// 301 47
// You are quite short for your weight.
