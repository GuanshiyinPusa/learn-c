// include <stdio.h>
#include <stdio.h>

// main()
int main(void) {
	// float g; h;
	float g, h;
	float tax, rate;

	// g = e21;
	g = 1e21;
	tax = rate * g;

	// printf otherwise stdio.h is useless
	printf("the tax of %f is %f\n", g, tax);
	return 0;
}

/*
 * Output:
 * the tax of 1000000000000000000000.000000 is 0.000000
 */
