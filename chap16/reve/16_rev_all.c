// 1. a.dist = 5280 * miles;
// is valid.b.plort = 4 * 4 + 4;
// is valid.But if the user really wanted 4 * (4 + 4),
// 	he or she should have used #define POD(FEET + FEET).c.nex = = 6;
// ; is invalid. (If there were no space between the two equal signs, it
// would be valid but useless.) Apparently, the user forgot that he or she was
// writing for the preprocessor, not writing in C.
//  d. y = y + 5;
// is valid.berg = berg + 5 * lob;
// is valid, but this is probably not the desired result.est = berg + 5 / y + 5;
// is valid, but this is probably not the desired result.nilp = lob * -berg + 5;
// is valid, but this is probably not the desired result.
// 2.
#define NEW(X) ((X) + 5)3. #define
MIN(X, Y)
((X) < (Y) ? (X) : (Y)) 4. #define
	EVEN_GT(X, Y)((X) > (Y) && (X) % 2 == 0 ? 1 : 0) 5. #define PR(X, Y)
		printf(#X " is %d and " #Y " is %d\n", X, Y)
//  Because X and Y are never exposed to any other operations (such as
//  multiplication) in this macro, you don’t have to cocoon everything in
//  parentheses.
//  6. a. #define QUARTERCENTURY 25
//  b. #define SPACE ' '
//  c. #define PS() putchar(' ')
//  or
// #define PS() putchar(SPACE)
//  d. #define BIG(X) ((X) + 3)
//  e. #define SUMSQ(X,Y) ((X)*(X) + (Y)*(Y))
// 7. Try this:
#define P(X) printf("name: " #X "; value: %d; address: %p\n", X, &X)
/*  Or, if your implementation doesn’t recognize the %p specification for the
 * address, try %u or %lu . */
// 8. Use the conditional compilation directives. One way is to use #ifndef :
#define _SKIP_ /* remove when you don't want to skip code */
#ifndef _SKIP_
/* code to be skipped */
#endif
// 9.
#ifdef PR_DATE
			printf("Date = %s\n", _ _DATE_ _);
#endif
// 10. One version returns the value x *
// 	x.This just returns the type double value of the square.For example,
// 	square(1.3) would return 1.69. The second version returns(int)(x * x)
// 		.This truncates the result to an int.Then,
// 	because the return type is double,
// 	the int value is promoted to a
// 	double value.So 1.69 would be converted first to 1 then to
// 	1.00 .The final version returns(int)(x *x + 0.5)
// 		.Adding
// 	0.5 makes the function round to the nearest whole number instead of
// 	truncating.So 1.69 becomes 2.19,
// 	which is truncated to 2 and then converted to 2.00. But 1.44 becomes 1.94,
// 	which is truncated to 1 and then converted to 1.00 .
// 11. Here’s one possibility:
#define BOOL(X) _Generic((X), _Bool: "boolean", default: "not boolean")
/* 12. The argv argument should be declared as type char *argv[]. Command-line
arguments are stored as strings, so the program should first convert the string
in argv[1] to a type double value—for example, by using atof() from the stdlib.h
library. The math.h header file should be included for the sqrt() function. The
program should check for negative values before taking a square root. */
//  13. a. The function call should look like this:
qsort((void *)scores, (size_t)1000, sizeof(double), comp);

//  b. Here’s a suitable comparison function:
int comp(const void *p1, const void *p2) {
	/* need to use pointers to int to access values */
	/* the type casts are optional in C, required in C++ */
	const int *a1 = (const int *)p1;
	const int *a2 = (const int *)p2;
	if (*a1 > *a2)
		return -1;
	else if (*a1 == *a2)
		return 0;
	else
		return 1;
}

//   14. a. The function call should look like this:
memcpy(data1, data2, 100 * sizeof(double));
//  b. The function call should look like this:
memcpy(data1, data2 + 200, 100 * sizeof(double));