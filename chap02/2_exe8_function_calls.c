/* function_calls.c -- a program that calls function in function */
#include <stdio.h>

// function declaration
void one_three(void);
void two(void);

void one_three(void) {
	// print one
	printf("one\n");
	// call function two()
	two();
	// print three
	printf("three\n");
}

void two(void) {
	// print two
	printf("two\n");
}

int main(void) {
	// print starting now:
	printf("starting now:\n");
	one_three();
	// print done!
	printf("done!\n");
}

/*
 * Output:
 * starting now:
 * one
 * two
 * three
 * done!
 */
