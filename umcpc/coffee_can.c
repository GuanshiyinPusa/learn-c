#include <stdio.h>
#define PI 3.14159

double find_surface_area(double radius, double height) {
	return 2 * PI * radius * radius + 2 * PI * radius * height;
}

int main(void) {
	int n;
	scanf("%d\n", &n);
	double radius = 0, height = 0;
	while (n--) {
		scanf("%lf %lf\n", &radius, &height);
	}
}
