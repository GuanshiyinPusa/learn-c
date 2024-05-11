/* p_and_s.c -- pointers and strings */
#include <stdio.h>

int main(void) {
	const char *mesg = "Don't be a fool";
	const char *copy;

	copy = mesg;
	printf("%s\n", copy);
	printf("mesg = %s, &mesg = %p, value = %p\n", mesg, &mesg, mesg);
	printf("copy = %s, &copy = %p, value = %p\n", copy, &copy, copy);

	return 0;
}

// Output:
// Don't be a fool!
// mesg = Don't be a fool!; &mesg = 0x0012ff48; value = 0x0040a000
// copy = Don't be a fool!; &copy = 0x0012ff44; value = 0x0040a000
