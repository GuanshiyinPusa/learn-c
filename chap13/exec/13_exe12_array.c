// Create a text file consisting of 20 rows of 30 integers. The integers should
// be in the range 0–9 and be separated by spaces. The file is a digital
// representation of a picture, with the values 0 through 9 representing
// increasing levels of darkness. Write a program that reads the contents of the
// file into a 20-by-30 array of ints. In a crude approach toward converting
// this digital representation to a picture, have the program use the values in
// this array to initialize a 20-by-31 array of chars, with a 0 value
// corresponding to a space character, a 1 value to the period character, and so
// on, with each larger number represented by a character that occupies more
// space. For example, you might use # to represent 9. The last character (the
// 31st) in each row should be a null character, making it an array of 20
// strings. Have the program display the resulting picture (that is, print the
// strings) and also store the result in a text file. For example, suppose you
// start with this data:
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 30
#define LEVELS 10
#define FILENAME "image.txt"
#define OUTFILE "imageout.txt"

const char trans[LEVELS + 1] = " .':~*=&%@";

int main(void) {
	int row, col;
	int image[ROWS][COLS];
	char pic[ROWS][COLS + 1];
	FILE *in, *out;

	if ((in = fopen(FILENAME, "r")) == NULL) {
		fprintf(stderr, "Could not open file %s for input.\n", FILENAME);
		exit(EXIT_FAILURE);
	}

	if ((out = fopen(OUTFILE, "w")) == NULL) {
		fprintf(stderr, "Could not open file %s for output.\n", OUTFILE);
		exit(EXIT_FAILURE);
	}

	for (row = 0; row < ROWS; row++)
		for (col = 0; col < COLS; col++)
			fscanf(in, "%d", &image[row][col]);

	for (row = 0; row < ROWS; row++) {
		for (col = 0; col < COLS; col++)
			pic[row][col] = trans[image[row][col]];
		pic[row][col] = '\0';
	}

	for (row = 0; row < ROWS; row++) {
		puts(pic[row]);
		fprintf(out, "%s\n", pic[row]);
	}

	fclose(in);
	fclose(out);

	return 0;
}