/* break.c -- uses break to exit a loop */
#include <stdio.h>

int main(void) {
	float length, width;
	printf("Enter the length of the rectangle:\n");
	while (scanf("%f", &length) == 1) {
		printf("Length = %0.2f:\n", length);
		printf("Enter its width:\n");
		if (scanf("%f", &width) != 1)
			break;
		printf("Width = %0.2f:\n", width);
		printf("Area = %0.2f:\n", length * width);
		printf("Enter the length of the rectangle:\n");
	}
	printf("Done.\n");
	return 0;
}

// Output:
// Enter the length of the rectangle:
// 10
// Length = 10.00:
// Enter its width:
// 5
// Width = 5.00:
// Area = 50.00:
// Enter the length of the rectangle:
// a
// Done.
