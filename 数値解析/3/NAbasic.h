/*
	?申?申?申l?申?申��p?申?申{?申��鐃�?申Q?申w?申b?申_?申t?申@?申C?申?申
	?申@Oct. 03, 2018		ver 1.0
*/

// ?申K?申v?申w?申b?申_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ?申?申{?申p?申?申?申?申?申[?申^?申?申`
#define MAX_STR_LENGTH 200	// 1?申s?申��鐃�?申?申?申?申?申����鐃�l
#define MAX_ROW_NUM 100		// csc?申t?申@?申C?申?申?申����鐃�s?申?申

// csv?申t?申@?申C?申?申?申?申����鐃�?申������鐃�?申z?申?申��i?申[?申?申?申?申
double** csvRead(int *row, int *col, FILE *fin);
// vector?申?申?申m?申��鐃�?申?申
double* allocVector(int length);
// matrix?申?申?申m?申��鐃�?申?申
double** allocMatrix(int row, int col);
// matrix?申?申?申J?申?申?申?申?申?申
int freeMatrix(double **matrix);
// vector?申?申?申J?申?申?申?申?申?申
int freeVector(double *vector);
// matrix?申?申?申x?申N?申g?申?申?申����鐃�?申?申?申?申
double* matrix2colVector(const double **matrix, int row, int col);