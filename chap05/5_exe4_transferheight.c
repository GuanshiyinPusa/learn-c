/*
Write a program that asks the user to enter a height in centimeters and then
displays the height in centimeters and in feet and inches. Fractional
centimeters and inches should be allowed, and the program should allow the user
to continue entering heights until a nonpositive value is entered. A sample run
should look like this: Enter a height in centimeters: 182 182.0 cm = 5
feet, 11.7 inches Enter a height in centimeters (<=0 to quit): 168.7 168.0 cm =
5 feet, 6.4 inches Enter a height in centimeters (<=0 to quit): 0 bye
*/
#include <stdio.h>
#define CM_IN_INCH 2.54
#define INCH_IN_FOOT 12
int main(void) {
	float cm, inch;
	int feet;
	printf("Enter a height in centimeters: ");
	scanf("%f", &cm);
	while (cm > 0) {
		inch = cm / CM_IN_INCH;
		feet = inch / INCH_IN_FOOT;
		inch = inch - feet * INCH_IN_FOOT;
		printf("%.1f cm = %d feet, %.1f inches\n", cm, feet, inch);
		printf("Enter a height in centimeters (<=0 to quit): ");
		scanf("%f", &cm);
	}
	printf("bye\n");
	return 0;
}

// Output:
// Enter a height in centimeters: 165
// 165.0 cm = 5 feet, 5.0 inches
// Enter a height in centimeters (<=0 to quit): 0
// bye
