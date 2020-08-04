#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pi.h"

#define BIAS 0x80

int main(int argc, char **argv) {
    int m, n, t;
    double amp, r, vin;
    unsigned char vout;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <amplitude> <M>\n", argv[0]);
    }
    amp = atof(argv[1]);
    m   = atof(argv[2]);

    for (t = 0; t <= 1000; t += 2) {
        for (vin = BIAS, n = 1; n <= m; n++) {
            r = (t * 2.0 / 1000.0 * 2.0 * PI) * n;
            vin += 8.0 * amp * sin(r) / (double)n / (double)n / PI / PI * sin(n * PI / 2.0);
        }
        
        if (vin > 255) {
            vout = 255;
        } else if (vin < 0) {
            vout = 0;
        } else {
            vout = vin + 0.5;
        }

        printf("%d, %4d\n", t, vout);
    }

    return EXIT_SUCCESS;
}