/* invert4.c -- using bit operations to display binary */
#include <limits.h>
#include <stdio.h>
char *itobs(int, char *);
void show_bstr(const char *);
int invert_end(int num, int bits);

int main(void) {
	char bin_str[CHAR_BIT * sizeof(int) + 1]; // add 1 for null character
	int number;

	puts("Enter integers and see them in binary.");
	puts("Non-numeric input terminates program.");
	while (scanf("%d", &number) == 1) {
		itobs(number, bin_str);
		printf("%d is ", number);
		show_bstr(bin_str);
		putchar('\n');
		number = invert_end(number, 4);
		printf("Inverting the last 4 bits gives\n");
		show_bstr(itobs(number, bin_str));
		putchar('\n');
	}
	puts("Bye!");

	return 0;
}

/**
 * @brief Convert integers to binary string
 *
 * @param n	The integer to convert
 * @param ps A pointer to a char array where the binary string will be stored
 * @return char*
 */
char *itobs(int n, char *ps) {
	int i;
	static const int size = CHAR_BIT * sizeof(int); // size of int in bits

	for (i = size - 1; i >= 0;
		 i--, n >>= 1)			// Step 1: Start with the most significant bit
		ps[i] = (01 & n) + '0'; // Steps 2-3: Check if the current bit is 1 or
								// 0, convert it to ASCII, and store it in ps
	// Step 4: Right shift n by 1 bit (handled in the for loop condition)
	ps[size] = '\0'; // Step 6: Add a null character to the end of the string
	return ps;
}

/* show binary string in block of 4 */
void show_bstr(const char *str) {
	int i = 0;

	while (str[i]) /* not a null character */
	{
		putchar(str[i]);
		// insert a space every four digits
		if (++i % 4 == 0 && str[i])
			putchar(' ');
	}
}

/**
 * @brief Invert the last bits bits of an integer num.
 *
 * @param num
 * @param bits
 * @return int
 */
int invert_end(int num, int bits) {
	int mask = 0;
	int bitval = 1;

	while (bits-- > 0) {
		mask |= bitval; // set bit to 1
		bitval <<= 1;	// shift bitval to the left by 1
	}
	return num ^ mask; // XOR the mask with num
}