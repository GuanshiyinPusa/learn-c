/* strptr.c -- strings as pointers */
#include <stdio.h>

int main(void) {
	printf("%s, %p, %c\n", "We", "are", *"space farers");

	return 0;
}

// Output:
// We, 0x5f0a78919013, s
