/* wheat.c -- exponential growth */
#include <stdio.h>
#define SQUARES 64 // squares on a checkerboard
int main(void) {
	const double CROP = 2E16; // world wheat production in wheat grains
	double current, total;
	int count = 1;

	printf("square     grains       total ");
	printf("fraction of \n");
	printf("           added        grains ");
	printf("world total\n");
	total = current = 1.0; /* start with one grain */
	printf("%4d %13.2e %12.2e %12.2e\n", count, current, total, total / CROP);
	while (count < SQUARES) {
		count = count + 1;
		current = 2.0 * current;
		/* double grains on next square */
		total = total + current; /* update total */
		printf("%4d %13.2e %12.2e %12.2e\n", count, current, total,
			   total / CROP);
	}
	printf("That's all.\n");
	return 0;
}

// Output:
/*
square     grains       total fraction of
		   added        grains world total
   1      1.00e+00     1.00e+00     5.00e-17
   2      2.00e+00     3.00e+00     1.50e-16
   3      4.00e+00     7.00e+00     3.50e-16
   4      8.00e+00     1.50e+01     7.50e-16
   5      1.60e+01     3.10e+01     1.55e-15
   6      3.20e+01     6.30e+01     3.15e-15
   7      6.40e+01     1.27e+02     6.35e-15
   8      1.28e+02     2.55e+02     1.27e-14
   9      2.56e+02     5.11e+02     2.55e-14
  10      5.12e+02     1.02e+03     5.12e-14
  11      1.02e+03     2.05e+03     1.02e-13
  12      2.05e+03     4.10e+03     2.05e-13
  13      4.10e+03     8.19e+03     4.10e-13
  14      8.19e+03     1.64e+04     8.19e-13
  15      1.64e+04     3.28e+04     1.64e-12
  16      3.28e+04     6.55e+04     3.28e-12
  17      6.55e+04     1.31e+05     6.55e-12
  18      1.31e+05     2.62e+05     1.31e-11
  19      2.62e+05     5.24e+05     2.62e-11
  20      5.24e+05     1.05e+06     5.24e-11
  21      1.05e+06     2.10e+06     1.05e-10
  22      2.10e+06     4.19e+06     2.10e-10
  23      4.19e+06     8.39e+06     4.19e-10
  24      8.39e+06     1.68e+07     8.39e-10
  25      1.68e+07     3.36e+07     1.68e-09
  26      3.36e+07     6.71e+07     3.36e-09
  27      6.71e+07     1.34e+08     6.71e-09
  28      1.34e+08     2.68e+08     1.34e-08
  29      2.68e+08     5.37e+08     2.68e-08
  30      5.37e+08     1.07e+09     5.37e-08
  31      1.07e+09     2.15e+09     1.07e-07
  32      2.15e+09     4.29e+09     2.15e-07
  33      4.29e+09     8.59e+09     4.29e-07
  34      8.59e+09     1.72e+10     8.59e-07
  35      1.72e+10     3.44e+10     1.72e-06
  36      3.44e+10     6.87e+10     3.44e-06
  37      6.87e+10     1.37e+11     6.87e-06
  38      1.37e+11     2.75e+11     1.37e-05
  39      2.75e+11     5.50e+11     2.75e-05
  40      5.50e+11     1.10e+12     5.50e-05
  41      1.10e+12     2.20e+12     1.10e-04
  42      2.20e+12     4.40e+12     2.20e-04
  43      4.40e+12     8.80e+12     4.40e-04
  44      8.80e+12     1.76e+13     8.80e-04
  45      1.76e+13     3.52e+13     1.76e-03
  46      3.52e+13     7.04e+13     3.52e-03
  47      7.04e+13     1.41e+14     7.04e-03
  48      1.41e+14     2.81e+14     1.41e-02
  49      2.81e+14     5.63e+14     2.81e-02
  50      5.63e+14     1.13e+15     5.63e-02
  51      1.13e+15     2.25e+15     1.13e-01
  52      2.25e+15     4.50e+15     2.25e-01
  53      4.50e+15     9.01e+15     4.50e-01
  54      9.01e+15     1.80e+16     9.01e-01
  55      1.80e+16     3.60e+16     1.80e+00
  56      3.60e+16     7.21e+16     3.60e+00
  57      7.21e+16     1.44e+17     7.21e+00
  58      1.44e+17     2.88e+17     1.44e+01
  59      2.88e+17     5.76e+17     2.88e+01
  60      5.76e+17     1.15e+18     5.76e+01
  61      1.15e+18     2.31e+18     1.15e+02
  62      2.31e+18     4.61e+18     2.31e+02
  63      4.61e+18     9.22e+18     4.61e+02
  64      9.22e+18     1.84e+19     9.22e+02
That's all.
*/
