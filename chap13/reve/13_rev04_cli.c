// Write a program that takes zero command-line arguments or one command-line
// argument. If there is one argument, it is interpreted as the name of a file.
// If there is no argument, the standard input (stdin) is to be used for input.
// Assume that the input consists entirely of floating-point numbers. Have the
// program calculate and report the arithmetic mean (the average) of the input
// numbers.

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	FILE *fp;
	double num, sum = 0;
	int count = 0;
	if (argc == 1)
		fp = stdin;
	else if (argc == 2) {
		if ((fp = fopen(argv[1], "r")) == NULL) {
			fprintf(stderr, "Can't open %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
	} else {
		fprintf(stderr, "Usage: %s [filename]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	while (fscanf(fp, "%lf", &num) == 1) {
		sum += num;
		count++;
	}
	if (count > 0)
		printf("Average of %d numbers is %.2f\n", count, sum / count);
	else
		printf("No numbers read\n");
	if (fp != stdin)
		fclose(fp);
	return 0;
}