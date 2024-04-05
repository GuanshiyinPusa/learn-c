// Here are three array declarations:
// double trots[20];
// short clops[10][30];
// long shots[5][10][15];
// a. Show a function prototype and a function call for a traditional void
// function that processes trots and also for a C function using a VLA.
// b. Show a function prototype and a function call for a traditional void
// function that processes clops and also for a C function using a VLA. c. Show
// a function prototype and a function call for a traditional void function that
// processes shots and also for a C function using a VLA.
void function1(double ar[], int size);
void function1_vla(int size, double ar[size]);

void function2(short ar[][30], int rows);
void function2_vla(int rows, int cols, short ar[rows][cols]);

void function3(long ar[][10][15], int x);
void function3_vla(int x, int y, int z, long ar[x][y][z]);

int main(void) {
	double trots[20];
	short clops[10][30];
	long shots[5][10][15];

	function1(trots, 20);
	function1_vla(20, trots);

	function2(clops, 10);
	function2_vla(10, 30, clops);

	function3(shots, 5);
	function3_vla(5, 10, 15, shots);
}
