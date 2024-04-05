/* strptr.c -- strings as pointers */
#include <stdio.h>

int main(void) {
	// %s produce a string, %p - address of first character
	// *"space farers" produce the value to which the address points: s
	printf("%s, %p, %c\n", "We", "are", *"space farers");
	return 0;
}

// Output:
// We, 0x650ef8d38004, s

// String literal concatenation:
// char greeting[50] = "Hello, and"" how are""you" today!";
// is equivalent to this:
// char greeting[50] = "Hello, and how are you today!";

// if you want to use a double quotation mark, you can use backslash o print it:
// printf("\"Run, Spot, run!\" exclaimed Dick.\n");
// prints: "Run, Spot, run!" exclaimed Dick.

// char array:
// const char m1[40] = "Limit yourself to one line's worth.";
// const char m1[40] = { 'L','i', 'm', 'i', 't', ' ', 'y', 'o', 'u', 'r', 's',
// 'e', 'l','f', ' ', 't', 'o', ' ', 'o', 'n', 'e', ' ','l', 'i', 'n', 'e', '\",
// 's', ' ', 'w', 'o', 'r','t', 'h', '.', '\0'};

// Note that any unused element are automatically initialized to \0.
// Or let the compiler determine the array size:
// const char m2[] = "If you can't think of anything, fake it.";

// VLA for char array:
// int n = 8;
// char cookies[1];
// valid
// char cakes[2 + 5]; // valid, size is a constant expression
// char pies[2*sizeof(long double) + 1]; // valid
// char crumbs[n];
// invalid prior to C99, a VLA after C99

// So the whole thing from pointer and array applys on char array as well:
// char car[10] = "Tata";
// car == &car[0] , *car == 'T', and *(car+1) == car[1] == 'a'

// pointer notation:
// So you can use the pointer notation to initialize string like array does:
// const char * pt1 = "Something is pointing at me.";
// const char ar1[] = "Something is pointing at me.";
