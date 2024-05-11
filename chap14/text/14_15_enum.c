/* Union */
// Union setup is the same as struct
// The following can hold a int or double or char.
// The system will alocate enough space so it can hold the largest of the
// described possibilities.
//  union hold {
// int digit;
// double bigfl;
// char letter;
// };

// Initializing a union:
// 1. to another union of the same type
// union hold valA;
// valA.letter = 'R';
// union hold valB = valA; // initialize one union to another
// 2. the first element of the union
// union hold valC = {88}; // initialize digit member of union
// 3. designated initializer
// union hold valD = {.bigfl = 118.2}; // designated initializer

// Using Union
/* fit.digit = 23;	  // 23 is stored in fit; 2 bytes used
fit.bigfl = 2.0;  // 23 cleared, 2.0 stored; 8 bytes used
fit.letter = 'h'; // 2.0 cleared, h stored; 1 byte use */
// pu = &fit;
// x = pu->digit;// same as x = fit.digit

/* enum.c -- uses enumerated values */
#include <stdbool.h> // C99 feature
#include <stdio.h>
#include <string.h> // for strcmp(), strchr()
char *s_gets(char *st, int n);

enum spectrum { red, orange, yellow, green, blue, violet };

const char *colors[] = {
	"red", "orange", "yellow", "green", "blue", "violet",
};
#define LEN 30

int main(void) {
	char choice[LEN];
	enum spectrum color;
	bool color_is_found = false;
	puts("Enter a color (empty line to quit):");
	while (s_gets(choice, LEN) != NULL && choice[0] != '\0') {
		for (color = red; color <= violet; color++) {
			if (strcmp(choice, colors[color]) == 0) {
				color_is_found = true;
				break;
			}
		}
		if (color_is_found)
			switch (color) {
			case red:
				puts("Roses are red.");
				break;
			case orange:
				puts("Poppies are orange.");
				break;
			case yellow:
				puts("Sunflowers are yellow.");
				break;
			case green:
				puts("Grass is green.");
				break;
			case blue:
				puts("Bluebells are blue.");
				break;
			case violet:
				puts("Violets are violet.");
				break;
			}
		else
			printf("I don't know about the color %s.\n", choice);
		color_is_found = false;
		puts("Next color, please (empty line to quit):");
	}
	puts("Goodbye!");
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