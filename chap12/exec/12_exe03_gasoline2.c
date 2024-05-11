#include <stdio.h>

void get_info(int *mode);
void show_info(int *mode, double distance, double fuel);

int main(void) {
	int mode;
	printf("Enter 0 for metric mode, 1 for US mode: ");
	scanf("%d", &mode);
	while (mode >= 0) {
		get_info(&mode);
		printf("Enter 0 for metric mode, 1 for US mode");
		printf(" (-1 to quit): ");
		scanf("%d", &mode);
	}
	printf("Done.\n");
	return 0;
}

void get_info(int *mode) {
	double distance, fuel;
	if (*mode == 0) {
		printf("Enter distance traveled in kilometers: ");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in liters: ");
		scanf("%lf", &fuel);
	} else if (*mode != 1) {
		printf("Invalid mode specified. Mode 1(US) used.\n");
		*mode = 1;
		printf("Enter distance traveled in miles: ");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in gallons: ");
		scanf("%lf", &fuel);
	} else {
		printf("Enter distance traveled in miles: ");
		scanf("%lf", &distance);
		printf("Enter fuel consumed in gallons: ");
		scanf("%lf", &fuel);
	}

	show_info(mode, distance, fuel);
}

void show_info(int *mode, double distance, double fuel) {
	if (*mode == 0) {
		printf(
			"Fuel consumption is %.2f liters per 100 km.\n",
			fuel / distance * 100);
	} else {
		printf("Fuel consumption is %.1f miles per gallon.\n", distance / fuel);
	}
}
