#include "NAbasic.h"

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
		// #?ｿｽﾍコ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽg?ｿｽs
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

	// ?ｿｽs?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽﾌで，?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽm?ｿｽﾛゑｿｽ?ｿｽC?ｿｽ齊橸ｿｽz?ｿｽ?ｩゑｿｽR?ｿｽs?ｿｽ[?ｿｽ?ｿｽ?ｿｽ?ｿｽ
	*row = i;
	if ((result = (double **)malloc(((*row) + 1) * sizeof(double *))) == NULL)
	{
		fprintf(stderr, "(from csvRead) \n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < *row; i++)
	{
		result[i] = mat[i];
	}
	result[*row] = NULL; // ?ｿｽI?ｿｽ[?ｿｽ?ｿｽNULL?ｿｽﾉゑｿｽ?ｿｽﾄゑｿｽ?ｿｽ?ｿｽ

	// ?ｿｽ?ｿｽ?ｿｽ?ｿｽ黷ｽ?ｿｽ?沍?ｿｽ?ｿｽz?ｿｽ?ｿｽﾌポ?ｿｽC?ｿｽ?ｿｽ?ｿｽ^?ｿｽ?ｿｽﾔゑｿｽ
	return result;
}

/*
 allocVector(int length)
  vector?ｿｽ?ｿｽ?ｿｽm?ｿｽﾛゑｿｽ?ｿｽ?ｿｽ
	?ｿｽﾟゑｿｽl: 1?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽz?ｿｽ?ｿｽ謫ｪ?ｿｽv?ｿｽf?ｿｽﾖのポ?ｿｽC?ｿｽ?ｿｽ?ｿｽ^?ｿｽi?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽs?ｿｽ?ｿｽj

	?ｿｽp?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ[?ｿｽ^
	  ?ｿｽ?ｿｽ?ｿｽ?ｿｽ
		length: ?ｿｽx?ｿｽN?ｿｽg?ｿｽ?ｿｽ?ｿｽﾌ抵ｿｽ?ｿｽ?ｿｽ
*/
double* allocVector(int length)
{
	double *vec;

	if ((vec = (double*)malloc(length * sizeof(double))) == NULL)
	{
		fprintf(stderr, " (from allocVector) \n");
		exit(EXIT_FAILURE);
	}

	return vec;
}

/*
 allocMatrix(int row, int col)
  matrix?ｿｽ?ｿｽ?ｿｽm?ｿｽﾛゑｿｽ?ｿｽ?ｿｽ
    ?ｿｽﾟゑｿｽl: 2?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽz?ｿｽ?ｿｽ謫ｪ?ｿｽv?ｿｽf?ｿｽﾖのポ?ｿｽC?ｿｽ?ｿｽ?ｿｽ^?ｿｽi?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽs?ｿｽ?ｿｽj

	?ｿｽp?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ[?ｿｽ^
	  ?ｿｽ?ｿｽ?ｿｽ?ｿｽ
		row: ?ｿｽs?ｿｽ?ｿｽ
		col: ?ｿｽ?ｿｽ
*/
double** allocMatrix(int row, int col)
{
	double **matrix;
	int i;
	if ((matrix = (double **)malloc((row+1) * sizeof(double *))) == NULL)
	{
		fprintf(stderr, " (from allocMatrix) \n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < row; i++)
	{
		if ((matrix[i] = (double *)malloc(col * sizeof(double))) == NULL)
		{
			fprintf(stderr, " (from allocMatrix) \n");
			exit(EXIT_FAILURE);
		}
	}
	matrix[row] = NULL;

	return matrix;
}

/*
  freeMatrix(double **matrix)
	matrix?ｿｽ?ｿｽ?ｿｽm?ｿｽﾛゑｿｽ?ｿｽ?ｿｽ
	  ?ｿｽﾟゑｿｽl: ?ｿｽJ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽor?ｿｽ?ｿｽ?ｿｽs

	  ?ｿｽp?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ[?ｿｽ^
		?ｿｽ?ｿｽ?ｿｽ?ｿｽ
		  matrix: ?ｿｽJ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽs?ｿｽ?ｿｽi?ｿｽﾅ終?ｿｽs?ｿｽv?ｿｽf?ｿｽ?ｿｽNULL?ｿｽj
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
	vector?ｿｽ?ｿｽ?ｿｽm?ｿｽﾛゑｿｽ?ｿｽ?ｿｽ
	  ?ｿｽﾟゑｿｽl: ?ｿｽJ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽor?ｿｽ?ｿｽ?ｿｽs

	  ?ｿｽp?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ[?ｿｽ^
		?ｿｽ?ｿｽ?ｿｽ?ｿｽ
		  vector: ?ｿｽJ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽ?ｿｽx?ｿｽN?ｿｽg?ｿｽ?ｿｽ
*/
int freeVector(double *vector)
{
	free(vector);
	return EXIT_SUCCESS;
}

double* matrix2colVector(const double **matrix, int row, int col)
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