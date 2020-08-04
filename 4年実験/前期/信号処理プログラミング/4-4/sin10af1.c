#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pi.h"

#define BIAS 0x80
#define DT 10
#define TEND 1000

int main(int argc, char **argv) {
    int t;
    double amp, frq, phf, r, vin, esum = 0, rms;
    unsigned char vout;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <amplitude> <frequency>\n", argv[0]);
    }
    amp = atof(argv[1]);
    frq = atof(argv[2]);

    for (t = 0; t <= TEND; t += DT) {
        r = 2 * PI * frq * t / 1000.0;
        vin = amp * sin(r) + BIAS;
        if (vin > 255) {
            vout = 255;
        } else if (vin < 0) {
            vout = 0;
        } else {
            vout = vin;
        }

        esum += (vin - vout) * (vin - vout);

        printf("%4d, %4d\n", t, vout);
    }

    rms = sqrt(esum / (TEND / DT + 1));
    printf("#E_RMS: %f\n", rms);

    return EXIT_SUCCESS;
}