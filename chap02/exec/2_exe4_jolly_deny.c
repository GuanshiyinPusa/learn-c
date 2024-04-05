/* jolly_deny.c -- a program that uses two functions jolly() and deny() */
#include <stdio.h>

// function declaration
void jolly(void);
void deny(void);

int main(void) {
	jolly();
	deny();

	return 0;
}

void jolly(void) { printf("For he's a jolly good fellow!\n"); }

void deny(void) { printf("Which nobody can deny!\n"); }

/*
 * Output:
 * For he's a jolly good fellow!
 * Which nobody can deny!
 */
