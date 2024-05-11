/* sort_str.c -- reads in strings and sorts them */
#include <stdio.h>
#include <string.h>
#define SIZE 81						 /* string length limit, including \0 */
#define LIM 20						 /* maximum number of lines to be read */
#define HALT ""						 /* null string to stop input */
void stsrt(char *string[], int num); /* string-sort function */
char *s_gets(char *st, int n);

int main(void) {
	char input[LIM][SIZE]; /* array to store input */
	char *ptstr[LIM];	   /* array of pointer variables */
	int ct = 0;			   /* input count */
	int k;				   /* output count */

	printf("Input up to %d lines, and I will sort them,\n", LIM);
	printf("To stop, press the Enter key at a line's start.\n");
	while (ct < LIM && s_gets(input[ct], SIZE) != NULL &&
		   input[ct][0] != '\0') {
		ptstr[ct] = input[ct]; /* set ptrs to strings */
		ct++;
	}
	stsrt(ptstr, ct); /* string sorter */
	puts("\nHere's the sorted list:\n");
	for (k = 0; k < ct; k++)
		puts(ptstr[k]); /* sorted pointers */
	return 0;
}

/* string-pointer-sorting function */
void stsrt(char *strings[], int num) {
	char *temp;
	int top, seek;

	for (top = 0; top < num - 1; top++)
		for (seek = top + 1; seek < num; seek++)
			if (strcmp(strings[top], strings[seek]) > 0) {
				temp = strings[top];
				strings[top] = strings[seek];
				strings[seek] = temp;
			}
}

char *s_gets(char *st, int n) {
	char *ret_val = fgets(st, n, stdin);
	if (ret_val) {
		char *newline = strchr(ret_val, '\n'); // find the first '\n's address
		if (newline)
			*newline = '\0';
		else {
			char ch;
			while ((ch = getchar()) != '\n' && ch != EOF)
				continue;
		}
	}
	return ret_val;
}

// Output:
// Input up to 20 lines, and I will sort them,
// To stop, press the Enter key at a line's start.
// O that I was where I would be,
// Then would I be where I am not;
// But where I am I must be,
// And where I would be I can not.
//
//
// Here's the sorted list:
//
// And where I would be I can not.
// But where I am I must be,
// O that I was where I would be,
// Then would I be where I am not;
