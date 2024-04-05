// Is anything wrong with this function definition?
#include <stdio.h>

/* void salami(num){
	int num, count;

	for (count = 1; count <= num; num++){
		printf(" 0 Salami mio!\n")
	}
} */

void salami(int num) {
	int count;
	for (count = 1; count <= num; count++) {
		printf(" 0 Salami mio!\n");
	}
}
