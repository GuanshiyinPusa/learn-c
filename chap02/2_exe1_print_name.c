/* print names
 * first print -- print first last name in one line
 * second print -- print first last name in two line
 * third and fourth print -- print first last name in one line
 */

#include <stdio.h>
int main(void) {
	printf("Shuyuan Gao\n");

	printf("Shuyuan\nGao\n");

	printf("Shuyuan");
	printf(" Gao\n");

	return 0;
}

/*
 * Output:
 * Shuyuan Gao
 * Shuyuan
 * Gao
 * Shuyuan Gao
 */
