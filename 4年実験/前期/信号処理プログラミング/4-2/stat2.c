#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define BUFSIZE 80
#define DATANUM 100
#define ROUND(x) ((x > 0) ? (x + 0.5) : (x - 0.5))
#define INF 1e9

int main(int argc, char **argv) {
    int tm[DATANUM], amp[DATANUM];
    char buf[BUFSIZE];
    double min_val = INF, max_val = -INF, sum = 0, mean, sum_squ = 0, std_dev, data_num = 0, max_amp, rms;
    FILE *fp;

    if (argc != 2) {
        return EXIT_FAILURE;
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        return EXIT_FAILURE;
    }

    srand((unsigned)time(NULL));

    for (int n = 0; n <= DATANUM; n++) {
        if (fgets(buf, sizeof(buf), fp) == NULL) break;
        if (buf[0] == '#') continue;
        tm[n]  = atoi(strtok(buf, ","));
        amp[n] = atoi(strtok(NULL, "\r\n\0"));
    }
    fclose(fp);

    for (int n = 0; n <= DATANUM; n++) {
        if (min_val > amp[n]) min_val = amp[n];
        if (max_val < amp[n]) max_val = amp[n];

        sum += amp[n];

        sum_squ += amp[n] * amp[n];
    }

    mean = sum / data_num;
    std_dev = sqrt(sum_squ / data_num -  mean * mean);
    max_amp = max_val - (max_val + min_val) / 2.0;
    rms = max_amp / sqrt(2);

    printf(
        "Min: %f, Max: %f, Mean: %f, Std Deviation: %f, Max Amplitude: %f, RMS: %f\n",
         min_val, max_val, mean,     std_dev,           max_amp,           rms
    );

    return EXIT_SUCCESS;
}