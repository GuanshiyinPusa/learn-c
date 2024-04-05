void alter(int *x, int *y) {
	int sum = *x + *y;
	int difference = *x - *y;
	*x = sum;
	*y = difference;
}

void alter1(int *pa, int *pb) {
	int temp;
	temp = *pa + *pb;
	*pb = *pa - *pb;
	*pa = temp;
}

void alter2(int *pa, int *pb) {
	*pa += *pb;
	*pb = *pa - 2 * *pb;
}
