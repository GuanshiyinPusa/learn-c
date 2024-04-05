/*
Modify exercise 8 so that it uses a function to return the value of the
calculation
*/
#include <stdio.h>
float loopfloat(float a, float b);

int main(void) {
	float a, b, result;
	printf("Give me two floating number:\n");
	while (scanf("%f %f", &a, &b)) {
		result = loopfloat(a, b);
		printf("%.2f", result);
	}
	return 0;
}

float loopfloat(float a, float b) { return (a - b) / (a * b); }
