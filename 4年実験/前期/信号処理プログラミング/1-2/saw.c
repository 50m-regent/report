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

double saw(double r) {
    return 1 - rad(r) / PI;
}

int main() {
    double t;
    double r, vin, vout;

    for (t = 0; t <= 8 * PI; t += PI / 100.0) {
        // printf("%f", r);
        vin = saw(t);
        vout = vin;
        printf("%f, %4f\n", t, vout);
    }
}