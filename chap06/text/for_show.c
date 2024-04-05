/* for_show.c */
#include <stdio.h>

int main(void) {
	int num = 0;

	for (printf("Keep entering numbers!\n"); num != 6;)
		scanf("%d", &num);
	printf("That's the one I want!\n");
	return 0;
}

// Output:
// Keep entering numbers!
// 1
// 2
// 3
// 4
// 5
// 5
// 6
// That's the one I want!
