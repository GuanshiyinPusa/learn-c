#include <stdio.h>

// Block Scope -- can be used for, while, do while, if
double blocky(double cleo) {
	double patrick = 0.0;
	// ...
	return patrick;
}

// Or q in this example -- inner block
double blocky(double cleo) {
	double patrick = 0.0;
	int i;
	for (i = 0; i < 10; i++) { // inner block
		double q = cleo * i;   // start of scope for q
							   // ...
		patrick *= q;		   // end of scope for q
	}
	// ...
	return patrick;
}

// function scope
int mighty(int mouse, double large);

// file scope (global variables) -- is visible till end of the file
int units = 0; // a variable with file scope, can be used in main, critic
void critic(void);

int main(void) {
	// ...
}

void critic(void) {
	// ...
}

// Linkage
// There are three types of linkage: external, internal, and none.
// Block scope, function scope and function prototype scope have no linkage.
// A variable with file scope can have either internal or external linkage.

// static

// can be used by other file
int giants = 5; // file scope, external linkage
// private to this particular file
static int dodgers = 3; // file scope, internal linkage

int main() {
	// ...
}

// ...

// Storage duration
// A C object has one of the following four storage durations: static storage
// duration, thread storage duration, automatic storage duration, or allocated
// storage duration.

// static storage duration -- file scope, till the end of the program

// thread storage duration -- concurrent programming, till the end of the thread

// automatic storage duration --
// block scope, memory allocated when program enters the block and freed when
// the block is exited.

// ### VLA provide a slight exception in that they exist from the point of
// declaration to the end of the block rather than from the beginning of the
// block to the end.

// automatic storage example:
void bore(int number) { // number and index have block scope
						// they come into existence when the function is called
						// and disappear when the function ends
	int index;
	for (index = 0; index < number; index++)
		puts("They don't make them the way they used to.\n");
	return 0;
}

// static storage duration
void more(int number) {
	int index;
	static int ct = 0; // static storage duration
					   // ct is initialized only once, allocated at the start of
					   // the program. retain its value between function calls
	// ...
	return 0;
}

// Storage class    Duration    Scope    Linkage    How declared
// automatic        Automatic   Block    None       In a block
// register         Automatic   Block    None       In a block with "register"
// static external  Static      File     External   Outside of all functions
// static internal  Static      File     Internal   Outside with "static"
// static none      Static      Block    None       In a block with "static"

// Auto - storage class specifier
// The auto keyword is rarely used in C programs. It is the default storage
// class
int main(void) { auto int plox; }

int loop(int n) {
	int m; // m in scope
	scanf("%d", &m);
	{
		int i; // both m and i in scope
		for (i = m; i < n; i++)
			puts("i is local to a sub-block\n");
	}
	return m; // m in scope, i gone
}

// register -- fastest, but can't take its address

// static -- static means variable stays put in the memory.
// not allowed as function parameters:
// int wontwork(static int flu); // not allowed

// A static variable with external linkage has file scope, external linkage, and
// static storage duration.This class is sometimes termed the external storage
// class, and variables of this type are called external variables.
int Errupt;		  /* externally defined variable */
double Up[100];	  /* externally defined array */
extern char Coal; /* mandatory declaration if */
				  /* Coal defined in another file*/
void next(void);

int main(void) {
	extern int Errupt;	/* optional declaration */
	extern double Up[]; /* optional declaration */
						// ...
}

void next(void) {
	// ...
}

// Like automatic variables, external variables can be initialized explicitly.
// Unlike automatic vari- ables, external variables are initialized
// automatically to zero if you don’t initialize them. This rule applies to
// elements of an externally defined array, too. Unlike the case for automatic
// vari- ables, you can use only constant expressions to initialize file scope
// variables:
int x = 10;				// ok, 10 is constant
int y = 3 + 20;			// ok, a constant expression
size_t z = sizeof(int); // ok, a constant expression
int x2 = 2 * x;			// not ok, x is a variable

// Definition and declarations
int tern = 1; /* tern defined -- defining declaration*/

main() {
	external int tern; /* use a tern defined elsewhere referencing declaration*/
}

// Use extern to refer it not define it. wont be useful if u have extern
// outside

// external internal linkage:
int traveler = 1;		 // external linkage
static int stayhome = 1; // internal linkage

int main() {
	extern int traveler; // use global traveler
	extern int stayhome; // use global stayhome
						 // ...
}

// INFO:
// Automatic variables have block scope, no linking, and automatic storage
// duration. They are local and private to the block (typically a function) in
// which they are defined. Register variables have the same properties as
// automatic variables, but the compiler may use faster memory or a register to
// store them. You can’t take the address of a register variable.

// INFO:
// Variables with static storage duration can have external linkage, internal
// linkage, or no linkage. When a variable is declared external to any function
// in a file, it’s an external variable and has file scope, external linkage,
// and static storage duration. If you add the keyword static to such a
// declaration, you get a variable with static storage duration, file scope, and
// internal linkage. If you declare a variable inside a function and use the
// keyword static, the variable has static storage duration, block scope, and no
// linkage.

// INFO:
// Memory for a variable with automatic storage duration is allocated when
// program execution enters the block containing the variable declaration and is
// freed when the block is exited. If uninitialized, such a variable has a
// garbage value. Memory for a variable with static storage duration is
// allocated at compile time and lasts as long as the program runs. If
// uninitialized, such a variable is set to 0.

