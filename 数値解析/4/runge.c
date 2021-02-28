#include "NAbasic.h"
#define N 10000

double f(double x, double y, double t) {
    return y;
}

double g(double x, double y, double t) {
    return 6 * x - 5 * y;
}

void sim_euler(
    double (*f)(
        double x, double y, double t
    ),
    double (*g)(
        double x, double y, double t
    ),
    double x[N],
    double y[N],
    double l,
    double r,
    int n,
    int debug
) {
    double t = 0, dt = (l + r) / (double)n;
    int i;

    for (i = 1; i <= n; i++, t += dt) {
        if (debug) {
            printf("t: %4.4f, x: %4.4f, y: %4.4f\n", t, x[i - 1], y[i - 1]);
        }

        x[i] = x[i - 1] + f(x[i - 1], y[i - 1], t) * dt;
        y[i] = y[i - 1] + g(x[i - 1], y[i - 1], t) * dt;
    }

    if (debug) {
        printf("t: %4.4f, x: %4.4f, y: %4.4f\n", t, x[n], y[n]);
    }
}

int main() {
    double x[N], y[N];
    x[0] = 0;
    y[0] = 7;

    sim_euler(f, g, x, y, 0, 2, 100, 1);
}