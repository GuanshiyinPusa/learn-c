// The align.c Program align.c-- using _Alignof and _Alignas(C11)
#include <stdio.h>

int main(void) {
	double dx;
	char ca;
	char cx;
	double dz;
	char cb;
	char _Alignas(double) cz;
	printf("char alignment: %zd\n", _Alignof(char));
	printf("double alignment: %zd\n", _Alignof(double));
	printf("&dx: %p\n", &dx);
	printf("&ca: %p\n", &ca);
	printf("&cx: %p\n", &cx);
	printf("&dz: %p\n", &dz);
	printf("&cb: %p\n", &cb);
	printf("&cz: %p\n", &cz);
	return 0;
}

// char alignment: 1
// double alignment: 8
// &dx: 0x7ffe217f0ef8
// &ca: 0x7ffe217f0ef5
// &cx: 0x7ffe217f0ef6
// &dz: 0x7ffe217f0f00
// &cb: 0x7ffe217f0ef7
// &cz: 0x7ffe217f0ef0
