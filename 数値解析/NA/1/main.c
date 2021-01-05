#include "NAbasic.h"

#define BUF 80

// csv�t�@�C�����擾
void get_file_name(char *file_name) {

	printf("CSV File Name<< ");
	scanf("%s", file_name);
	puts("");
}

// IEEE754�`���ɕϊ����ďo��
void analyze(char *c) {
	int i, j, k;

	printf("sEEEEEEE EEEEdddd dddddddd...\n");

	for (i = sizeof(double) - 1; i >= 0; --i) {
		// 8�������\��
		for (j = sizeof(c[i]) * 8 - 1; j >= 0; --j) {
			k = c[i] & (1 << j);
			printf("%d", k ? 1 : 0);
		}
		printf(" ");
	}
}

int main() {
	FILE *fin;
	double **matrix;
	int row, col;
	char c[sizeof(double)], file_name[BUF];

	get_file_name(file_name);

	// csv�t�@�C���ǂݍ���
	if ((fin = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "�t�@�C�������݂��܂���.\n");
		return EXIT_FAILURE;
	}

	// csv����f�[�^��ǂݍ���
	matrix = csvRead(&row, &col, fin);

	// ��ڂ̐��l�𕶎�����R�s�[
	memcpy(c, &matrix[0][0], sizeof(double));

	analyze(c);

	return EXIT_SUCCESS;
}