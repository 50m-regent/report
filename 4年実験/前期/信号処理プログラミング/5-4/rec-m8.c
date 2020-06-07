#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pi.h"

#define BIAS 0x80
#define RIFF_SIZE 11061
#define FMT_SIZE 16
#define FORMAT_ID 1
#define SAMPLING_RATE 11025
#define CHANNEL_N 1
#define BLOCK_SIZE 1
#define Q_BIT 8

void write_header(FILE *fp) {
    int
        riff_size     = RIFF_SIZE,
        fmt_size      = FMT_SIZE,
        format_id     = FORMAT_ID,
        channel_n     = CHANNEL_N,
        sampling_rate = SAMPLING_RATE,
        block_size    = BLOCK_SIZE,
        q_bit         = Q_BIT;

    fwrite("RIFF",         sizeof(char),  4, fp);
    fwrite(&riff_size,     sizeof(int),   1, fp);
    fwrite("WAVE",         sizeof(char),  4, fp);
    fwrite("fmt ",         sizeof(char),  4, fp);
    fwrite(&fmt_size,      sizeof(int),   1, fp);
    fwrite(&format_id,     sizeof(short), 1, fp);
    fwrite(&channel_n,     sizeof(short), 1, fp);
    fwrite(&sampling_rate, sizeof(int),   1, fp);
    fwrite(&sampling_rate, sizeof(int),   1, fp);
    fwrite(&block_size,    sizeof(short), 1, fp);
    fwrite(&q_bit,         sizeof(short), 1, fp);
    fwrite("data",         sizeof(char),  4, fp);
    fwrite(&sampling_rate, sizeof(int),   1, fp);
}

int main(int argc, char **argv) {
    int t;
    double rad, frq, amp;
    unsigned char vout;
    FILE *fp;

    if (argc != 4) {
        return EXIT_FAILURE;
    }
    amp = atof(argv[1]);
    frq = atof(argv[2]);

    if ((fp = fopen(argv[3], "a+b")) == NULL) {
        return EXIT_FAILURE;
    }

    write_header(fp);

    for (t = 0; t <= SAMPLING_RATE; t++) {
        rad = 2 * PI * frq * t / (double)SAMPLING_RATE;
        vout = amp * sin(rad) + BIAS;
        fwrite(&vout, 1, 1, fp);
    }
}