#include <stdio.h>
#include <math.h>
#include "pi.h"

double rad(double r) {
    if (r >= 0) {
        return fmod(r, 2 * PI);
    } else {
        return 2 * PI - fmod(-r, 2 * PI);
    }
}

double squ(double r) {
    return rad(r) < PI ? 1 : -1;
}

int main() {
    double t;
    double r, vin, vout;

    for (t = 0; t <= 4.0 * PI; t += PI / 100.0) {
        vin = squ(t);
        vout = vin;
        printf("%f, %4f\n", t, vout);
    }
}