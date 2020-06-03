#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HEAD_SIZE 44
#define H_LEN 4
#define ID_LPCM 1
typedef unsigned short uShort;
typedef unsigned long uLong;

uLong read_head(FILE *fp, uShort *ch, uShort *qbit) {
	char str[H_LEN];
	uLong riffsize, fmtsize, smprate, bytepersec, datasize;
	uShort fid, blksize;
	
	fread(str, sizeof(char), H_LEN, fp);
	if(memcmp("RIFF", str, H_LEN) != 0) return 0;
	fread(&riffsize, sizeof(uLong), 1, fp);
	printf("# RIFF size: %1lu\n", riffsize);

	fread(str, sizeof(char), H_LEN, fp);
	// if(memcmp("WAVE", str, H_LEN) != 0) return 0;
	// fread(str, sizeof(char), H_LEN, fp);
	if(memcmp("fmt ", str, H_LEN) != 0) return 0;
	fread(&fmtsize, sizeof(uLong), 1, fp);
	printf("# fmt size: %1lu\n", fmtsize);
	fread(&fid, sizeof(uShort), 1, fp);
	printf("# fmt ID: %d\n", fid);
	
	// if(fid != ID_LPCM) return 0;
	fread(ch, sizeof(uShort), 1, fp);
	printf("# CH: %d\n", *ch);
	fread(&smprate, sizeof(uLong), 1, fp);
	printf("# Sampling rate: %1lu\n", smprate);
	fread(&bytepersec,sizeof(uLong), 1, fp);
	printf("# Bytes per sec: %1lu\n", bytepersec);
	fread(&blksize, sizeof(uShort), 1, fp);
	printf("# Block size: %d\n", blksize);
	fread(qbit, sizeof(uShort), 1, fp);
	printf("# Q bit: %d\n", *qbit);

	// fread(str, sizeof(char), H_LEN, fp);
	// if(memcmp("data", str, H_LEN) != 0) return 0;
	fread(&datasize, sizeof(uLong), 1, fp);
	printf("# datasize: %1lu\n", datasize);
	return smprate;
}

void read_data(FILE *fp, uLong smprate, int start, int end) {
	char amp;
	double now = 0;
	while ((amp = fgetc(fp)) != EOF) {
		if (now >= start && now <= end) printf("%f, %d", now, amp);
		now += 1000.0 / smprate;
	}
}

int main(int argc, char **argv) {
	uLong dsize;
	uShort ch, qbit;
	FILE *fp;
	
	if(argc != 2) {
		return EXIT_FAILURE;
	}
	if((fp = fopen(argv[1], "rb")) == NULL) {
		return EXIT_FAILURE;
	}
	read_data(fp, read_head(fp, &ch, &qbit), 0, 10000);
	fclose(fp);
	return EXIT_SUCCESS;
}