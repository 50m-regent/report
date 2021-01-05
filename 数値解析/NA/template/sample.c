#include "NAbasic.h"

int main(void)
{
	FILE *fin;
	double **matrix, **matrix2;
	double *vector, *vector2;
	int row, col;
	int i, j, k;

	/* CSV����s��E�x�N�g����ǂݍ��� */
	if ((fin = fopen("inData.csv", "r")) == NULL)
	{
		fprintf(stderr, "�t�@�C�������݂��܂���.\n");
		return EXIT_FAILURE;
	}

	matrix = csvRead(&row, &col, fin);
	matrix2 = allocMatrix(row, col);
	vector = allocVector(row);

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col;j++)
		{
			// �����R�s�[���邾��
			matrix2[i][j] = matrix[i][j];
			// �s�x�N�g����
			vector[i*col+j] = matrix[i][j];
		}
	}
	
	// �\�����Ă݂�
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
	// �֐��ɂ��x�N�g����
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
	// �㏈���i���I�m�ۂ����z��͍폜��Y��Ȃ��j
	freeMatrix(matrix2);
	freeMatrix(matrix);
	freeVector(vector);
	freeVector(vector2);
	return 0;
}