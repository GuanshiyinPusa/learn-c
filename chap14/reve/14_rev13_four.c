// Declare four functions and initialize an array of pointers to point to them.
// Each function should take two double arguments and return a double. Also,
// show two ways using the array to invoke the second function with arguments
// of 10.0 and 2.5.

double function1(double a, double b) { return a + b; }

double function2(double a, double b) { return a - b; }

double function3(double a, double b) { return a * b; }

double function4(double a, double b) { return a / b; }

typedef double (*ptype)(double, double);
ptype pfl[4] = {function1, function2, function3, function4};

int main(void) {
	double (*function[4])(double, double) = {
		function1, function2, function3, function4};
	double result = function[1](10.0, 2.5);
	double result3 = (*function[1])(10.0, 2.5);
}