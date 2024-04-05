// min_sec.c -- converts seconds to minutes and seconds
#include <stdio.h>
#define SEC_PER_MIN 60

// seconds in a minute
int main(void) {
	int sec, min, left;
	printf("Convert seconds to minutes and seconds!\n");
	printf("Enter the number of seconds (<=0 to quit):\n");
	scanf("%d", &sec);
	// read number of seconds
	while (sec > 0) {
		min = sec / SEC_PER_MIN;  // truncated number of minutes
		left = sec % SEC_PER_MIN; // number of seconds left over
		printf("%d seconds is %d minutes, %d seconds.\n", sec, min, left);
		printf("Enter next value (<=0 to quit):\n");
		scanf("%d", &sec);
	}
	printf("Done!\n");
	return 0;
}

// Output:
/*
Enter the number of seconds (<=0 to quit):
100
100 seconds is 1 minutes, 40 seconds.
Enter next value (<=0 to quit):
120
120 seconds is 2 minutes, 0 seconds.
Enter next value (<=0 to quit):
300
300 seconds is 5 minutes, 0 seconds.
Enter next value (<=0 to quit):
340
340 seconds is 5 minutes, 40 seconds.
Enter next value (<=0 to quit):
-10
Done!
*/
