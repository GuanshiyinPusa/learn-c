// WARNING: Use the following cmd to compile and check undefined behavior:
// clang -fsanitize=undefined,address
// INFO: array is composed of a series of elements of one type.
// An array declaration tells the compiler how many elements the array contains
// and what the type is for these elements

// For example:
// int main(void){
// float candy[365];    // array of 365 floats
// }

// ----------------------------------------------------------------------------
// INFO: Const:
// Making a read-oly array:
// const int days[MONTHS] = {31,28,31,30};

// ----------------------------------------------------------------------------
// INFO: Array initialization:
// if the array is uninitialized, it is filled with garbage.

// For example:
// #define SIZE 4
// int no_data[SIZE];
// i    no_data[i]
// 0    0
// 1    4204937
// 2    4219854
// 3    2147348480

// NOTE: If the array is partially initialized, it will fill the rest with 0s.

// For example:
// #define SIZE 4
// int some_data[SIZE] = {1492, 1066}
// i    some_data[i]
// 0    1492
// 1    1066
// 2    0
// 3    0

// ----------------------------------------------------------------------------
// NOTE: If we use empty brackets to initialize an array, the compiler counts
// the number of items in the list and makes the array that large.

/* #include <stdio.h>
int main(void){
	const int days[] = {31,28,31,30,31,30,31,31,30,31};
	int index;

	// Lacking faith in our ability to count correctly, we let the computer give
	// us the size of the array by dividing sizeof(day) by sizeof(day[0])
	for (index = 0; index < sizeof(days) / sizeof(days[0]); index++){
		printf("Month %2d has %d days.\n", index + 1, days[index]);
	}
	return 0;
} */

// ----------------------------------------------------------------------------
// INFO: designated initializers(C99)
// designated initializers allow you to pick and choose which elements are
// intialized

// For example:
// int arr[6] = {0,0,0,0,0,212}; // traditional syntax
// In C99, you can:
// int arr[6] = {[5]} // initialized arr[5] to 212
// #define MONTHS 12
// int days[MONTHS] = {31, 28, [4] = 31, 30, 31, [1] = 29};

// ----------------------------------------------------------------------------
// NOTE: The compiler will make the array big enough to accommodate the
// initialization values.

// For example:
// int stuff[] = {1, [6] = 4, 9, 10};

// ----------------------------------------------------------------------------
// INFO: Array Bounds:
// There is no -1 in array. The array index is only from 0 to (index - 1)

// For example:
// #define SIZE 4
// int main(void){
//      int arr[SIZE];
//      for(i = 0; i < SIZE; i++)
//      ...
// }

// Specifying array size:
// int n = 5;
// int m = 8;
// float a1[5];			   // yes
// float a2[5 * 2 + 1];	   // yes
// float a3[sizeof(int) + 1]; // yes
// float a4[-4];			   // no, size must be >
// float a5[0];			   // no, size must be > 0
// float a6[2.5];			   // no, size must be an integer
// float a7[(int)2.5];		   // yes, typecast float to int constant
// float a8[n];			   // not allowed before C99 -- variable length array
// float a9[m];			   // not allowed before C99 -- variable length array

// ----------------------------------------------------------------------------
// INFO: Multidimensional Arrays
// float rain[5][12];   // array of 5 arrays of 12 floats

// You could omit the interior braces and just retain the two outermost braces.
// If you are short of entries, however, the array is filled sequentially, row
// by row, until the data runs out. Then the remaining elements are initialized
// to 0.

// For example:
// int sq[2][3] = {{5,6}, {7,8}};   // int sq[2][3] = {{5,6,0}, {7,8,0}}
// int sq[2][3] = {5, 6, 7, 8};     // int sq[2][3] = {{5,6,7},{8,0,0}}

// ----------------------------------------------------------------------------
// INFO: Pointers and Arrays:
// the array name is also the address of the first element of the array.
// if flizny is an array, then the following is true.
// flizny == &flizny[0] // name of the array is the address of the first element

// The value of a pointer is the address of the object to which it points.
// Applying the * operator to a pointer yields the object to which the pointer
// Adding 1 to the pointer increases its value by the size, in bytes.

// For example:
// dates + 2 == &dates[2]   // same address
// *(dates + 2) == dates[2] // same value

// NOTE: Don't confuse *(dates + 2) with *dates + 2. The indirection operator *
// binds more tightly then +, so the latter means (*dates) + 2

// For example:
// *(dates + 2) // value of the 3rd element of dates
// *dates + 2   // 2 added to the value of the 1st element

// ----------------------------------------------------------------------------
// INFO: Functions, Arrays, and Pointers:

// For example:
/* int sum(int *ar); // Corresponding prototype

int sum(int *ar) { // corresponding definition
	int i;
	int total = 0;
	for (i = 0; i < 10; i++) // assume 10 elements
		total += ar[i];		 // ar[i] the same as *(ar + i)
	return total;
} */

// HACK: A more common way: Code array size into function

// For example:
/* int sum(int *ar) {
	int i;
	int total = 0;
	// corresponding definition
	for (i = 0; i < 10; i++)
		// assume 10 elements
		total += ar[i];
	// ar[i] the same as *(ar + i)
	return total;
} */

// NOTE: You can substitute int ar[] for int *ar:   int sum(int ar[]);

// NOTE: The following prototypes are equivalent:
// int sum(int *ar, int n);
// int sum(int *, int);
// int sum(int ar[], int n);
// int sum(int [], int);

// NOTE: You can't omit names in function definition, like the following terms:
// int sum(int *ar, int n){}; // OK
// int sum(int ar[], int n){};   // OK

// ----------------------------------------------------------------------------
// NOTE: Using Pointer Parameters:
// You use pointers as the parameters freely like this:
/* sum_arr2.c -- sums the elements of an array */
/* #include <stdio.h>
#define SIZE 10
int sump(int *start, int *end);

int main(void) {
	int marbles[SIZE] = {20, 10, 5, 39, 4, 16, 19, 26, 31, 20};
	long answer;
	answer = sump(marbles, marbles + SIZE);
	printf("The total number of marbles is %ld.\n", answer);
	return 0;
} */

/* use pointer arithmetic */
/* int sump(int *start, int *end) {
	int total = 0;
	while (start < end) {
		total += *start; // add value to total
		start++;		 // advance pointer to next element
	}
	return total;
} */

// INFO: There has been concern that functions that takes in array may change
// the content of array unintentionally. To prevent this, you can use const.
// int sum(const int *start, const int *end);
// NOTE: You don't need to set the array to be const, but the function's const
// will treat the input array as const.

// ----------------------------------------------------------------------------
// INFO: Compound literals:
// Compound literals are a way to create unnamed objects on the fly.

// For example:
// (int [2]){10, 20} // a compound literal

// NOTE: You use compound literal when you make it:

// For example:
// int *pt = (int [2]){10, 20}; // pt points to an array of 2 ints
// int *pt = (int []){10, 20, 30}; // pt points to an array of 3 ints

// int (*pt2)[4];
// declare a pointer to an array of 4-int arrays
// pt2 = (int [2][4]) { {1,2,3,-9}, {4,5,6,-8} };
