#include <stdio.h>
#define SIZE 8

int main(void) {
	int by_twos[SIZE]; // int array size 8
	int index;
	for (index = 0; index <= SIZE; index++)
		// for (index = 1; index <= SIZE; index++) // index 1 - 8
		by_twos[index] = 2 * index; // index out of bound, because size 0 - 7
	for (index = 0; index <= SIZE; index++)
		// for (index = 1; index <= SIZE; index++)
		printf("%d ", by_twos[index]); // print the elements of by_twos
	printf("\n");
	return 0;
}
