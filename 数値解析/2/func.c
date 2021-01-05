#include <math.h>
#include "func.h"

// ŠÖ”
double f(double x) {
	return pow(x, 4) - 3 * pow(x, 2) + 5 * x - 9;
}

// ”÷•ª‚µ‚½ŠÖ”
double df(double x) {
	return 4 * pow(x, 3) - 6 * x + 5;
}