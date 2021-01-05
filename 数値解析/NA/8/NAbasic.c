/*
���l��͗p��{�֐��Q�����t�@�C��
�@Jan. 11, 2019		ver 1.1
 */

#include "NAbasic.h"

/*
 csvRead(int *row, int *col, FILE *fin)
  csv�t�@�C����ǂݍ��ݓ񎟌��z��Ɋi�[����B
	�߂�l: 2�����z��擪�v�f�ւ̃|�C���^�i�����s��j

	�p�����[�^
	�@�o��
		row: �ǂݍ��܂ꂽ�s��
		col: �ǂݍ��܂ꂽ�� (csv�̍ŏ��̃f�[�^�s�Ŋm��)

	�@����
		fin: �ǂݍ��ރt�@�C���̃t�@�C���|�C���^
*/
double** csvRead(int *row, int *col, FILE *fin)
{
	char buf[MAX_STR_LENGTH], buf2[MAX_STR_LENGTH];
	double *mat[MAX_ROW_NUM];
	double **result;

	char *nbuf;
	int i = 0, j;
	*row = *col = 0;

	while (fgets(buf, sizeof(buf), fin) != NULL)
	{
		// #�̓R�����g�s
		if (buf[0] == '#')	continue;

		if (i == 0)
		{
			strcpy(buf2, buf);
			if (strtok(buf2, ",") != NULL)	(*col)++;
			while (strtok(NULL, ",\r\n\0") != NULL)	(*col)++;
		}

		mat[i] = allocVector(*col);

		mat[i][0] = atof(strtok(buf, ","));
		for (j = 1; j < *col; j++)
		{
			nbuf = strtok(NULL, ",\r\n\0");
			if (nbuf == NULL)
				mat[i][j] = 0;
			else
				mat[i][j] = atof(nbuf);
		}
		i++;
	}

	// �s�������������̂ŁC���������m�ۂ��C�ꎞ�z�񂩂�R�s�[����
	*row = i;
	if ((result = (double **)malloc(((*row) + 1) * sizeof(double *))) == NULL)
	{
		fprintf(stderr, "���������m�ۂł��܂��� (from csvRead) \n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < *row; i++)
	{
		result[i] = mat[i];
	}
	result[*row] = NULL; // �I�[��NULL�ɂ��Ă���

	// ����ꂽ�񎟌��z��̃|�C���^��Ԃ�
	return result;
}

/*
 allocVector(int length)
  vector���m�ۂ���
	�߂�l: 1�����z��擪�v�f�ւ̃|�C���^�i�����s��j

	�p�����[�^
	  ����
		length: �x�N�g���̒���
*/
double* allocVector(int length)
{
	double *vec;

	if ((vec = (double*)malloc(length * sizeof(double))) == NULL)
	{
		fprintf(stderr, "���������m�ۂł��܂��� (from allocVector) \n");
		exit(EXIT_FAILURE);
	}

	return vec;
}

/*
 allocMatrix(int row, int col)
  matrix���m�ۂ���
    �߂�l: 2�����z��擪�v�f�ւ̃|�C���^�i�����s��j

	�p�����[�^
	  ����
		row: �s��
		col: ��
*/
double** allocMatrix(int row, int col)
{
	double **matrix;
	int i;
	if ((matrix = (double **)malloc((row+1) * sizeof(double *))) == NULL)
	{
		fprintf(stderr, "���������m�ۂł��܂��� (from allocMatrix) \n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < row; i++)
	{
		if ((matrix[i] = (double *)malloc(col * sizeof(double))) == NULL)
		{
			fprintf(stderr, "���������m�ۂł��܂��� (from allocMatrix) \n");
			exit(EXIT_FAILURE);
		}
	}
	matrix[row] = NULL;

	return matrix;
}

/*
  freeMatrix(double **matrix)
	matrix���m�ۂ���
	  �߂�l: �J������or���s

	  �p�����[�^
		����
		  matrix: �J���������s��i�ŏI�s�v�f��NULL�j
*/
int freeMatrix(double **matrix)
{
	int i=0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);

	return EXIT_SUCCESS;
}

/*
  freeVector(double *vector)
	vector���m�ۂ���
	  �߂�l: �J������or���s

	  �p�����[�^
		����
		  vector: �J���������x�N�g��
*/
int freeVector(double *vector)
{
	free(vector);
	return EXIT_SUCCESS;
}

double* matrix2colVector(double **matrix, int row, int col)
{
	double *vector;
	int i, j, k;

	k = 0;
	vector = allocVector(row * col);
	for (j = 0; j < col; j++)
	{
		for (i = 0; i < row; i++)
		{
			vector[k] = matrix[i][j];
			k++;
		}
	}
	
	return vector;
}