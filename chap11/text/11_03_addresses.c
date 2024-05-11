// addresses.c -- addresses of strings
#define MSG "I'm special"
#include <stdio.h>

int main() {
	char ar[] = MSG;
	const char *pt = MSG;
	printf("address of \"I'm special\":%p\n", "I'm special");
	printf("              address ar:%p\n", ar);
	printf("              address pt:%p\n", pt);
	printf("          address of MSG:%p\n", MSG);
	printf("address of \"I'm special\":%p\n", "I'm special");

	return 0;
}

// Output:
// address of "I'm special":0x64de42dfa004
//               address ar:0x7ffc0fce1dc8
//               address pt:0x64de42dfa004
//           address of MSG:0x64de42dfa004
// address of "I'm special":0x64de42dfa004
