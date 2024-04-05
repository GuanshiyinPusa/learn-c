/* Generalize the to_binary() function of Listing 9.8 to a to_base_n() function
that takes a second argument in the range 2–10. It then should print the number
that is its first argument to the number base given by the second argument. For
example, to_ base_n(129,8) would display 201, the base-8 equivalent of 129. Test
the function in a complete program.*/
#include <stdio.h>

void to_base_n(unsigned long n, int base); // Function prototype

int main(void) {
	unsigned long number;
	int base;

	printf(
		"Enter an integer and the base (2-10) for conversion (q to quit):\n");
	while (scanf("%lu %d", &number, &base) == 2) {
		if (base < 2 || base > 10) {
			printf("Base must be between 2 and 10. Try again.\n");
			continue; // Skip the rest of the loop if base is out of range
		}
		printf("Equivalent in base %d: ", base);
		to_base_n(number, base);
		putchar('\n');
		printf("Enter another integer and base (q to quit):\n");
	}
	printf("Done.\n");
	return 0;
}

void to_base_n(unsigned long n, int base) {
	int r;
	r = n % base; // Use the base for modulus
	if (n >= (unsigned long)base) {
		to_base_n(n / base, base); // Recursive call with base
	}
	putchar('0' + r); // Convert digit to character and print
}
