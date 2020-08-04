#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 80
#define ROUND(x) ((x > 0) ? (x + 0.5) : (x - 0.5))

#define POINTS 5

int main(int argc, char **argv) {
    int tm[(POINTS + 1) / 2] = {}, amp[POINTS] = {}, sum = 0, pt1 = 0, pt2 = 0;
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

        sum -= amp[pt1];
        
        tm[pt2]  = atoi(strtok(buf, ","));
        amp[pt1] = atoi(strtok(NULL, "\r\n\0"));

        sum += amp[pt1];

        pt1 = (pt1 + 1) % POINTS;
        pt2 = (pt2 + 1) % ((POINTS + 1) / 2);

        if (amp[pt1] == 0) continue;

        vout = ROUND(sum / (double)POINTS);
        printf("%d, %4d\n", tm[pt2], vout);
    }
    fclose(fp);

    return EXIT_SUCCESS;
}
