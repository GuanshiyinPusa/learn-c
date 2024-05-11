// *book.c -- one-book inventory
#include <stdio.h>
#include <string.h>
char *s_gets(char *st, int n);
#define MAXTITL 41 /* maximum length of title 1 */
#define MAXAUTL 31 /* maximum length of author's name + 1 */

struct book { /* structure template: tag is book */
	char title[MAXTITL];
	char author[MAXAUTL];
	float value;
}; /* end of structure template */

/* As far as the computer is concerned, the declaration */
/* struct book library; */

/* is short for */
// struct book {
// 	char title[MAXTITL];
// 	char author[AXAUTL];
// 	float value;
// } library;

/* Or */
// struct book library = {
// 	"The Pious Pirate and the Devious Damsel",
// 	"Renee Vivotte",
// 	1.95,
// };

// C99 and C11 provide designated initializers for structures. The syntax is
// similar to that for designated initializers for arrays. However, designated
// initializers for structures use the dot operator and member names instead of
// brackets and indices to identify particular elements. For example, to
// initialize just the value member of a book structure, you would do this:
// struct book surprise = {.value = 10.99};
// You can use designated initializers in any order:
// struct book gift = {
// 	.value = 25.99,
// 	.author = "James Broadfool",
// 	.title = "Rue for the Toad",
// };

// struct book gift = {
// 	.value = 18.90,
// 	.author = "Philionna Pestle",
// 	0.25,
// };

// The value 0.25 is assigned to the value member because it is the one
// immediately listed after the author member in the structure declaration.
/* follow declaration with variable name */
int main(void) {
	struct book library; /* declare library as a book variable */

	printf("Please enter the book title.\n");
	s_gets(library.title, MAXTITL); /* access to the title position */
	printf("Now enter the author.\n");
	s_gets(library.author, MAXAUTL);
	printf("Now enter the value.\n");
	scanf("%f", &library.value);
	printf("%s by %s: $%.2f\n", library.title, library.author, library.value);
	printf(
		"%s: \"%s\" ($%.2f)\n", library.author, library.title, library.value);
	printf("Done.\n");
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

// Output:
// Please enter the book title.
// Chicken of the Andes
// Now enter the author.
// Disma Lapoult
// Now enter the value.
// 29.99
// Chicken of the Andes by Disma Lapoult: $29.99
// Disma Lapoult: "Chicken of the Andes" ($29.99)
// Done.
