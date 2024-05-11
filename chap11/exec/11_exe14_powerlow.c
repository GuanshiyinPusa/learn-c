// Write a power-law program that works on a command-line basis. The first
// command-line argument should be the type double number to be raised to a
// certain power, and the second argument should be the integer power.

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	if (argc != 3) {
		fprintf(stderr, "Usage: %s <number> <power>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	double number = atof(argv[1]);
	int power = atoi(argv[2]);

	printf("%f\n", pow(number, power));

	return 0;
}

// Compile using clang 11_exe14_powerlow.c -lm
