#include <stdio.h>

int main() {
	// Open a file in write mode
	FILE *file = fopen("example.txt", "w");
	if (file == NULL) {
		perror("Failed to open file");
		return 1;
	}

	// Buffering options
	char buffer[BUFSIZ];

	// Set the buffer for file to be line-buffered
	if (setvbuf(file, buffer, _IOLBF, BUFSIZ) != 0) {
		perror("Failed to set buffer");
		fclose(file);
		return 1;
	}

	// Write to the file
	fprintf(file, "Hello, ");
	fprintf(file, "World!\n");

	// Close the file
	fclose(file);

	return 0;
}

// int setvbuf(FILE *restrict fp, char *restrict buf, int mode, size_t size);

// The setvbuf() function sets up an alternative buffer to be used by the
// standard I/O functions. It is called after the file has been opened and
// before any other operations have been performed on the stream. The pointer fp
// identifies the stream, and buf points to the storage to be used. If the value
// of buf is not NULL, you must create the buffer. For instance, you could
// declare an array of 1,024 chars and pass the address of that array. However,
// if you use NULL for the value of buf, the function allocates a buffer itself.
// The size variable tells setvbuf() how big the array is. (The size_t type is a
// derived integer type; see Chapter 5, “Operators, Expressions, and
// Statements.”) The mode is selected from the following choices: _IOFBF means
// fully buffered (buffer flushed when full), _IOLBF means line-buffered (buffer
// flushed when full or when a newline is written), and _IONBF means
// nonbuffered. The function returns zero if successful, nonzero otherwise.