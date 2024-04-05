// Suppose you have these declarations:
// float rootbeer[10], things[10][5], *pf, value = 2.2;
// int i = 3;
// Identify each of the following statements as valid or invalid:
// a. rootbeer[2] = value;
// b. scanf("%f", &rootbeer );
// c. rootbeer = value;
// d. printf("%f", rootbeer);
// e. things[4][4] = rootbeer[3];
// f. things[5] = rootbeer;
// g. pf = value;
// h. pf = rootbeer;
#include <stdio.h>

int main(void) {
	float rootbeer[10], things[10][5], *pf, value = 2.2;
	int i = 3;
	// Yes
	rootbeer[2] = 2.2;
	// No, rootbeer is a pointer, float *
	scanf("%f", &rootbeer);
	// float * can't be assigned by a float
	rootbeer = value;
	// rootbeer is type pointer, therefore %p
	printf("%f", rootbeer);
	// Yes
	things[4][4] = rootbeer[3];
	// rootbeer is an address, while things[5] requires a float
	things[5] = rootbeer;
	// pf is pointer, float *, value is float
	pf = value;
	pf = rootbeer;
}
