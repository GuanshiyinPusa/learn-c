// Device a function chline(ch, i, j) that prints the requested character in
// columns i through j. Test it in a simple driver.

#include <stdio.h>
void chline(char, int, int);

void chline(char ch, int i, int j) {
	for (int k = 0; k < i; k++) {
		putchar(' ');
	}
	for (int k = i; k <= j; k++) {
		putchar(ch);
	}
	putchar('\n');
}

int main(void) {
	chline('a', 1, 5);
	chline('b', 2, 6);
	chline('c', 3, 7);
	chline('d', 4, 8);
	chline('e', 5, 9);
	return 0;
}
