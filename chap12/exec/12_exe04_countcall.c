// Write and test in a loop a function that returns the number of times it has
// been called.
#include <stdio.h>

int count_call(void) {
	static int count = 0;
	return ++count;
}

int main() {
	for (int i = 0; i < 5; i++) {
		printf("Function called %d times.\n", count_call());
	}
	return 0;
}
