/* What will this program print? */
#include <stdio.h>

int main(void) {
	char str1[] = "gawsie"; // plump and cheerful
	char str2[] = "bletonism";

	char *ps;
	int i = 0;
	// ps points to str1, ps increment until it reaches '\0' the end
	for (ps = str1; *ps != '\0'; ps++) {
		if (*ps == 'a' || *ps == 'e') // if ps points to a or e, print it.
			putchar(*ps);
		else
			(*ps)--;
		putchar(*ps); // faavrhee
	}
	putchar('\n');
	while (str2[i] != '\0') {
		printf("%c", i % 3 ? str2[i] : '*'); // *le*on*sm
		++i;
	}
	return 0;
}

// Output:
// faavrhee
// *le*on*sm
