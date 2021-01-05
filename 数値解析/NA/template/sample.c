#include "NAbasic.h"

int main(void)
{
	FILE *fin;
	double **matrix, **matrix2;
	double *vector, *vector2;
	int row, col;
	int i, j, k;

	/* CSVから行列・ベクトルを読み込む */
	if ((fin = fopen("inData.csv", "r")) == NULL)
	{
		fprintf(stderr, "ファイルが存在しません.\n");
		return EXIT_FAILURE;
	}

	matrix = csvRead(&row, &col, fin);
	matrix2 = allocMatrix(row, col);
	vector = allocVector(row);

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col;j++)
		{
			// ただコピーするだけ
			matrix2[i][j] = matrix[i][j];
			// 行ベクトル化
			vector[i*col+j] = matrix[i][j];
		}
	}
	
	// 表示してみる
	printf("matrix1: \t\t matrix2: \n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col;j++)
		{			
			printf("%7.3f ", matrix[i][j]);
		}
		printf("\t");		
		for (j = 0; j < col;j++)
		{			
			printf("%7.3f ", matrix[i][j]);
		}
		printf("\n");

	}
	printf("\n");
	
	printf("Row Vector: \nCol Vector(matrix2vec): \n");
	// 関数によるベクトル化
	vector2 = matrix2colVector((const double**)matrix, row, col);
	for (k = 0; k < row*col; k++)
	{
		printf("%7.3f, ", vector[k]);
	}
	printf("\n");	
	for (k = 0; k < row*col; k++)
	{
		printf("%7.3f, ", vector2[k]);
	}
	// 後処理（動的確保した配列は削除を忘れない）
	freeMatrix(matrix2);
	freeMatrix(matrix);
	freeVector(vector);
	freeVector(vector2);
	return 0;
}