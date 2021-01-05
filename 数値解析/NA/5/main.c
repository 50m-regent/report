#include <math.h>
#include "NAbasic.h"

#define BUF 80

// �s��ƃx�N�g���̐ς����߂�
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

// �s����o��
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

// �x�N�g�����o��
void print_vector(double *a, int row) {
    int i;
    for (i = 0; i < row; i++) {
        printf("%lf ", a[i]);
    }
	puts("");
}

// �s��̍s����
void swap_row(double **a, int row, int x, int y) {
    if (x < 0 || x >= row || y < 0 || y >= row) {
        puts("Defective Input (swap_row())");
        return;
    }

    double *tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
}

// LU���� ����������0��Ԃ�
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

// �O�i����
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

// ��ޑ��
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

// �������J��
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

// �A��������������
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

	// A��csv�t�@�C���ǂݍ���
	if (NULL == (fin = fopen(file_name, "r"))) {
		fprintf(stderr, "�t�@�C�������݂��܂���.\n");
		return EXIT_FAILURE;
	}
	// csv����f�[�^��ǂݍ���
	A = csvRead(&Arow, &Acol, fin);

	if (Arow != Acol) {
		puts("Defective A Input!");
		return EXIT_FAILURE;
	}

	// �e�ϐ��̃������m��
	L = allocMatrix(Arow, Acol);
	U = allocMatrix(Arow, Acol);
	P = allocMatrix(Arow, Acol);
	x = allocVector(Arow);
	y = allocVector(Arow);

	// P�͒P�ʍs��ɂ��Ă���
	for (i = 0; i < Arow; i++) {
		P[i][i] = 1;
	}

	// LU���������s������I��
	if (lu(A, L, U, P, Arow)) {
		return EXIT_FAILURE;
	}

	// �e�s��̏o��
	puts("L�s��");
	print_matrix(L, Arow, Acol);

	puts("U�s��");
	print_matrix(U, Arow, Acol);

	puts("P�s��");
	print_matrix(P, Arow, Acol);


	printf("b CSV File Name<< ");
	scanf("%s", file_name);
	puts("");

	// y��csv�t�@�C���ǂݍ���
	if (NULL == (fin = fopen(file_name, "r"))) {
		fprintf(stderr, "�t�@�C�������݂��܂���.\n");
		return EXIT_FAILURE;
	}
	// csv����f�[�^��ǂݍ���
	b = csvRead(&brow, &bcol, fin);
	
	if (1 != bcol) {
		puts("Defective b Input!");
		return EXIT_FAILURE;
	}

	// �A������������
	hiding(A, L, U, P, b, Pb, x, y, Arow, Acol, brow, bcol);

	return EXIT_SUCCESS;
}