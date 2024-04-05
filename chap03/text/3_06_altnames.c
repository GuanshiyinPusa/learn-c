/* altnames.c -- portable names for integer types */

#include <inttypes.h> // support portable types
#include <stdio.h>

int main(void) {
	int32_t me32; // me32 -- a 32-bit signed value

	me32 = 45933945;
	printf("First, assume int32_t is int: ");
	printf("m32 = %d\n", me32);
	printf("Next, Let's not make any assumptions.\n");
	printf("Instead, use a \"macro\" from inttypes.h: ");
	printf("me32 = %" PRId32 "\n", me32);

	return 0;
}

/*
 * Output:
 * First, assume int32_t is int: m32 = 45933945
 * Next, Let's not make any assumptions.
 * Instead, use a "macro" from inttypes.h: me32 = 45933945
 */
