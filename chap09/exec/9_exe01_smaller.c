// Devise a function called min(x, y) that returns the smaller of two double
// values. Test the function wit ha simple driver
#include <stdio.h>
double min(double, double);

int main(void) {
	printf("%.2f\n", min(1.2, 3.3));
	return 0;
}

double min(double x, double y) { return (x < y) ? x : y; }
