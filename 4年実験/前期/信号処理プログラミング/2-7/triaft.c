#include <stdio.h>
#include <stdlib.h>
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
        return 2.0 - 2.0 * (rad(r) - PI / 2.0) / PI;
    }
}

int main(int argc, char **argv) {
    int t;
    double r, amp, frq, smp, vin, vout;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <amplitude> <frequency> <sampling interval>", argv[0]);
        return EXIT_FAILURE;
    }

    amp = atof(argv[1]);
    frq = atof(argv[2]);
    smp = atof(argv[3]);

    for (t = 0; t <= 1000; t += smp) {
        r = t / 1000.0 * 2.0 * PI * frq;
        vin = amp * tri(r);
        vout = vin;
        printf("%d, %4f\n", t, vout);
    }
}