#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE *file_pointer;
	char buffer[100]; // Buffer to hold data

	// Open a file for writing
	file_pointer = fopen("example.txt", "w");
	if (file_pointer == NULL) {
		printf("Error opening the file for writing.\n");
		return 1;
	}

	// Write data to the file
	char data_to_write[] = "Hello, world!";
	fwrite(data_to_write, sizeof(char), sizeof(data_to_write), file_pointer);

	// Close the file
	fclose(file_pointer);

	// Open the same file for reading
	file_pointer = fopen("example.txt", "r");
	if (file_pointer == NULL) {
		printf("Error opening the file for reading.\n");
		return 1;
	}

	// Read data from the file into buffer
	fread(buffer, sizeof(char), sizeof(data_to_write), file_pointer);

	// Close the file
	fclose(file_pointer);

	// Print the read data
	printf("Data read from file: %s\n", buffer);

	return 0;
}

// The prototype for fwrite() is this:
// size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb,
// FILE * restrict fp);
// The fwrite() function writes binary data to a file. The size_t type is
// defined in terms of the standard C types. It is the type returned by the
// sizeof operator. Typically, it is unsigned int, but an implementation can
// choose another type. The pointer ptr is the address of the chunk of data to
// be written. Also, size represents the size, in bytes, of the chunks to be
// written, and nmemb represents the number of chunks to be written. As usual,
// fp identifies the file to be written to. For instance, to save a data object
// (such as an array) that is 256 bytes in size, you can do this:
// char buffer[256];
// fwrite(buffer, 256, 1, fp);
// This call writes one chunk of 256 bytes from buffer to the file. Or, to save
// an array of 10 double values, you can do this: double earnings[10];
// fwrite(earnings, sizeof (double), 10, fp);

// The prototype for fread() is this:
// size_t fread(void * restrict ptr, size_t size, size_t nmemb,
// FILE * restrict fp);
// The fread() function takes the same set of arguments that fwrite() does. This
// time ptr is the address of the memory storage into which file data is read,
// and fp identifies the file to be read. Use this function to read data that
// was written to a file using fwrite(). For example, to recover the array of 10
// doubles saved in the previous example, use this call:
// double earnings[10];
// fread(earnings, sizeof (double), 10, fp);
// This call copies 10 size double values into the earnings array.
// The fread() function returns the number of items successfully read. Normally,
// this equals nmemb, but it can be less if there is a read error or if the
// end-of-file is reached.