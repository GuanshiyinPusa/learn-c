// Programs using command-line arguments rely on the user’s memory of how to use
// them correctly. Rewrite the program in Listing 13.2 so that, instead of using
// command-line arguments, it prompts the user for the required information.
// reducto.c -- reduces your file by two-thirds
#include <stdio.h>
#include <stdlib.h> // for exit()
#include <string.h>
#define LEN 40

char *s_gets(char *st, int n);

int main(void) {
	FILE *in, *out; // declare two file pointers
	int ch;
	char name[LEN]; // storage for output filename
	int count = 0;

	// prompt the user for the required information
	printf("Enter the filename: ");
	s_gets(name, LEN);

	// set up input
	if ((in = fopen(name, "r")) == NULL) {
		fprintf(stderr, "I couldn't open the file \"%s\"\n", name);
		exit(EXIT_FAILURE);
	}
	// set up output
	strcat(name, ".red");					// append .red
	if ((out = fopen(name, "w")) == NULL) { // open file for writing
		fprintf(stderr, "Can't create output file.\n");
		exit(3);
	}
	// copy data
	while ((ch = getc(in)) != EOF)
		if (count++ % 3 == 0)
			putc(ch, out); // print every 3rd char
	// clean up
	if (fclose(in) != 0 || fclose(out) != 0)
		fprintf(stderr, "Error in closing files\n");

	return 0;
}

char *s_gets(char *st, int n) {
	char *ret_val;
	char *find;
	ret_val = fgets(st, n, stdin);
	if (ret_val) {
		find = strchr(st, '\n'); // look for newline
		if (find)				 // if the address is not NULL,
			*find = '\0';		 // place a null character there
		else
			while (getchar() != '\n')
				continue; // dispose of rest of line
	}
	return ret_val;
}
