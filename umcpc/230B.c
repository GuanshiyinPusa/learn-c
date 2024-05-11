/* https://codeforces.com/problemset/problem/230/B */
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
bool check_prime(int n);
bool check_prime_square(int n);

int main(void) {
	int n;
	scanf("%d", &n);
	if (check_prime_square(n)) {
		printf("YES\n");
		return 0;
	}
}

bool check_prime_square(int n) { return check_prime(sqrt(n)); }

bool check_prime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}
