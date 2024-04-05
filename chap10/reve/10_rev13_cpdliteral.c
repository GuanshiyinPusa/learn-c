/* Here are two function prototypes:
void show(const double ar[], int n);        // n is number of elements
void show2(const double ar2[][3], int n);   // n is number of rows
a. Show a function call that passes a compound literal containing the values 8,
3, 9, and 2 to the show() function.
b. Show a function call that passes a
compound literal containing the values 8, 3, and 9 as the first row and the
values 5, 4, and 1 as the second row to the show2() function. */

void show(const double ar[], int n);	  // n is number of elements
void show2(const double ar2[][3], int n); // n is number of rows

int main(void) {
	show((double[4]){8, 3, 9, 2}, 4);
	show2((double[][3]){{8, 3, 9}, {5, 4, 1}}, 2);
}
