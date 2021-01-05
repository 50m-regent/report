/*
	数値解析用基本関数群ヘッダファイル
	　Oct. 03, 2018		ver 1.0
*/

// 必要ヘッダ
#include	<stdio.h>
#include	<stdlib.h>
#include<string.h>

// 基本パラメータ定義
#define MAX_STR_LENGTH 200	// 1行の文字数の最大値
#define MAX_ROW_NUM 100		// cscファイルの最大行数

// csvファイルを読み込み二次元配列に格納する
double** csvRead(int *row, int *col, FILE *fin);
// vectorを確保する
double* allocVector(int length);
// matrixを確保する
double** allocMatrix(int row, int col);
// matrixを開放する
int freeMatrix(double **matrix);
// vectorを開放する
int freeVector(double *vector);
// matrixを列ベクトルへ変換する
double* matrix2colVector(const double **matrix, int row, int col);
