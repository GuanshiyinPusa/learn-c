// Write a file-copy program that takes the original filename and the copy file
// from the command line. Use standard I/O and the binary mode, if possible.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char buffer[1024];
	size_t bytes_read;
	FILE *srce, *dest;

	// cmdline input -- error handling
	if (argc != 3) {
		fprintf(stderr, "Usage: %s source_file destination_file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	srce = fopen(argv[1], "rb");
	if (srce == NULL) {
		fprintf(stderr, "Error opening source file: %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	dest = fopen(argv[2], "wb");
	if (dest == NULL) {
		fprintf(stderr, "Error opening destination file: %s\n", argv[2]);
		fclose(srce);
		exit(EXIT_FAILURE);
	}

	// fread, fwrite module
	while ((bytes_read = fread(buffer, 1, sizeof(buffer), srce)) > 0) {
		if (fwrite(buffer, 1, bytes_read, dest) != bytes_read) {
			fprintf(stderr, "Error writing to file: %s\n", argv[2]);
			fclose(srce);
			fclose(dest);
			exit(EXIT_FAILURE);
		}
	}
	// --------------------

	fclose(srce);
	fclose(dest);
	return 0;
}