/* copy2.c -- strcpy() demo */
#include <stdio.h>
#include <string.h> // declares strcpy()
#define WORDS "beast"
#define SIZE 40

int main(void) {
	const char *orig = WORDS;
	char copy[SIZE] = "Be the best that you can be.";
	char *ps;

	puts(orig);
	puts(copy);
	ps = strcpy(copy + 7, orig);

	puts(copy); // Be the beast
	puts(ps);	// beast because ps is copy + 7 which is beast

	return 0;
}

// char target[20];
// int x;
// x = 50;					  /* assignment for numbers */
// strcpy(target, "Hi ho!"); /* assignment for strings */
// target = "So long";		  /* syntax error */
//
// char *str;
// strcpy(str, "The C of Tranquility"); // a problem

// Remember, declaring an array allocates storage space for data;
// declaring a pointer only allocates storage space for one address.

// First, it is type char *. It returns the value of its first argument—the
// address of a character. Second, the first argument need not point to the
// beginning of an array; this lets you copy just part of an array.
