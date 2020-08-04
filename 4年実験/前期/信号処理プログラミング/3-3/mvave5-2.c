#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 80
#define DATANUM 1000
#define ROUND(x) ((x > 0) ? (x + 0.5) : (x - 0.5))

#define POINTS 5

int main(int argc, char **argv) {
    int tm[DATANUM], amp[DATANUM], sum = 0, n, data_num;
    char buf[BUFSIZE];
    unsigned char vout;
    FILE *fp;

    if (argc != 2) {
        return EXIT_FAILURE;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        return EXIT_FAILURE;
    }

    for (n = 0; n < DATANUM; n++) {
        if (fgets(buf, sizeof(buf), fp) == NULL) break;
        if (buf[0] == '#') continue;
        tm[n]  = atoi(strtok(buf, ","));
        amp[n] = atoi(strtok(NULL, "\r\n\0"));
    }
    fclose(fp);

    data_num = n;

    for (int n = 0; n < data_num; n++) {
        sum += amp[n];

        if (n < POINTS - 1) continue;
        if (n >= POINTS) sum -= amp[n - POINTS];

        vout = ROUND(sum / (double)POINTS);

        printf("%d, %4d\n", tm[n - POINTS / 2], vout);
    }
    return EXIT_SUCCESS;
}
