#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define BUFSIZE 80
#define ROUND(x) ((x > 0) ? (x + 0.5) : (x - 0.5))
#define INF 1e9

int main(int argc, char **argv) {
    int tm, amp;
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

    while (fgets(buf, sizeof(buf), fp) != NULL) {
        if (buf[0] == '#') continue;

        data_num += 1;
        
        tm  = atoi(strtok(buf, ","));
        amp = atoi(strtok(NULL, "\r\n\0"));

        if (min_val > amp) min_val = amp;
        if (max_val < amp) max_val = amp;

        sum += amp;

        sum_squ += amp * amp;
    }
    fclose(fp);

    mean = sum / data_num;
    std_dev = sqrt(sum_squ / data_num -  mean * mean);
    max_amp = max_val - (max_val + min_val) / 2.0;
    rms = max_amp / sqrt(2);

    printf(
        "Min: %f, Max: %f, Mean: %f, Std Deviation: %f, Max Amplitude: %f, RMS: %f",
         min_val, max_val, mean,     std_dev,           max_amp,           rms
    );

    return EXIT_SUCCESS;
}