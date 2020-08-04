#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 80
#define ROUND(x) ((x > 0) ? (x + 0.5) : (x - 0.5))

#define POINTS 5

int main(int argc, char **argv) {
    int i, tm[(POINTS + 1) / 2] = {}, amp[POINTS] = {}, sum = 0;
    char buf[BUFSIZE];
    unsigned char vout;
    FILE *fp;

    if (argc != 2) {
        return EXIT_FAILURE;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        return EXIT_FAILURE;
    }

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        if (buf[0] == '#') continue;

        sum -= amp[0];

        for (i = 0; i < POINTS - 1; i++) {
            amp[i] = amp[i + 1];
        }
        for (i = 0; i < POINTS / 2; i++) {
            tm[i] = tm[i + 1];
        }
        
        tm[POINTS / 2]  = atoi(strtok(buf, ","));
        amp[POINTS - 1] = atoi(strtok(NULL, "\r\n\0"));

        sum += amp[POINTS - 1];

        if (amp[0] == 0) continue;

        vout = ROUND(sum / (double)POINTS);
        printf("%d, %4d\n", tm[0], vout);
    }
    fclose(fp);

    return EXIT_SUCCESS;
}
