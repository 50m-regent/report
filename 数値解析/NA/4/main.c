#include <math.h>
#include "NAbasic.h"

// csv�t�@�C�����擾
void get_file_name(char *file_name) {

	printf("CSV File Name<< ");
	scanf("%s", file_name);
	puts("");
}

void swap_row(double **a, int row, int col, int x, int y) {
    if (x < 0 || x >= row || y < 0 || y >= row) {
        puts("Defective Input (swap_row())");
        return;
    }

    double *tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
}

void print_mat(double **A, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%3.2f", A[i][j]);
		}
		puts("");
	}
}

int main() {
	FILE *fin;
	double **A, **y, maxabs;
	int i, j, k, pivot, Arow, Acol, yrow, ycol;
	char file_name[80];

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

	printf("y CSV File Name<< ");
	scanf("%s", file_name);
	puts("");

	// y��csv�t�@�C���ǂݍ���
	if (NULL == (fin = fopen(file_name, "r"))) {
		fprintf(stderr, "�t�@�C�������݂��܂���.\n");
		return EXIT_FAILURE;
	}
	// csv����f�[�^��ǂݍ���
	y = csvRead(&yrow, &ycol, fin);
	
	for (k = 0; k < Arow; k++) {  /* 第ｋステップ */
      	pivot = k;
      	maxabs = fabs(A[k][k]);
      	for (i = k + 1; i < Arow; i++) {  /* ピボット選択 */
         	if (fabs(A[i][k]) > maxabs) {
            	pivot = i;
            	maxabs = fabs(A[i][k]);
         	}
      	}

 /* エラー処理：ピボットがあまりに小さい時はメッセージを表示して終了　*/
		if (fabs(maxabs) < 1.0e-12) {
			printf("too small pivot! \n");
			return EXIT_FAILURE;
		}
		swap_row(A, Arow, Acol, pivot, k);
/* 前進消去 */
      for (i = k + 1; i < Arow; i++) { /* 第ｉ行 */
         A[i][k] = 0.0;
         /* 第ｋ行を-a[i][k]/a[k][k]倍して、第ｉ行に加える */
         for (j = k + 1; j < Acol; j++){
            A[i][j] = A[i][j] - A[k][j] * A[i][k] / A[k][k];
         }
         y[i] = y[i] - y[k] * A[i][k] / A[k][k];
      }
   }
/* 後退代入 */
      for (i = Arow - 1; i >= 0; i--){
         for (j = i + 1; j < Acol; j++){
            y[i] = y[i] - A[i][j] * y[j];
            A[i][j] = 0.0;
         }
         y[i] = y[i] / A[i][i];
         A[i][i] = 1.0;
      }
/* 解の表示 */

	print_mat(y, Arow, 1);

	return EXIT_SUCCESS;
}