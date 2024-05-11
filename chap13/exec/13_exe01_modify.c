// Modify Listing 13.1 so that it solicits the user to enter the filename and
// reads the user’s response instead of using command-line arguments.

/* count.c -- using standard I/O */
#include <stdio.h>
#include <stdlib.h> // exit() prototype
#include <string.h>
char *s_gets(char *st, int n);

int main(void) {
	char file[20];
	int ch;	  // place to store each character as read
	FILE *fp; // "file pointer"
	unsigned long count = 0;
	// ask for file name -- error checking module
	printf("Enter the filename: ");
	if (s_gets(file, 20) == NULL) {
		fprintf(stderr, "Error reading filename.\n");
		exit(EXIT_FAILURE);
	}
	// open file -- error checking module
	if ((fp = fopen(file, "r")) == NULL) {
		fprintf(stdout, "Can't open %s file.\n", file);
		exit(EXIT_FAILURE);
	}
	// read file -- print every character
	while ((ch = getc(fp)) != EOF) { // getc needs a source compares to getchar
		putc(ch, stdout);			 // same as putchar(ch);
		count++;
	}
	fclose(fp);
	printf("File %s has %lu characters\n", file, count);
	return 0; // note: same as exit(0) == exit(EXIT_SUCCESS)
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
