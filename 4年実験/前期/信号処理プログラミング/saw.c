#include <stdio.h>
#include <math.h>
#include "pi.h"
#include "rad.c"

double saw(double r) {
    return 1 - rad(r) / PI;
}

double squ(double r) {
    return (rad(r) <= PI) ? 1 : -1;
}

int main() {
    printf("%f", squ(3.14));
}