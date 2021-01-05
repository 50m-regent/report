#include <math.h>
#include "NAbasic.h"

#define BUF 80
#define EPS 1e-8

/*---------------------------------------------------
	行列とベクトルの積を求める
	引数: (行列, ベクトル, 行列の行数, 行列の列数, ベクトルの次数)
	戻り値: 積(ベクトル)
---------------------------------------------------*/
double *matrix_times_vector(double **x, double *y, int xrow, int xcol, int ylen) {
	int i, j;
	double *ret = allocVector(ylen); // 結果のベクトル

	// 次数が合わなければエラー
	if (xrow != ylen) {
		puts("Defective data! (matrix_times_vector())");
		return ret;
	}

	// 計算
	for (i = 0; i < xrow; i++) {
		for (j = 0; j < xcol; j++) {
			ret[i] += x[i][j] * y[j];
		}
	}

	return ret;
}

/*---------------------------------------------------
	前進消去
	引数: (L行列, yベクトル, P*bベクトル, L行列の行数)
	戻り値: なし
---------------------------------------------------*/
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

/*---------------------------------------------------
	後退代入
	引数: (U行列, xベクトル, yベクトル, U行列の行数)
	戻り値: なし
---------------------------------------------------*/
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

/*---------------------------------------------------
	行列のx行目とy行目を交換
	引数: (行列, 行列の行数, x, y)
	戻り値: 成功したら0, 失敗したら0以外
---------------------------------------------------*/
int swap_row(double **a, int row, int x, int y) {
	// 行数が範囲外だったらエラー
	if (x < 0 || x >= row || y < 0 || y >= row) {
		puts("Defective Input (swap_row())");
		return EXIT_FAILURE;
	}

	double *tmp = a[x];
	a[x] = a[y];
	a[y] = tmp;

	return EXIT_SUCCESS;
}

/*---------------------------------------------------
	LU分解
	引数: (A行列, L行列, U行列, P行列, 行列の行数)
	戻り値: 成功したら0, 失敗したら0以外
---------------------------------------------------*/
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
		// ピボット抽出
		for (pivot = j = i; j < Arow; j++) {
			if (fabs(A[j][i]) > fabs(A[pivot][i])) {
				pivot = j;
			}
		}

		// ピボットに基づいて行交換
		swap_row(A, Arow, i, pivot);
		swap_row(L, Arow, i, pivot);
		swap_row(U, Arow, i, pivot);
		swap_row(P, Arow, i, pivot);

		q = A[i][i];
		if (0 == q) {
			// LU分解不可能であればエラー
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

/*---------------------------------------------------
	ベクトルxとベクトルyの内積を求める
	引数: (x, y, ベクトルの次数)
	戻り値: 内積
---------------------------------------------------*/
double inner_product(double *x, double *y, int len) {
	int i;
	double ret = 0;

	for (i = 0; i < len; i++) {
		ret += x[i] * y[i];
	}
	return ret;
}

/*---------------------------------------------------
	ベクトルを単位ベクトルに正規化する
	引数: (ベクトル, ベクトルの次数)
	戻り値: 成功したら0, 失敗(0ベクトルだったら)したら0以外
---------------------------------------------------*/
int normalize(double *x, int len) {
	double norm = 0; // ベクトルのノルム
	int i;

	// ベクトルのノルム計算
	for (i = 0; i < len; i++) {
		norm += x[i] * x[i];
	}

	norm = sqrtf(norm);

	if (0 == norm) {
		puts("Defective Input (normalize())");
		return EXIT_FAILURE;
	}

	// 各要素をノルムで割っていく
	for (i = 0; i < len; i++) {
		x[i] /= norm;
	}

	return EXIT_SUCCESS;
}

int main() {
	FILE *fin;
	double **A, **L, **U, **P, *y, *last_y, *z, lambda = 10e8, last_lambda;
	int i, Arow, Acol;
	char file_name[BUF];

	printf("A CSV File Name<< ");
	scanf("%s", file_name);
	puts("");

	// ファイル読み込み
	if (NULL == (fin = fopen(file_name, "r"))) {
		fprintf(stderr, "The file doesn't exist.\n");
		return EXIT_FAILURE;
	}

	// ファイルから行列読み込み
	A = csvRead(&Arow, &Acol, fin);

	// 変数のメモリ確保
	y      = allocVector(Arow);
	last_y = allocVector(Arow);

	// yを適当なベクトルにしとく
	for (i = 0; i < Arow; i++) {
		y[i] = 1;
	}

	// 最大固有値を求める
	do {
		memcpy(last_y, y, sizeof(double) * Arow);
		y = matrix_times_vector(A, last_y, Arow, Acol, Arow);
		last_lambda = lambda;
		lambda = inner_product(y, y, Arow) / inner_product(y, last_y, Arow);
		normalize(y, Arow);
	} while (fabs((lambda - last_lambda) / last_lambda) > EPS);

	printf("Max Eigenvalue: %lf\n", lambda);

	// LU分解用のメモリ確保
	L = allocMatrix(Arow, Acol);
	U = allocMatrix(Arow, Acol);
	P = allocMatrix(Arow, Acol);
	z = allocVector(Arow);
	// Pは単位行列にしておく
	for (i = 0; i < Arow; i++) {
		P[i][i] = 1;
	}

	// LU分解が失敗したら終了
	if (lu(A, L, U, P, Arow)) {
		return EXIT_FAILURE;
	}

	// yを適当なベクトルにしとく
	for (i = 0; i < Arow; i++) {
		y[i] = 1;
	}

	// 最小固有値を求める
	do {
		memcpy(last_y, y, sizeof(double) * Arow);
		forward_elimination(L, z, last_y, Arow);
		backward_substitution(U, y, z, Arow);
		last_lambda = lambda;
		lambda = inner_product(y, last_y, Arow) / inner_product(y, y, Arow);
		normalize(y, Arow);
	} while (fabs((lambda - last_lambda) / last_lambda) > EPS);

	printf("Min Eigenvalue: %lf\n", lambda);

	return EXIT_SUCCESS;
}