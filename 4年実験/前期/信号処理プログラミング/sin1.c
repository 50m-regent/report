#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pi.h"

int main() {
    double amp, dif, pi2, rad;

    pi2 = 2 * PI;
    dif = PI/90.0;
    for (rad = -pi2; rad <= pi2; rad += dif) {
        amp = sin(rad);
        printf("%6.3f, %6.3f\n", rad, amp);
    }

    return EXIT_SUCCESS;
}