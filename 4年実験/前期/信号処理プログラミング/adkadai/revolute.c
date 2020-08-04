#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "pi.h"
#define H_LEN 4
#define ID_LPCM 1
#define BIAS 0x80
#define RIFF_SIZE 11061
#define FMT_SIZE 16
#define FORMAT_ID 1
#define SAMPLING_RATE 11025
#define CHANNEL_N 1
#define BLOCK_SIZE 1
#define Q_BIT 8

typedef unsigned short uShort;
typedef unsigned long uLong;

int copy_header(FILE *fp1, FILE *fp2) {
    char str[H_LEN];
    int
        riff_size, fmt_size, format_id, channel_n, sampling_rate, byte_per_sec, block_size, q_bit, data_size;

    fread(str, 1, H_LEN, fp1);
	fread(&riff_size, 4, 1, fp1);
    fwrite("RIFF",         sizeof(char),  4, fp2);
    fwrite(&riff_size,     sizeof(int),   1, fp2);

    fread(str, 1, H_LEN, fp1);
	fread(str, 1, H_LEN, fp1);
	fread(&fmt_size, 4, 1, fp1);
    fwrite("WAVE",         sizeof(char),  4, fp2);
    fwrite("fmt ",         sizeof(char),  4, fp2);
    fwrite(&fmt_size,      sizeof(int),   1, fp2);


    fread(&format_id, 2, 1, fp1);
    fwrite(&format_id,     sizeof(short), 1, fp2);

    fread(&channel_n, 2, 1, fp1);
    channel_n = 2;
    fwrite(&channel_n,     sizeof(short), 1, fp2);

    fread(&sampling_rate, 4, 1, fp1);
    fwrite(&sampling_rate, sizeof(int),   1, fp2);

	fread(&byte_per_sec, 4, 1, fp1);
    fwrite(&byte_per_sec,  sizeof(int),   1, fp2);

    fread(&block_size, 2, 1, fp1);
    block_size = 2;
    fwrite(&block_size,    sizeof(short), 1, fp2);

    fread(&q_bit, 2, 1, fp1);
    fwrite(&q_bit,         sizeof(short), 1, fp2);

    fwrite("data",         sizeof(char),  4, fp2);

    fread(&data_size, 4, 1, fp1);
    data_size *= 2;
    fwrite(&data_size, sizeof(int),   1, fp2);

    return sampling_rate;
}

void revolute(FILE *fp1, FILE *fp2, int sampling_rate, double frq) {
	int amp, ampl, ampr;
    double theta = 0;
	while ((amp = fgetc(fp1)) != EOF) {
        ampl = (amp - BIAS) * (cos(theta / 180.0 * PI) / 2.0 + 0.5) + BIAS;
        ampr = (amp - BIAS) * (0.5 - cos(theta / 180.0 * PI) / 2.0) + BIAS;

		fwrite(&ampl, 1, 1, fp2);
        fwrite(&ampr, 1, 1, fp2);
        theta += 360.0 * frq / sampling_rate;
	}
}

int main(int argc, char **argv) {
    double frq;
	FILE *fp1, *fp2;
	
	if (argc != 4) {
		return EXIT_FAILURE;
	}
    if ((fp1 = fopen(argv[1], "rb")) == NULL) {
		return EXIT_FAILURE;
	}
	if ((fp2 = fopen(argv[2], "a+b")) == NULL) {
        return EXIT_FAILURE;
    }

    frq = atof(argv[3]);

    revolute(fp1, fp2, copy_header(fp1, fp2), frq);
    fclose(fp1);
    fclose(fp2);
	return EXIT_SUCCESS;
}