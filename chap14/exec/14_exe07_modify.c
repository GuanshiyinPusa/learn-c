// Modify Listing 14.14 so that as each record is read from the file and shown
// to you, you are given the chance to delete the record or to modify its
// contents. If you delete the record, use the vacated array position for the
// next record to be read. To allow changing the existing contents, you’ll need
// to use the "r+b" mode instead of the "a+b" mode, and you’ll have to pay more
// attention to positioning the file pointer so that appended records don’t
// overwrite existing records. It’s simplest to make all changes in the data
// stored in program memory and then write the final set of information to the
// file. One approach to keeping track is to add a member to the book structure
// that indicates whether it is to be deleted.
/* booksave.c -- saves structure contents in a file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 /* maximum number of books */
char *s_gets(char *st, int n);

struct book {
	/* set up book template */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int is_deleted;
};

int main(void) {
	struct book library[MAXBKS] = {0}; /* array of structures */
	int count = 0;
	int index;
	FILE *pbooks;
	int size = sizeof(struct book);
	if ((pbooks = fopen("book.dat", "r+b")) == NULL) {
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}
	rewind(pbooks);
	while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
		if (count == 0)
			puts("Current contents of book.dat:");
		printf(
			"%s by %s: $%.2f\n", library[count].title, library[count].author,
			library[count].value);
		printf("Do you want to delete or modify this book? (d/m/n): ");
		char choice;
		scanf(" %c", &choice);
		while (getchar() != '\n')
			continue; /* clear input line */
		if (choice == 'd') {
			library[count].is_deleted = 1;
		} else if (choice == 'm') {
			puts("Enter the new title.");
			s_gets(library[count].title, MAXTITL);
			puts("Enter the new author.");
			s_gets(library[count].author, MAXAUTL);
			puts("Enter the new value.");
			scanf("%f", &library[count].value);
			while (getchar() != '\n')
				continue; /* clear input line */
		}
		count++;
	}
	fclose(pbooks);
	if ((pbooks = fopen("book.dat", "w+b")) == NULL) {
		fputs("Can't open book.dat file\n", stderr);
		exit(1);
	}
	for (index = 0; index < count; index++) {
		if (!library[index].is_deleted) {
			fwrite(&library[index], size, 1, pbooks);
		}
	}
	fclose(pbooks);
	return 0;
}

char *s_gets(char *st, int n) {
	char *ret_val = fgets(st, n, stdin);
	if (ret_val) {
		while (*st != '\n' && *st != '\0')
			st++;
		if (*st == '\n')
			*st = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}