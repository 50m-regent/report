#include "NAbasic.h"

#define BUF 80

#define IN1 "input1.csv"
#define IN2 "input2.csv"

void print_mat(double** mat) {

}

double **mat_prod(double** mat1, double **mat2) {

}

int main() {
	FILE *fin;
	double **mat1, **mat2, **prod;
	int row, col;

	// csv�t�@�C����ړǂݍ���
	if ((fin = fopen(IN1, "r")) == NULL) {
		fprintf(stderr, "�t�@�C�������݂��܂���.\n");
		return EXIT_FAILURE;
	}
	// csv����f�[�^��ǂݍ���
	mat1 = csvRead(&row, &col, fin);

	// csv�t�@�C����ړǂݍ���
	if ((fin = fopen(IN2, "r")) == NULL) {
		fprintf(stderr, "�t�@�C�������݂��܂���.\n");
		return EXIT_FAILURE;
	}
	// csv����f�[�^��ǂݍ���
	mat2 = csvRead(&row, &col, fin);
	
	prod = mat_prod(mat1, mat2);

	print_mat(prod);

	return EXIT_SUCCESS;
}