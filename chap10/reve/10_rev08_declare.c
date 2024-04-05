// a. Declare an array of six ints and initialize it to the values 1, 2, 4, 8,
// 16, and 32.
int array1[6] = {1, 2, 4, 8, 16, 32};
// b. Use array notation to represent the third element (the one
// with the value 4) of the array in part a.
int array2[6] = {1, 2, [2] = 4, 8, 16, 32};
// c. Assuming C99/C11 rules are in effect, declare an array of 100 ints and
// initialize it so that the last element is -1; don’t worry about the other
// elements.
int array3[100] = {[99] = -1};
// d. Assuming C99/C11 rules are in effect, declare an array of 100
// ints and initialize it so that elements 5, 10, 11, 12, and 13 are 101; don’t
// worry about the other elements.
int array4[100] = {[5] = 101, [10] = 101, 101, 101, 101};
