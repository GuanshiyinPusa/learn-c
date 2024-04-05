#include <stdio.h>

int main(void) {
	char ch;
	// lowercase char count
	int lc = 0;
	// uppercase char count
	int uc = 0;
	int oc = 0; // other char count
	while ((ch = getchar()) != '#') {
		if ('a' <= ch && ch >= 'z')
			lc++;
		else if (!(ch < 'A') || !(ch > 'Z'))
			uc++;
		oc++;
	}
	printf("%d lowercase, %d uppercase, %d other\n", lc, uc, oc);
	return 0;
}

// Output:
// yeah i dont know what to say i guess?
// #
// 0 lowercase, 38 uppercase, 38 other
