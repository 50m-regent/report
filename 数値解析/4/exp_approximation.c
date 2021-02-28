#include <math.h>
#include "NAbasic.h"

#define A_NUM 2
#define DATA_NUM 4

double *exp_approxmation(double *x, double *y) {
    double
        *a = allocVector(A_NUM),
        *b = allocVector(A_NUM),
        **A = allocMatrix(A_NUM, A_NUM);

    for (i = 0; i < A_NUM; i++) {
        for (j = 0; j < DATA_NUM; j++) {
            b[i] += log(y[j]) * pow(x[j], i);
        }
    }

    for (i = 0; i < A_NUM; i++) {
        for (j = i; j < A_NUM; j++) {
            for (k = 0; k < DATA_NUM; k++) {
                A[i][j] += pow(x[k], i + j);
            }
            A[j][i] = A[i][j];
        }
    }

    gauss(A, b, A_NUM, A_NUM);
    backward_substitution(A, b, a, A_NUM);
    a[0] = exp(a[0]);

    return a;
}

int main() {
    int row, col;
    int i, j, k;

/*
    double
        *x, // サンプルのx座標
        *y, // サンプルのy座標
        *a, // 近似係数
        *b, // 連立方程式の右辺ベクトル
        **A; // 連立方程式の係数行列
*/
    double
        x[4] = {1.5, 2.0, 2.5, 3.0},
        y[4] = {8.96, 14.78, 24.36, 40.17},
        *a = allocVector(2),
        *b = allocVector(2),
        **A = allocMatrix(2, 2);

    for (i = 0; i < A_NUM; i++) {
        for (j = 0; j < DATA_NUM; j++) {
            b[i] += log(y[j]) * pow(x[j], i);
        }
    }

    for (i = 0; i < A_NUM; i++) {
        for (j = i; j < A_NUM; j++) {
            for (k = 0; k < DATA_NUM; k++) {
                A[i][j] += pow(x[k], i + j);
            }
            A[j][i] = A[i][j];
        }
    }

    gauss(A, b, A_NUM, A_NUM);
    backward_substitution(A, b, a, A_NUM);

    a[0] = exp(a[0]);

    printf("a_0 = %f, a_1 = %f\n", a[0], a[1]);

    return 0;
}