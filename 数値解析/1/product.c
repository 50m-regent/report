#include <math.h>
#include "NAbasic.h"

#define BUF 80

double **matrix_p(double **x, double **y, int xrow, int xcol, int yrow, int ycol) {
    int i, j;
    double **ret = allocMatrix(xrow, ycol);

    if (xrow != ycol || xcol != yrow) {
        puts("Defective data! (matrix_p())");
        return ret;
    }

    for (i = 0; i < xrow; i++) {
        for (j = 0; j < xcol; j++) {
            ret[i][i] += x[i][j] * y[j][i];
        }
    }

    return ret;
}

double norm(double *x, int len) {
    int i;
    double ret = 0;
    for (i = 0; i < len; i++) {
        ret += x[i] * x[i];
    }

    return sqrt(ret);
}

double calc_angle(double **x, double **y, int xrow, int xcol, int yrow, int ycol) {
    if (xrow != 1 || ycol != 1 || xcol != yrow) {
        puts("Defective data! (calc_angle())");
        return -1;
    }

    double p = matrix_p(x, y, xrow, xcol, yrow, ycol)[0][0];
    return acosf(p / norm(matrix2colVector(x, xrow, xcol), xrow * xcol) / norm(matrix2colVector(y, yrow, ycol), yrow * ycol));
}

int main() {
    int xrow, xcol, yrow, ycol;
    double **x, **y, **prod;
    char file_name[BUF];
    FILE *fp;

    printf("x CSV File Name <<");
    scanf("%s", file_name);

    if (NULL == (fp = fopen(file_name, "r"))) {
        puts("No File!");
        return EXIT_FAILURE;
    }

    x = csvRead(&xrow, &xcol, fp);

    printf("y CSV File Name <<");
    scanf("%s", file_name);

    if (NULL == (fp = fopen(file_name, "r"))) {
        puts("No File!");
        return EXIT_FAILURE;
    }

    y = csvRead(&yrow, &ycol, fp);

    prod = matrix_p(x, y, xrow, xcol, yrow, ycol);

    printf("Inner product: %lf\n", prod[0][0]);

    printf("Angle: %lf [rad]\n", calc_angle(x, y, xrow, xcol, yrow, ycol));

    return EXIT_SUCCESS;
}