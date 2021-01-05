#include "NAbasic.h"

#define BUF 80

// csvファイル名取得
void get_file_name(char *file_name) {

	printf("CSV File Name<< ");
	scanf("%s", file_name);
	puts("");
}

// IEEE754形式に変換して出力
void analyze(char *c) {
	int i, j, k;

	printf("sEEEEEEE EEEEdddd dddddddd...\n");

	for (i = sizeof(double) - 1; i >= 0; --i) {
		// 8文字ずつ表示
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

	// csvファイル読み込み
	if ((fin = fopen(file_name, "r")) == NULL) {
		fprintf(stderr, "ファイルが存在しません.\n");
		return EXIT_FAILURE;
	}

	// csvからデータを読み込み
	matrix = csvRead(&row, &col, fin);

	// 一つ目の数値を文字列をコピー
	memcpy(c, &matrix[0][0], sizeof(double));

	analyze(c);

	return EXIT_SUCCESS;
}