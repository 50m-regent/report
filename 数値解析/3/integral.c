#include <math.h>
#include "NAbasic.h"

double f(double x) {
    return x * log(x);
}

double trapezoid(
    double (*f)(double),
    double a,
    double b,
    int n
) {
    if (a > b) return -trapezoid(f, b, a, n);
    double sum = 0, dx = (b - a) / n, x;
    for (x = a; x <= b; x += dx) {
        sum += f(x);
    }
    sum -= (f(a) + f(b)) / 2.0;
    return sum * dx;
}

double simpson(
    double (*f)(double),
    double a,
    double b,
    int n
) {
    if (a > b) return -simpson(f, b, a, n);
    double sum = 0, dx = (b - a) / n, x;
    sum = f(a) + f(b);
    for (x = a + dx; x < b; x += 2 * dx) {
		sum += 4.0 * f(x);
	}
    for (x = a + 2 * dx; x < b; x += 2 * dx) {
        sum += 2.0 * f(x);
    }
	
	return sum * dx / 3.0;
}

double romberg(
    double (*f)(double),
    double a,
    double b,
    int n,
    double T[50][50]
) {
    if (a > b) return -romberg(f, a, b, n, T);
    int k, m;
    double h, x;

    T[0][0] = (b - a) * (f(a) + f(b)) / 2.0;

    for (k = 1; k < n; k++) {
        h = (b - a) / pow(2, k);

        T[k][0] = T[k - 1][0] / 2.0;
        for (x = a + h; x <= b - h; x += 2.0 * h) {
            T[k][0] += h * f(x);
        }

        for (m = 1; m <= k; m++) {
            T[k][m] = T[k][m - 1] + (T[k][m - 1] - T[k - 1][m - 1]) / (pow(4.0, m) - 1.0);
        }
    }

    return T[n - 1][n - 1];
}

int main() {
    double T[50][50];

    for (int i = 1; i < 50; i++) {
        printf("%f,\n", fabs(trapezoid(sin, 0, M_PI / 2, i) - 1));
        // printf("%f,\n", fabs(simpson(sin, 0, M_PI / 2, i) - 1));
        // if (i < 30) printf("%f,\n", fabs(romberg(sin, 0, M_PI / 2, i, T) - 1));

        // printf("%f,\n", fabs(trapezoid(f, 1e-18, M_E, i) - M_E * M_E / 4.0));
        // printf("%f,\n", fabs(simpson(f, 1e-18, M_E, i) - M_E * M_E / 4.0));
        // if (i < 30) printf("%f,\n", fabs(romberg(f, 1e-18, M_E, i, T) - M_E * M_E / 4.0));
    }
}