/* A file begins with the following declarations: */
static int plink;
int value_ct(const int arr[], int value, int n);
// a. What do these declarations tell you about the programmer’s intent?
// b. Will replacing int value and int n with const int value and const int n
// enhance the protection of values in the calling program?

// a. It tells you that the program will use the variable plink, which is local
// to the file containing the function. The first argument to value_ct() is a
// pointer to an integer, presumably the first element of an array of n members.
// The important point here is that the program will not be allowed to use the
// pointer arr to modify values in the original array.
//  b. No. Already, value and n are copies of original data, so there is no way
//  for the
// function to alter the corresponding values in the calling program. What these
// declarations do accomplish is to prevent the function from altering value and
// n within the function. For example, the function couldn’t use the expression
// n++ if n were qualified as const .
