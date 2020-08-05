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

double tri(double r) {
    r += PI / 2.0;
    if (rad(r) < PI) {
        return 2.0 * rad(r) / PI - 1.0;
    } else {
        return 3.0 - 2.0 * rad(r) / PI;
    }
}

/*
double tri(double r) {
    if (rad(r) < PI / 2.0) {
        return 2 * rad(r) / PI;
    } else if (rad(r) < 1.5 * PI) {
        return 1 - 2 * (rad(r) - PI / 2.0) / PI;
    } else {
        return 2 * (rad(r) - 2.0 * PI) / PI;
    }
}
*/

int main() {
    double t;
    double r, vin, vout;

    for (t = 0; t <= 4.0 * PI; t += PI / 100.0) {
        vin = tri(t);
        vout = vin;
        printf("%f, %4f\n", t, vout);
    }
}