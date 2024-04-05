/*
Modify the guessing program of Listing 8.4 so that it uses a more intelligent
guessing strategy. For example, have the program initially guess 50, and have it
ask the user whether the guess is high, low, or correct. If, say, the guess is
low, have the next guess be halfway between 50 and 100, that is, 75. If that
guess is high, let the next guess be halfway between 75 and 50, and so on. Using
this binary search strategy, the program quickly zeros in on the correct answer,
at least if the user does not cheat.
*/
#include <stdbool.h>
#include <stdio.h>

int main(void) {
	int guess = 50;
	int upper_bound = 100;
	int lower_bound = 0;
	char response;
	printf("Pick an integer from 1 to 100. I will try to guess it.\n");
	printf("Respond with a y if my guess is correct and with an h if it is too "
		   "high and with an l if it is too low.\n");
	printf("Uh...is your number %d?\n", guess);
	while ((response = getchar()) != 'y') {
		if (response == 'h') {
			upper_bound = guess;
			guess = (upper_bound + lower_bound) / 2;
			printf("Well, then, is it %d?\n", guess);
		} else if (response == 'l') {
			lower_bound = guess;
			guess = (upper_bound + lower_bound) / 2;
			printf("Well, then, is it %d?\n", guess);
		} else {
			printf("Invalid response. Please enter 'y' for yes, 'h' for high, "
				   "or 'l' for low.\n");
		}
		while (getchar() != '\n') // Skip rest of input line
			continue;
	}
	printf("I knew I could do it!\n");
	return 0;
}
