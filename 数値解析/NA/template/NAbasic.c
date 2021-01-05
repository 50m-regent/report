/*
数値解析用基本関数群実装ファイル
　Jan. 11, 2019		ver 1.1
 */

#include "NAbasic.h"

/*
 csvRead(int *row, int *col, FILE *fin)
  csvファイルを読み込み二次元配列に格納する。
	戻り値: 2次元配列先頭要素へのポインタ（実数行列）

	パラメータ
	　出力
		row: 読み込まれた行数
		col: 読み込まれた列数 (csvの最初のデータ行で確定)

	　入力
		fin: 読み込むファイルのファイルポインタ
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
		// #はコメント行
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

	// 行数が分かったので，メモリを確保し，一時配列からコピーする
	*row = i;
	if ((result = (double **)malloc(((*row) + 1) * sizeof(double *))) == NULL)
	{
		fprintf(stderr, "メモリを確保できません (from csvRead) \n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < *row; i++)
	{
		result[i] = mat[i];
	}
	result[*row] = NULL; // 終端をNULLにしておく

	// 得られた二次元配列のポインタを返す
	return result;
}

/*
 allocVector(int length)
  vectorを確保する
	戻り値: 1次元配列先頭要素へのポインタ（実数行列）

	パラメータ
	  入力
		length: ベクトルの長さ
*/
double* allocVector(int length)
{
	double *vec;

	if ((vec = (double*)malloc(length * sizeof(double))) == NULL)
	{
		fprintf(stderr, "メモリを確保できません (from allocVector) \n");
		exit(EXIT_FAILURE);
	}

	return vec;
}

/*
 allocMatrix(int row, int col)
  matrixを確保する
    戻り値: 2次元配列先頭要素へのポインタ（実数行列）

	パラメータ
	  入力
		row: 行数
		col: 列数
*/
double** allocMatrix(int row, int col)
{
	double **matrix;
	int i;
	if ((matrix = (double **)malloc((row+1) * sizeof(double *))) == NULL)
	{
		fprintf(stderr, "メモリを確保できません (from allocMatrix) \n");
		exit(EXIT_FAILURE);
	}
	for (i = 0; i < row; i++)
	{
		if ((matrix[i] = (double *)malloc(col * sizeof(double))) == NULL)
		{
			fprintf(stderr, "メモリを確保できません (from allocMatrix) \n");
			exit(EXIT_FAILURE);
		}
	}
	matrix[row] = NULL;

	return matrix;
}

/*
  freeMatrix(double **matrix)
	matrixを確保する
	  戻り値: 開放成功or失敗

	  パラメータ
		入力
		  matrix: 開放したい行列（最終行要素はNULL）
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
	vectorを確保する
	  戻り値: 開放成功or失敗

	  パラメータ
		入力
		  vector: 開放したいベクトル
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