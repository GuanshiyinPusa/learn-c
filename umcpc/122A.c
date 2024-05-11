/* https://codeforces.com/problemset/problem/122/A */
#include <stdio.h>
#define LIM 14

int main(void) {
	int array[14] = {
		4, 7, 44, 47, 74, 77, 444, 447, 474, 477, 744, 747, 774, 777,
	};
	int input;
	scanf("%d", &input);
	for (int i = 0; i < LIM; i++) {
		if (!(input % array[i])) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
