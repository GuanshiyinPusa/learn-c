/* reverse.c -- displays a file in reverse order */
#include <stdio.h>
#include <stdlib.h>
#define CNTL_Z '\032' /* eof marker in DOS text files */
#define SLEN 81

/* fseek(file pointer, offset(type; long), mode -- starting point) */
/* go to a file location, return 0 if okay, -1 if error*/
// Offset(type long, so need to add L suffix)
// 0L -- no move
// postive int + L: 10L go 10 bytes
// negative int + L: -5L go backwards 5 bytes
// Mode
// SEEK_SET Beginning of file
// SEEK_CUR Current position
// SEEK_END End of file

// ftell
// return current file location (type long)

// fseek(fp, 0L, SEEK_END);
// sets the position to an offset of 0 bytes from the file end. That is, it sets
// the position to the end of the file. Next, the statement
// last = ftell(fp);
// assigns to last the number of bytes from the beginning to the end of the
// file.

// ANSI C does define how fpos_t is used. The fgetpos() function has this
// prototype:
// int fgetpos(FILE * restrict stream, fpos_t * restrict pos);
// When called, it places an fpos_t value in the location pointed to by pos; the
// value describes a location in the file. The function returns zero if
// successful and a nonzero value for failure. The fsetpos() function has this
// prototype:
// int fsetpos(FILE *stream, const fpos_t *pos);
// When called, it uses the fpos_t value in the location pointed to by pos to
// set the file pointer to the location indicated by that value. The function
// returns zero if successful and a nonzero value for failure. The fpos_t value
// should have been obtained by a previous call to fgetpos().
int main(void) {
	char file[SLEN];
	char ch;
	FILE *fp;
	long count, last;
	puts("Enter the name of the file to be processed:");
	scanf("%80s", file);
	if ((fp = fopen(file, "rb")) == NULL) { /* read-only mode */
		printf("reverse can't open %s\n", file);
		exit(EXIT_FAILURE);
	}
	fseek(fp, 0L, SEEK_END); /* go to end of file */
	last = ftell(fp);
	for (count = 1L; count <= last; count++) {
		fseek(fp, -count, SEEK_END); /* go backward  */
		ch = getc(fp);
		if (ch != CNTL_Z && ch != '\r') /* MS-DOS files */
			putchar(ch);
	}
	putchar('\n');
	fclose(fp);
	return 0;
}