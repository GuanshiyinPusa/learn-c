#include <stdio.h>

char *pr(char *str) {
	char *pc;	// initialize a ptr
	pc = str;	// assign ptr to str
	while (*pc) // print every char in pc
		putchar(*pc++);
	do {
		putchar(*--pc);
	} while (pc - str);
	return (pc);
}

int main(void) {
	char *x = pr("Ho Ho Ho!");
	printf("%s", x);
	return 0;
}

// the following function call:
// x = pr("Ho Ho Ho!");
// a. What is printed?
// Ho Ho Ho!!oH oH oH

// b. What type should x be?
// char *

// c. What value does x get?
// address of first H

// d. What does the expression *--pc mean, and how is it different from --*pc?
// --pc moves the address and * takes the value, so *--pc is decremented ptr
// *pc takes the value, --*pc decremented the value.

// e. What would be printed if *--pc were replaced with *pc--?
// *--pc the ptr is decremented then value is accessed. Ho Ho Ho!!oH oH oH
// *pc-- the value is accessed then the ptr is decremented. Ho Ho Ho!!oH oH o

// f. What do the two while expressions test for?
// First when checks if pc is null pointer, Second checks if pc points to the
// same location as str does.

// g. What happens if pr() is supplied with a null string as an argument?
// segmentation fault (core dump) because pc - str is never 0.

// h. What must be done in the calling function so that pr() can be used as
// shown?
// function declration char *pr (char *)
