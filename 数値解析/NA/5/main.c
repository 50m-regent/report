#include <math.h>
#include "NAbasic.h"

#define BUF 80

// 行列とベクトルの積を求める
double *matrix_times_vector(double **x, double *y, int xrow, int xcol, int ylen) {
    int i, j;
    double *ret = allocVector(ylen);

    if (xrow != ylen) {
        puts("Defective data! (matrix_times_vector())");
        return ret;
    }

    for (i = 0; i < xrow; i++) {
        for (j = 0; j < xcol; j++) {
            ret[i] += x[i][j] * y[j];
        }
    }

    return ret;
}

// 行列を出力
void print_matrix(double **a, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%lf ", a[i][j]);
        }
        puts("");
    }
	puts("");
}

// ベクトルを出力
void print_vector(double *a, int row) {
    int i;
    for (i = 0; i < row; i++) {
        printf("%lf ", a[i]);
    }
	puts("");
}

// 行列の行交換
void swap_row(double **a, int row, int x, int y) {
    if (x < 0 || x >= row || y < 0 || y >= row) {
        puts("Defective Input (swap_row())");
        return;
    }

    double *tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
}

// LU分解 成功したら0を返す
int lu(
	double **A,
	double **L,
	double **U,
	double **P,
	int Arow
) {
	int i, j, k, pivot;
	double q;

	for (i = 0; i < Arow; i++) {
		for (pivot = j = i; j < Arow; j++) {
			if (fabs(A[j][i]) > fabs(A[pivot][i])) {
				pivot = j;
			}
		}

		swap_row(A, Arow, i, pivot);
		swap_row(L, Arow, i, pivot);
		swap_row(U, Arow, i, pivot);
		swap_row(P, Arow, i, pivot);

		q = A[i][i];
		if (0 == q) {
			print_matrix(A, Arow, Arow);
			puts("Defective A Data!");
			return EXIT_FAILURE;
		}
		for (j = i; j < Arow; j++) {
			L[j][i] = A[j][i];
			A[i][j] /= q;
		}
		
		for (k = i + 1; k < Arow; k++) {
			q = A[k][i];
			for (j = i; j < Arow; j++) {
				A[k][j] -= A[i][j] * q;
			}
		}

		for (j = i; j < Arow; j++) {
			U[i][j] = A[i][j];
		}
	}

	return EXIT_SUCCESS;
}

// 前進消去
void forward_elimination(
	double **L,
	double *y,
	double *Pb,
	int Arow
) {
	int i, j;

	for (i = 0; i < Arow; i++) {
		y[i] = Pb[i] / L[i][i];
		for (j = 0; j < i; j++) {
			y[i] -= y[j] * L[i][j] / L[i][i];
		}
	}
}

// 後退代入
void backward_substitution(
	double **U,
	double *x,
	double *y,
	int Arow
) {
	int i, j;

	for (i = Arow - 1; i >= 0; i--) {
		x[i] = y[i] / U[i][i];
		for (j = i + 1; j < Arow; j++) {
			x[i] -= x[j] * U[i][j] / U[i][i];
		}
	}
}

// メモリ開放
void free_mems(
	double **A,
	double **b,
	double **L,
	double **U,
	double **P,
	double *x,
	double *Pb,
	double *y
) {
	freeMatrix(A);
	freeMatrix(b);
	freeMatrix(L);
	freeMatrix(U);
	freeMatrix(P);

	freeVector(x);
	freeVector(Pb);
	freeVector(y);
}

// 連立方程式を解く
void hiding(
	double **A,
	double **L,
	double **U,
	double **P,
	double **b,
	double *Pb,
	double *x,
	double *y,
	int Arow,
	int Acol,
	int brow,
	int bcol
) {
	Pb = matrix_times_vector(
		P, matrix2colVector(b, brow, bcol),
		Arow, Acol, brow
	);

	forward_elimination(L, y, Pb, Arow);
	backward_substitution(U, x, y, Arow);

	puts("x");
	print_vector(x, Arow);

	free_mems(A, b, L, U, P, x, Pb, y);
}

int main() {
	FILE *fin;
	double **A, **b, **L, **U, **P, *x, *Pb, *y;
	int i, Arow, Acol, brow, bcol;
	char file_name[BUF];

	printf("A CSV File Name<< ");
	scanf("%s", file_name);
	puts("");

	// Aのcsvファイル読み込み
	if (NULL == (fin = fopen(file_name, "r"))) {
		fprintf(stderr, "ファイルが存在しません.\n");
		return EXIT_FAILURE;
	}
	// csvからデータを読み込み
	A = csvRead(&Arow, &Acol, fin);

	if (Arow != Acol) {
		puts("Defective A Input!");
		return EXIT_FAILURE;
	}

	// 各変数のメモリ確保
	L = allocMatrix(Arow, Acol);
	U = allocMatrix(Arow, Acol);
	P = allocMatrix(Arow, Acol);
	x = allocVector(Arow);
	y = allocVector(Arow);

	// Pは単位行列にしておく
	for (i = 0; i < Arow; i++) {
		P[i][i] = 1;
	}

	// LU分解が失敗したら終了
	if (lu(A, L, U, P, Arow)) {
		return EXIT_FAILURE;
	}

	// 各行列の出力
	puts("L行列");
	print_matrix(L, Arow, Acol);

	puts("U行列");
	print_matrix(U, Arow, Acol);

	puts("P行列");
	print_matrix(P, Arow, Acol);


	printf("b CSV File Name<< ");
	scanf("%s", file_name);
	puts("");

	// yのcsvファイル読み込み
	if (NULL == (fin = fopen(file_name, "r"))) {
		fprintf(stderr, "ファイルが存在しません.\n");
		return EXIT_FAILURE;
	}
	// csvからデータを読み込み
	b = csvRead(&brow, &bcol, fin);
	
	if (1 != bcol) {
		puts("Defective b Input!");
		return EXIT_FAILURE;
	}

	// 連立方程式解く
	hiding(A, L, U, P, b, Pb, x, y, Arow, Acol, brow, bcol);

	return EXIT_SUCCESS;
}