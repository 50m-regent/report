#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pi.h"

#define BIAS 0x80
#define TEND 1000

int main(int argc, char **argv) {
    int t;
    double amp, frq, smp, phf, r, vin, esum = 0, rms;
    unsigned char vout;

    if (argc != 5) {
        fprintf(stderr, "Usage: %s <amplitude> <frequency> <phase> <sampling interval> \n", argv[0]);
    }
    amp = atof(argv[1]);
    frq = atof(argv[2]);
    phf = atof(argv[3]);
    smp = atof(argv[4]);

    for (t = 0; t <= TEND; t += smp) {
        r = t / 1000.0 * 2.0 * PI * frq + phf;
        vin = amp * sin(r) + BIAS;
        if (vin > 255) {
            vout = 255;
        } else if (vin < 0) {
            vout = 0;
        } else {
            vout = vin + 0.5;
        }

        esum += (vin - vout) * (vin - vout);

        printf("%d, %4d\n", t, vout);
    }

    rms = sqrt(esum / (1000 / smp + 1));
    printf("#E_RMS: %f\n", rms);

    return EXIT_SUCCESS;
}