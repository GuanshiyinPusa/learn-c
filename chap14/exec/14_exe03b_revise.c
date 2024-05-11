/* Revise the book-listing program in Listing 14.2 so that it prints the book
descriptions in the order entered, then alphabetized by title, and then in order
of increased value. */

/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
void sort_decreasing(int array[], int size);
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 100 /* maximum number of books*/

struct book { /* set up book template */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
};

void swap(struct book *a, struct book *b);
void sort_alphabet(struct book input[], int size);
void sort_value(struct book input[], int size);
void print_book(struct book input[], int count);
char *s_gets(char *st, int n);

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
		scanf("%f", &library[count++].value);
		while (getchar() != '\n')
			continue; /* clear input line */
		if (count < MAXBKS)
			printf("Enter the next title.\n");
	}
	if (count > 0) {
		printf("Here is the list of your books:\n");
		// print the job descriptions in the order entered
		print_book(library, count);
		// print then alphabetized by title
		sort_alphabet(library, count);
		print_book(library, count);
		// and then in order of increased value
		sort_value(library, count);
		print_book(library, count);
	} else
		printf("No books? Too bad.\n");
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

void swap(struct book *a, struct book *b) {
	struct book temp = *a;
	*a = *b;
	*b = temp;
}

void sort_alphabet(struct book input[], int size) {
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (strcmp(input[j].title, input[j + 1].title) > 0)
				swap(&input[j], &input[j + 1]);
}

void sort_value(struct book input[], int size) {
	for (int i = 0; i < size - 1; i++)
		for (int j = 0; j < size - i - 1; j++)
			if (input[j].value < input[j + 1].value)
				swap(&input[j], &input[j + 1]);
}

void print_book(struct book input[], int count) {
	for (int index = 0; index < count; index++)
		printf(
			"%s by %s: $%.2f\n", input[index].title, input[index].author,
			input[index].value);
}