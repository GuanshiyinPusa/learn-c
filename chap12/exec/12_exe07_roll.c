// Write a program that behaves like the modification of Listing 12.13, which we
// discussed after showing the output of Listing 12.13. That is, have the
// program produce output like the following:
// Enter the number of sets; enter q to stop: 18
// How many sides and how many dice? 6 3
// Here are 18 sets of 3 6-sided throws.
// 12 10 6 9 8 14 8 15 9 14 12 17 11 7 10 13 8 14
// How many sets? Enter q to stop: q

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "diceroll.h"

int main(void) {
	int set_number;
	srand((unsigned int)time(0));
	/* read set number */

	while (printf("Enter the number of sets; enter q to stop: ") &&
		   scanf("%d", &set_number) == 1 && set_number > 0) {
		// initialize an array to store dice throws
		int sides;
		int dice;
		int dice_throws[set_number];
		printf("How many sides and how many dice? ");
		scanf("%d %d", &sides, &dice);
		// loop set_number of times and record them inside an array
		for (int i = 0; i < set_number; i++) {
			dice_throws[i] = roll_n_dice(dice, sides);
		}
		// print the array
		printf(
			"Here are %d sets of %d %d-sided throws.\n", set_number, dice,
			sides);
		for (int i = 0; i < set_number; i++) {
			printf("%d ", dice_throws[i]);
		}
		printf("\n");
	}
	return 0;
}
