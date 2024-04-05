#include <stdio.h>

int main(void) {
	int i = 1;
	float n;
	printf("Watch out! Here come a bunch of fractions!\n");
	while (i++ < 30)
		n = 1.0 / i;
	printf(" %f", n);
	printf("That's all, folks!\n");
	return 0;
}

// Output:
//  0.033333That's all, folks!
