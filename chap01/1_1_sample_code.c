#include <stdio.h>

int main(void) {
	int dogs;

	printf("How many dogs do you have?\n");
	scanf("%d", &dogs);
	printf("So you have %d dog(s)!\n", dogs);

	return 0;
}

/*
 * Output:
 * How many dogs do you have?
 * 3
 * So you have 3 dog(s)!
 */
