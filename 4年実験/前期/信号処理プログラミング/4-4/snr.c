#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BIAS 0x80
#define BUFSIZE 80
#define DATANUM 1000

int main(int argc, char **argv) {
    int tm1[DATANUM] = {}, tm2, amp1[DATANUM], amp2, dif, n, m, sum1 = 0, sum2 = 0;
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

        sum1 += (amp1[n] - BIAS) * (amp1[n] - BIAS);
    }
    fclose(fp1);

    for (n = 0; n <= DATANUM; n++) {
        if (fgets(buf, sizeof(buf), fp2) == NULL) break;
        if (buf[0] == '#') continue;
        tm2  = atoi(strtok(buf, ","));
        amp2 = atoi(strtok(NULL, "\r\n\0"));

        sum2 += (amp2 - amp1[n]) * (amp2 - amp1[n]);
    }
    fclose(fp2);

    printf("SNR[dB]: %f\n", 10 * log10(sum1 / (double)sum2));

    return EXIT_SUCCESS;
}