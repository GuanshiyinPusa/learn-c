/* randbin.c -- random access, binary i/o */
#include <stdio.h>
#include <stdlib.h>
#define ARSIZE 1000

int main() {
	double numbers[ARSIZE];
	double value;
	const char *file = "numbers.dat";
	int i;
	long pos;
	FILE *iofile;
	// create a set of double values
	for (i = 0; i < ARSIZE; i++)
		numbers[i] = 100.0 * i + 1.0 / (i + 1);
	// attempt to open file
	if ((iofile = fopen(file, "wb")) == NULL) {
		fprintf(stderr, "Could not open %s for output.\n", file);
		exit(EXIT_FAILURE);
	}
	// write array in binary format to file
	fwrite(numbers, sizeof(double), ARSIZE, iofile);
	fclose(iofile);
	if ((iofile = fopen(file, "rb")) == NULL) {
		fprintf(stderr, "Could not open %s for random access.\n", file);
		exit(EXIT_FAILURE);
	}
	// read selected items from file
	printf("Enter an index in the range 0-%d.\n", ARSIZE - 1);
	while (scanf("%d", &i) == 1 && i >= 0 && i < ARSIZE) {
		pos = (long)i * sizeof(double); // calculate offset
		fseek(iofile, pos, SEEK_SET);	// go there
		fread(&value, sizeof(double), 1, iofile);
		printf("The value there is %f.\n", value);
		printf("Next index (out of range to quit):\n");
	}
	// finish up
	fclose(iofile);
	puts("Bye!");
	return 0;
}

// First, the program creates an array and places some values into it. Then it
// creates a file called numbers.dat in binary mode and uses fwrite() to copy
// the array contents to the file. The 64-bit pattern for each double value is
// copied from memory to the file. You can’t read the resulting binary file with
// a text editor because the values are not translated to strings. However, each
// value is stored in the file precisely as it was stored in memory, so there is
// no loss of preci- sion. Furthermore, each value occupies exactly 64 bits of
// storage in the file, so it is a simple matter to calculate the location of
// each value.
// The second part of the program opens the file for reading and
// asks the user to enter the index for a value. Multiplying the index times the
// number of bytes per double yields the location in the file. The program then
// uses fseek() to go to that location and fread() to read the value there. Note
// that there are no format specifiers. Instead, fread() copies the 8 bytes,
// starting at that location, into the memory location indicated by &value. Then
// the program can use printf() to display value. Here is a sample run:

// Enter an index in the range 0-999. 500
// The value there is 50000.001996.
// Next index (out of range to quit): 900
// The value there is 90000.001110.
// Next index (out of range to quit): 0
// The value there is 1.000000.
// Next index (out of range to quit):
// -1
// Bye!