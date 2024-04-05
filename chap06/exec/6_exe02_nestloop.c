/*
Use nested loops to produce the following pattern:
$
$$
$$$
$$$$
$$$$$
*/

#include <stdio.h>

int main(void) {
	for (int j = 0; j < 6; j++) {
		for (int i = 0; i < j; i++)
			printf("$");
		printf("\n");
	}
	return 0;
}
