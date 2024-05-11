// where.c -- where's the memory?

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int static_store = 30;
const char *pcg = "String Literal";

int main(void) {
	int auto_store = 40;
	char auto_string[] = "Auto char Array";
	int *pi;
	char *pcl;

	pi = (int *)malloc(sizeof(int));
	*pi = 35;
	pcl = (char *)malloc(strlen("Dynamic String") + 1);
	strcpy(pcl, "Dynamic String");

	printf("static_store: %d at %p\n", static_store, &static_store);
	printf("  auto_store: %d at %p\n", auto_store, &auto_store);
	printf("         *pi: %d at %p\n", *pi, pi);
	printf("  %s at %p\n", pcg, pcg);
	printf(" %s at %p\n", auto_string, auto_string);
	printf("  %s at %p\n", pcl, pcl);
	printf("   %s at %p\n", "Quoted String", "Quoted String");
	free(pi);
	free(pcl);
	return 0;
}

// Output:
// static_store: 30 at 0x5c053a754030
//   auto_store: 40 at 0x7ffe97ca05ec
//          *pi: 35 at 0x5c053b7192a0
//   String Literal at 0x5c053a752004
//  Auto char Array at 0x7ffe97ca0600
//   Dynamic String at 0x5c053b7192c0
//    Quoted String at 0x5c053a752072
