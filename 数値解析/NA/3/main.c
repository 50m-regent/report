#include "NAbasic.h"
#include "func.h"

#define BUF 80
#define EPOCHS 10

// csvファイル名取得
void get_file_name(char *file_name) {

	printf("CSV File Name<< ");
	scanf("%s", file_name);
	puts("");
}

// 二分法
void bisection(
	double a1,
	double a2,
	double (*f)(double x)
){
	int i;
	double mid;

	puts("二分法");

	for (i = 1; EPOCHS >= i; ++i) {
		mid = (a1 + a2) / 2.0;

		printf("Epoch: %2d, x=%lf\n", i, mid);

		if (0 > f(a1) * f(mid)) {
			a2 = mid;
		} else {
			a1 = mid;
		}
	}
}

// ニュートン法
void newton(
	double a1,
	double a2,
	double(*f)(double x),
	double(*df)(double x)
) {
	int i;
	double x = (a1 + a2) / 2.0;

	puts("ニュートン法");

	for (i = 1; EPOCHS >= i; ++i) {
		x = x - f(x) / df(x);

		printf("Epoch: %2d, x=%lf\n", i, x);
	}
}

int main() {
	FILE *fin;
	double **matrix, a1, a2;
	int row, col;
	char file_name[BUF];

	get_file_name(file_name);

	// csvファイル読み込み
	if (NULL == (fin = fopen(file_name, "r"))) {
		fprintf(stderr, "ファイルが存在しません.\n");
		return EXIT_FAILURE;
	}

	// csvからデータを読み込み
	matrix = csvRead(&row, &col, fin);

	// 範囲を初期化
	a1 = matrix[0][0];
	a2 = matrix[0][1];

	// 二分法
	bisection(a1, a2, f);
	puts("");
	// ニュートン法
	newton(a1, a2, f, df);

	return EXIT_SUCCESS;
}