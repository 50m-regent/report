#include "NAbasic.h"

#define BUF 80

void get_file_name(char file_name[BUF]) {
    printf("CSV File Name <<");
    scanf("%s", file_name);
}

void print_matrix(double **a, int row, int col) {
    int i, j;
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            printf("%lf ", a[i][j]);
        }
        puts("");
    }
}

void swap_row(double **a, int row, int col, int x, int y) {
    if (x < 0 || x >= row || y < 0 || y >= row) {
        puts("Defective Input (swap())");
        return;
    }

    double *tmp = a[x];
    a[x] = a[y];
    a[y] = tmp;
}

int main() {
    int row, col;
    double **a;
    char file_name[BUF];
    FILE *fp;

    get_file_name(file_name);

    if (NULL == (fp = fopen(file_name, "r"))) {
        puts("No File!");
        return EXIT_FAILURE;
    }

    a = csvRead(&row, &col, fp);

    puts("Before swapping");
    print_matrix(a, row, col);
    swap_row(a, row, col, 0, 2);
    puts("\nAfter swapping");
    print_matrix(a, row, col);

    return EXIT_SUCCESS;
}