/* https://codeforces.com/problemset/problem/1679/A */
#include <stdio.h>

int main(void) {
	long long int wheels;
	scanf("%lld", &wheels);

	long long int smallest;
	long long int largest;

	smallest = wheels / 24 * 6 + (wheels % 24) / 4;
	largest = wheels / 4;

	printf("The smallest number of buses is %lld\n", smallest);
	printf("The largest number of buses is %lld\n", largest);

	return 0;
}
