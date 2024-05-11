/* Revise the book-listing program in Listing 14.2 so that it prints the book
descriptions in the order entered, then alphabetized by title, and then in order
of increased value. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* maximum number of books*/

struct book { /* set up book template */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
	int entry;
};

int compare_by_entry(const void *a, const void *b) {
	struct book *bookA = (struct book *)a;
	struct book *bookB = (struct book *)b;
	return bookA->entry - bookB->entry;
}

int compare_by_title(const void *a, const void *b) {
	struct book *bookA = (struct book *)a;
	struct book *bookB = (struct book *)b;
	return strcmp(bookA->title, bookB->title);
}

int compare_by_value(const void *a, const void *b) {
	struct book *bookA = (struct book *)a;
	struct book *bookB = (struct book *)b;
	if (bookA->value < bookB->value)
		return -1;
	else if (bookA->value > bookB->value)
		return 1;
	else
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

int main(void) {
	struct book library[MAXBKS]; /* array of book structures */
	int count = 0;
	int index;
	printf("Please enter the book title.\n");
	printf("Press [enter] at the start of a line to stop.\n");
	while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL &&
		   library[count].title[0] != '\0') {
		printf("Now enter the author.\n");
		s_gets(library[count].author, MAXAUTL);
		printf("Now enter the value.\n");
		scanf("%f", &library[count].value);
		library[count].entry = count;
		count++;
		while (getchar() != '\n')
			continue; /* clear input line */
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}
	if (count > 0) {
		qsort(library, count, sizeof(struct book), compare_by_entry);
		printf("Here is the list of your books by entry:\n");
		for (index = 0; index < count; index++)
			printf(
				"%s by %s: $%.2f\n", library[index].title,
				library[index].author, library[index].value);

		qsort(library, count, sizeof(struct book), compare_by_title);
		printf("Here is the list of your books by title:\n");
		for (index = 0; index < count; index++)
			printf(
				"%s by %s: $%.2f\n", library[index].title,
				library[index].author, library[index].value);

		qsort(library, count, sizeof(struct book), compare_by_value);
		printf("Here is the list of your books by value:\n");
		for (index = 0; index < count; index++)
			printf(
				"%s by %s: $%.2f\n", library[index].title,
				library[index].author, library[index].value);
	} else
		printf("No books? Too bad.\n");
	return 0;
}