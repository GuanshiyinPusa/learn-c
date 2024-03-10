#include <stdio.h>
#define S_TO_M 60
int main(void) {
	int sec, min, left;
	printf("This program converts seconds to minutes and ");
	printf("seconds.\n");
	printf("Just enter the number of seconds.\n");
	printf("Enter 0 to end the program.\n");
	// better solution: scanf("%d", &sec);
	while (sec > 0) {
		scanf("%d", &sec); // better solution: get rid of this, because sec is
						   // not initialized
		min = sec / S_TO_M;
		left = sec % S_TO_M;
		printf("%d sec is %d min, %d sec. \n", sec, min, left);
		printf("Next input?\n");
	}
	printf("Bye!\n");
	return 0;
}
