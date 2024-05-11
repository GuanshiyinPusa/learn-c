// Digital images, particularly those radioed back from spacecraft, may have
// glitches. Add a de-glitching function to programming exercise 12. It should
// compare each value to its immediate neighbors to the left and right, above
// and below. If the value differs by more than 1 from each of its neighbors,
// replace the value with the average of the neighboring values. You should
// round the average to the nearest integer value. Note that the points along
// the boundaries have fewer than four neighbors, so they require special
// handling.
#include <stdio.h>
#include <stdlib.h>

#define LEVELS 10
#define FILENAME "image.txt"
#define OUTFILE "imageout.txt"

const char trans[LEVELS + 1] = " .':~*=&%@";

void deglitch(int rows, int cols, int image[rows][cols]) {
	int r, c;
	int sum, count;
	int temp[rows][cols];

	for (r = 0; r < rows; r++)
		for (c = 0; c < cols; c++)
			temp[r][c] = image[r][c];

	for (r = 0; r < rows; r++)
		for (c = 0; c < cols; c++) {
			sum = count = 0;
			if (r > 0) {
				sum += temp[r - 1][c];
				count++;
			}
			if (r < rows - 1) {
				sum += temp[r + 1][c];
				count++;
			}
			if (c > 0) {
				sum += temp[r][c - 1];
				count++;
			}
			if (c < cols - 1) {
				sum += temp[r][c + 1];
				count++;
			}
			if (abs(image[r][c] * count - sum) > count) {
				image[r][c] = (sum + count / 2) / count;
			}
		}
}

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

	deglitch(rows, cols, image);

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