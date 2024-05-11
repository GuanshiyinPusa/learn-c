// Assume this declaration:
// char sign = '$';
// How many bytes of memory does sign use? What about '$'? What about "$"?
#include <stdio.h>
#include <string.h>

int main(void) {
	char sign = '$';
	char *sign2 = "$";
	int n = sizeof(sign);
	int n2 = strlen(sign2);
	printf("%d\n", n);	// char size is 1
	printf("%d\n", n2); // strlen doesn't consider '\0'
	return 0;
}
