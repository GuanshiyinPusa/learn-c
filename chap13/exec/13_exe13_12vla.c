// Do Programming Exercise 12, but use variable-length arrays (VLAs) instead of
// standard arrays.
#include <stdio.h>
#include <stdlib.h>

#define LEVELS 10
#define FILENAME "image.txt"
#define OUTFILE "imageout.txt"

const char trans[LEVELS + 1] = " .':~*=&%@";

int main(void) {
	int row, col;
	int rows = 20;
	int cols = 30;

	int image[rows][cols];
	char pic[rows][cols + 1];
	FILE *in, *out;

	if ((in = fopen(FILENAME, "r")) == NULL) {
		fprintf(stderr, "Could not open file %s for input.\n", FILENAME);
		exit(EXIT_FAILURE);
	}

	if ((out = fopen(OUTFILE, "w")) == NULL) {
		fprintf(stderr, "Could not open file %s for output.\n", OUTFILE);
		exit(EXIT_FAILURE);
	}

	for (row = 0; row < rows; row++)
		for (col = 0; col < cols; col++)
			fscanf(in, "%d", &image[row][col]);

	for (row = 0; row < rows; row++) {
		for (col = 0; col < cols; col++)
			pic[row][col] = trans[image[row][col]];
		pic[row][col] = '\0';
	}

	for (row = 0; row < rows; row++) {
		puts(pic[row]);
		fprintf(out, "%s\n", pic[row]);
	}

	fclose(in);
	fclose(out);

	return 0;
}