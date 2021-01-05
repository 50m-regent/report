/*
	���l��͗p��{�֐��Q�w�b�_�t�@�C��
	�@Oct. 03, 2018		ver 1.0
*/

// �K�v�w�b�_
#include	<stdio.h>
#include	<stdlib.h>
#include<string.h>

// ��{�p�����[�^��`
#define MAX_STR_LENGTH 200	// 1�s�̕������̍ő�l
#define MAX_ROW_NUM 100		// csc�t�@�C���̍ő�s��

// csv�t�@�C����ǂݍ��ݓ񎟌��z��Ɋi�[����
double** csvRead(int *row, int *col, FILE *fin);
// vector���m�ۂ���
double* allocVector(int length);
// matrix���m�ۂ���
double** allocMatrix(int row, int col);
// matrix���J������
int freeMatrix(double **matrix);
// vector���J������
int freeVector(double *vector);
// matrix���x�N�g���֕ϊ�����
double* matrix2colVector(double **matrix, int row, int col);
