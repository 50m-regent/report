#include <math.h>
#include "func.h"

// 関数
double f(double x) {
	return pow(x, 4) - 3 * pow(x, 2) + 5 * x - 9;
}

// 微分した関数
double df(double x) {
	return 4 * pow(x, 3) - 6 * x + 5;
}