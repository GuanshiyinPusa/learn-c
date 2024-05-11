/* https://codeforces.com/problemset/problem/1526/B */
#include <stdio.h>

int main(void) {
	int n;
	scanf("%d", &n);

	if (n % 11 * 111 > n)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}
