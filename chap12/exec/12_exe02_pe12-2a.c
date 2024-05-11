#include <stdio.h>
static int mode;
static double distance, fuel;

void set_mode(int m) { mode = m; }

void get_info() {
	if (mode == 0) {
		printf("Enter distance traveled in kilometers: ");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in liters: ");
		scanf("%lf", &fuel);
		return;
	} else if (mode != 1) {
		printf("Invalid mode specified. Mode 1(US) used.\n");
		mode = 1;
	}
	printf("Enter distance traveled in miles: ");
	scanf("%lf", &distance);
	printf("Enter fuel consumed in gallons: ");
	scanf("%lf", &fuel);
}

void show_info() {
	if (mode == 0) {
		printf(
			"Fuel consumption is %.2f liters per 100 km.\n",
			fuel / distance * 100);
	} else {
		printf("Fuel consumption is %.1f miles per gallon.\n", distance / fuel);
	}
}
