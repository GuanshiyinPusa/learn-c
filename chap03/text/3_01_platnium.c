/* platnium.c -- your weight in platnium */
#include <stdio.h>

int main(void) {
	float weight; /* user weight          */
	float value;  /* platnium equivalent  */

	printf("Are you worth your weight in platnium?\n");
	printf("Let's check it out.\n");
	printf("Please enter your weight in pounds.\n");

	/* get input from the user              */
	scanf("%f", &weight);

	/* assume platnium is $1700 per ounce   */
	value = 1700.0 * weight * 14.5833;

	printf("Your weight in platnium is worth $%.2f.\n", value);
	printf("You are easily worth that! If platnium prices drop,\n");
	printf("eat more to maintain your value.\n");

	return 0;
}

/*
 * Output:
 * Are you worth your weight in platnium?
 * Let's check it out.
 * Please enter your weight in pounds.
 * 150
 * Your weight in platnium is worth $36712500.00.
 * You are easily worth that! If platnium prices drop,
 * eat more to maintain your value.
 */
