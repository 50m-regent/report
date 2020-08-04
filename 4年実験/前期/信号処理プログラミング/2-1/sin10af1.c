#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pi.h"

#define BIAS 0x80
#define DT 10
#define TEND 1000

int main(int argc, char **argv) {
    int t;
    double amp, frq, phf, r, vin, esum=0;
    unsigned char vout;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s amplitude frequency\n", argv[0]);
    }
    amp = atof(argv[1]);
    frq = atof(argv[2]);
    /*
    printf("#A %f\n", amp);
    printf("#F %f\n", frq);
    printf("#T %d\n", DT);
    printf("#B %d\n", BIAS);
    printf("#N %d\n", TEND / DT + 1);
    */
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
        printf("%4f, %4d\n", t, vout);
    }
    // printf("#E %g\n", esum);
    return EXIT_SUCCESS;
}