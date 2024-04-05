/* p_and_s.c -- pointers and strings */
#include <stdio.h>
int main(void) {
	const char *mesg = "Don't be a fool!";
	const char *copy;
	copy = mesg;
	printf("%s\n", copy);
	printf("mesg = %s; &mesg = %p; value = %p\n", mesg, &mesg, mesg);
	printf("copy = %s; &copy = %p; value = %p\n", copy, &copy, copy);
	return 0;
}

// Output:
// Don't be a fool!
// mesg = Don't be a fool!; &mesg = 0x7ffcfb5a4938; value = 0x569f7c443008
// copy = Don't be a fool!; &copy = 0x7ffcfb5a4940; value = 0x569f7c443008