// INFO:
// A variable with block scope is local to the block containing the declaration.
// A variable with file scope is known to all functions in a file (or
// translation unit) following its declaration. If a file scope variable has
// external linkage, it can be used by other translation units in the program.
// If a file scope variable has internal linkage, it can be used just within the
// file in which it is declared.

// If your C implementation gives you access to some changing quantity, such as
// the system clock, you can use that value (possibly truncated) to initialize
// the seed value. For instance, ANSI C has a time() function that returns the
// system time. The time units are system depen- dent, but what matters here is
// that the return value is an arithmetic type and that its value changes with
// time. The exact type is system dependent and is given the label time_t, but
// you can use a type cast. Here’s the basic setup:

#include <time.h>			   /* ANSI prototype for time() */
srand1((unsigned int)time(0)); /* initialize seed */
// In general, time() takes an argument that is the address of a type time_t
// object. In that case, the time value is also stored at that address. However,
// you can pass the null pointer (0) as an argument, in which case the value is
// supplied only through the return value mechanism.

// Roll em
// Take random number mod 5 then add 1 to get range 1-6
#include <stdlib.h> /* for rand() */

int rollem(int sides) {
	int roll;
	roll = rand() % sides + 1;
	return roll;
}

// malloc
// watch out memory leak by not using free().
void gobble(double ar[], int n) {
	double *temp = (double *)malloc(n * sizeof(double));
	// ...
	/* free(temp); // forgot to use free() */
}

// temp disappears when the function terminates, but the memory it pointed still
// existed.

// calloc
long *newmem;
newmem = (long *)calloc(100, sizeof(long));

// calloc sets every bits in block to zero, so slower than malloc. It is handy
// when it comes to data structures.

// Dynamic memory allocation and variable-length array
int vlamal() {
	int n;
	int *pi;
	scanf("%d", &n);
	pi = (int *)malloc(n * sizeof(int));
	int ar[n]; // vla
	pi[2] = ar[2] = -5;
	// ...
}

// NOTE: VLA is automatic storage. VLA is freed when leaving the function block.
// so No need to use free(). malloc's array can be used outside the function
// block, by returning the pointer.
// VLAs are more convenient for multidimensional arrays. You can create a
// two-dimensional array using malloc(), but the syntax is awkward. If a
// compiler doesn’t support the VLA feature, one of the dimensions has to be
// fixed, just like in function calls:
int n = 5;
int m = 6;
int ar2[n][m];								  // n x m VLA
int (*p2)[6];								  // works pre-C99
int (*p3)[m];								  // requires VLA support
p2 = (int (*)[6])malloc(n * 6 * sizeof(int)); // n * 6 array
p3 = (int (*)[m])malloc(n * m * sizeof(int)); // n * m array
// above expression also requires VLA support
ar2[1][2] = p2[1][2] = 12;

// Using const with Global data
// One area that requires care, however, is sharing const data across files.
//
// First strategy:
// The first is to follow the usual rules for external variables—use defining
// declarations in one file and reference declarations (using the keyword
// extern) in the other files

/* file1.c -- defines some global constants */
const double PI = 3.14159;
const char *MONTHS[12] = {"January",   "February", "March",	   "April",
						  "May",	   "June",	   "July",	   "August",
						  "September", "October",  "November", "December"};
/* file2.c -- use global constants defined elsewhere */
extern const double PI;
extern const *MONTHS[];

// The second approach is to place the constants in an include file. Here, you
// must take the addi- tional step of using the static external storage class:
/* constant.h -- defines some global constants */
static const double PI = 3.14159;
static const char *MONTHS[12] = {
	"January", "February", "March",		"April",   "May",	   "June",
	"July",	   "August",   "September", "October", "November", "December"};
/* file1.c -- use global constants defined elsewhere */
#include "constant.h"
/* file2.c -- use global constants defined elsewhere */
#include "constant.h"

// The following are C’s five storage classes (excluding thread concepts):
// ■Automatic—A variable declared in a block (or as a parameter in a function
// header) with no storage class modifier, or with the auto storage class
// modifier, belongs to the automatic storage class. It has automatic storage
// duration, block scope, and no linkage. Its value, if uninitialized, is not
// undetermined.
// ■Register—A variable declared in a block (or as a parameter in
// a function header) with the register storage class modifier belongs to the
// register storage class. It has automatic storage duration, block scope, and
// no linkage, and its address cannot be taken. Declaring a variable as a
// register variable is a hint to the compiler to provide the fastest access
// possible. Its value, if uninitialized, is not undetermined.
// ■Static, no linkage—A variable declared in a block with the static storage
// class modifier belongs to the “static, no linkage” storage class. It has
// static storage duration, block scope, and no linkage. It is initialized just
// once, at compile time. If not initialized explicitly, its bytes are set to 0.
// ■Static, external linkage—A variable defined external to any function and
// without using the static storage class modifier belongs to the “static,
// external linkage” storage class. It has static storage duration, file scope,
// and external linkage. It is initialized just once, at compile time. If not
// initialized explicitly, its bytes are set to 0.
// ■Static, internal linkage—A
// variable defined external to any function and using the static storage class
// modifier belongs to the “static, internal linkage” storage class. It has
// static storage duration, file scope, and internal linkage. It is initialized
// just once, at compile time. If not initialized explicitly, its bytes are set
// to 0.
