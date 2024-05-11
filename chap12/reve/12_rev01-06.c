// 1. Which storage classes create variables local to the function containing
// them?
// Automatic and Register
// 2. Which storage classes create variables that persist for the duration of
// the containing program?
// Static external and static internal
// 3. Which storage class creates variables that can be used across several
// files? Restricted to just one file?
// Static external. Static internal is restricted.
// 4. What kind of linkage do block scope variables have?
// No linkage
// 5. What is the extern keyword used for?
// To declare a variable that is defined in another file
//
// 6. Consider this code fragment:
int *p1 = (int *)malloc(100 * sizeof(int));
// In terms of the final outcome, how does the following statement differ?
int *p1 = (int *)calloc(100, sizeof(int));
// calloc initializes each element to zero
