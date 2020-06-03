#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BUFSIZE 80
#define DATANUM 100
#define ROUND(x) ((x > 0) ? (x + 0.5) : (x - 0.5))

int main(int argc, char **argv) {
    int tm[DATANUM], amp[DATANUM], nmax;
    double err;
    char buf[BUFSIZE];
    FILE *fp;

    if (argc != 3) {
        return EXIT_FAILURE;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        return EXIT_FAILURE;
    }

    nmax = atoi(argv[2]);
    srand((unsigned)time(NULL));
    
    for (int n = 0; n <= DATANUM; ) {
        if (fgets(buf, sizeof(buf), fp) == NULL) break;
        if (buf[0] == '#') continue;
        tm[n]  = atoi(strtok(buf, ","));
        amp[n] = atoi(strtok(NULL, "\r\n\0"));
        n++;
    }
    fclose(fp);

    for (int n = 0; n <= DATANUM; n++) {
        err = nmax * (2.0 * rand() / RAND_MAX - 1.0);
        amp[n] += ROUND(err);

        printf("%4d, %4d\n", tm[n], amp[n]);
    }
    return EXIT_SUCCESS;
}