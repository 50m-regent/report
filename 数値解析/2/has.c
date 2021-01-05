#include "NAbasic.h"
#include "func.h"

#define BUF 80
#define EPOCHS 10

// csv?��t?��@?��C?��?��?��?��?��擾
void get_file_name(char *file_name) {

	printf("CSV File Name<< ");
	scanf("%s", file_name);
	puts("");
}

// ?��?��@
void bisection(
	double a1,
	double a2,
	double (*f)(double x)
){
	int i;
	double mid;

	puts("?��?��@");

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

void false_pos(
	double a1,
	double a2,
	double (*f)(double x)
){
	int i;
	double next;

	puts("?��?��@");

	for (i = 1; EPOCHS >= i; ++i) {
		next = (a1 * f(a2) - a2 * f(a1)) / (f(a2) - f(a1));

		printf("Epoch: %2d, x=%lf\n", i, next);

		if (0 > f(a1) * f(next)) {
			a2 = next;
		} else {
			a1 = next;
		}
	}
}

// ?��j?��?��?��[?��g?��?��?��@
void newton(
	double a1,
	double a2,
	double(*f)(double x),
	double(*df)(double x)
) {
	int i;
	double x = (a1 + a2) / 2.0;

	puts("?��j?��?��?��[?��g?��?��?��@");

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

	// csv?��t?��@?��C?��?��?��ǂݍ�?��?��
	if (NULL == (fin = fopen(file_name, "r"))) {
		fprintf(stderr, "?��t?��@?��C?��?��?��?��?��?��?��݂�?��܂�?��?��.\n");
		return EXIT_FAILURE;
	}

	// csv?��?��?��?��f?��[?��^?��?��ǂݍ�?��?��
	matrix = csvRead(&row, &col, fin);

	// ?��͈͂�?��?��?��?��?��?��
	a1 = matrix[0][0];
	a2 = matrix[0][1];

	// ?��?��@
	bisection(a1, a2, f);
	puts("");

    false_pos(a1, a2, f);
    puts("");
	// ?��j?��?��?��[?��g?��?��?��@
	newton(a1, a2, f, df);

	return EXIT_SUCCESS;
}