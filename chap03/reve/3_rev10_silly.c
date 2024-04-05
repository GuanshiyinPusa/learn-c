#include <stdio.h>

// void main(int)
int main(void) {
	// cows, legs integer;
	int cows, legs;
	printf("How many cow legs did you count?\n");
	// scanf("%c", legs);
	scanf("%d", &legs);
	cows = legs / 4;
	// printf("That implies there are %f cows.\n", cows);
	printf("That implies there are %d cows.\n", cows);
}

/*
 * Output:
 * How many cow legs did you count?
 * 4
 * That implies there are 1 cows.
 */
