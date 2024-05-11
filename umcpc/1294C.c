/* https://codeforces.com/problemset/problem/1294/C */
#include <stdio.h>

int find_divisor(int num, int start);
void find_three_distinct(int number);

int main(void) {
	int n;
	scanf("%d", &n);
	find_three_distinct(n);
	return 0;
}

void find_three_distinct(int number) {
	int divisor = find_divisor(number, 1);
	if (divisor < 2) {
		printf("NO\n");
	} else {
		int quotient = number / divisor;
		int divisor2 = find_divisor(quotient, divisor);
		if (divisor2 < 2) {
			printf("NO\n");
		} else {
			int quotient2 = quotient / divisor2;
			if (quotient2 < 2 || quotient2 == divisor2) {
				printf("NO\n");
			} else {
				printf("YES\n");
				printf("Divisors: %d, %d, %d\n", divisor, divisor2, quotient2);
			}
		}
	}
}

int find_divisor(int num, int start) {
	if (num <= 1) {
		return 0;
	}
	for (int i = start + 1; i * i <= num; i++) {
		if (num % i == 0) {
			return i;
		}
	}
	return 0;
}
