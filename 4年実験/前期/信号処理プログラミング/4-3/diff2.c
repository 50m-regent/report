#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 80
#define DATANUM 1000

int main(int argc, char **argv) {
    int tm1[DATANUM] = {}, tm2[DATANUM] = {}, amp1[DATANUM], amp2[DATANUM], dif, n, m;
    char buf[BUFSIZE];

    FILE *fp1, *fp2;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <file1> <file2>\n", argv[0]);
        return EXIT_FAILURE;
    }

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");

    for (n = 0; n <= DATANUM; n++) {
        if (fgets(buf, sizeof(buf), fp1) == NULL) break;
        if (buf[0] == '#') continue;
        tm1[n]  = atoi(strtok(buf, ","));
        amp1[n] = atof(strtok(NULL, "\r\n\0"));
    }
    fclose(fp1);

    for (n = 0; n <= DATANUM; n++) {
        if (fgets(buf, sizeof(buf), fp2) == NULL) break;
        if (buf[0] == '#') continue;
        tm2[n]  = atoi(strtok(buf, ","));
        amp2[n] = atoi(strtok(NULL, "\r\n\0"));
    }
    fclose(fp2);

    for (n = m = 0; n < DATANUM; n++) {
        while (tm2[m] < tm1[n]) m++;
        while (tm1[n] < tm2[m]) n++;

        if (tm1[n] != tm2[m]) continue;

        dif = amp1[n] - amp2[m];
        printf("%d, %4d\n", tm1[n], dif);
    }
    return EXIT_SUCCESS;
}