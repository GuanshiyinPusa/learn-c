/* for_down.c */
#include <stdio.h>
int main(void) {
	int secs;
	for (secs = 5; secs > 0; secs--)
		printf("%d seconds!\n", secs);
	printf("We have ignition!\n");
	return 0;
}

// Output:
// 5 seconds!
// 4 seconds!
// 3 seconds!
// 2 seconds!
// 1 seconds!
// We have ignition!
