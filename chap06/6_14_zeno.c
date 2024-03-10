/* zeno.c -- series sum */
#include <stdio.h>
int main(void) {
	int t_ct;
	// term count
	double time, power_of_2;
	int limit;
	printf("Enter the number of terms you want: ");
	scanf("%d", &limit);
	for (time = 0, power_of_2 = 1, t_ct = 1; t_ct <= limit;
		 t_ct++, power_of_2 *= 2.0) {
		time += 1.0 / power_of_2;
		printf("time = %f when terms = %d.\n", time, t_ct);
	}
	return 0;
}

/* Enter the number of terms you want: 100
time = 1.000000 when terms = 1.
time = 1.500000 when terms = 2.
time = 1.750000 when terms = 3.
time = 1.875000 when terms = 4.
time = 1.937500 when terms = 5.
time = 1.968750 when terms = 6.
time = 1.984375 when terms = 7.
time = 1.992188 when terms = 8.
time = 1.996094 when terms = 9.
time = 1.998047 when terms = 10.
time = 1.999023 when terms = 11.
time = 1.999512 when terms = 12.
time = 1.999756 when terms = 13.
time = 1.999878 when terms = 14.
time = 1.999939 when terms = 15.
time = 1.999969 when terms = 16.
time = 1.999985 when terms = 17.
time = 1.999992 when terms = 18.
time = 1.999996 when terms = 19.
time = 1.999998 when terms = 20.
time = 1.999999 when terms = 21.
time = 2.000000 when terms = 22. */
