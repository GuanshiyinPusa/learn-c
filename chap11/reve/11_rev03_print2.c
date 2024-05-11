/* print string backwards */
#include <stdio.h>
// #include <string.h>
void print_backwards(const char *ptr);

int main(void) {
	char food[] = "Yummy";
	// char *ptr;
	//
	// ptr = food + strlen(food); // ptr = food + 5, pointing to '\0'
	// while (--ptr >= food) {
	// 	puts(ptr);
	// }
	print_backwards(food);
	return 0;
}

void print_backwards(const char *ptr) {
	const char *str = ptr;
	while (*ptr != '\0')
		ptr++;
	while (--ptr >= str)
		puts(ptr);
}
