/*
Write a program that reads integers until 0 is entered. After input terminates,
the program should report the total number of even integers (excluding the 0)
entered, the average value of the even integers, the total number of odd
integers entered, and the average value of the odd integers.
*/

#include <stdio.h>

int main(void) {
	int n_even = 0;
	int n_odd = 0;
	int sum_even = 0;
	int sum_odd = 0;
	int n;
	while (scanf("%d", &n) == 1 && n != 0) {
		if (n % 2 == 0) {
			n_even++;
			sum_even += n;
		} else {
			n_odd++;
			sum_odd += n;
		}
	}
	printf("number of even integers: %d\n", n_even);
	printf("average value of even integers: %.2f\n", (float)sum_even / n_even);
	printf("number of odd integers: %d\n", n_odd);
	printf("average value of odd integers: %.2f\n", (float)sum_odd / n_odd);
	return 0;
}

// Output:
// 1 2 3 4 5 6 7 8 9 0
// number of even integers: 4
// average value of even integers: 5.00
// number of odd integers: 5
// average value of odd integers: 5.00
