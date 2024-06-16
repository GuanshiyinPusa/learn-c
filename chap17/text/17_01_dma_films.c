#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TSIZE 45 /* size of array to hold title */

struct film {
	char title[TSIZE];
	int rating;
};

char *s_gets(char *st, int n);

int main(void) {
	struct film *movies;
	int n = 0;
	printf("How many movies do you want to enter? ");
	scanf("%d", &n);
	while (getchar() != '\n')
		continue; // clear input buffer

	// Dynamically allocate memory for n movies
	movies = (struct film *)malloc(n * sizeof(struct film));
	if (movies == NULL) {
		printf("Memory allocation failed.\n");
		exit(1);
	}

	int i = 0;
	puts("Enter first movie title:");
	while (i < n && s_gets(movies[i].title, TSIZE) != NULL &&
		   movies[i].title[0] != '\0') {
		puts("Enter your rating <0-10>:");
		scanf("%d", &movies[i++].rating);
		while (getchar() != '\n')
			continue; // clear input buffer
		if (i < n) {
			puts("Enter next movie title (empty line to stop):");
		}
	}

	if (i == 0)
		printf("No data entered. ");
	else
		printf("Here is the movie list:\n");

	for (int j = 0; j < i; j++)
		printf("Movie: %s  Rating: %d\n", movies[j].title, movies[j].rating);

	free(movies); // Free the allocated memory
	printf("Bye!\n");

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