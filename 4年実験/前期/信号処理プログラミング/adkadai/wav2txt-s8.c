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
	
	fread(str, 1, H_LEN, fp);
	if(memcmp("RIFF", str, H_LEN) != 0) return 0;
	fread(&riffsize, 4, 1, fp);
	printf("# RIFF size: %ld\n", riffsize);

	fread(str, 1, H_LEN, fp);
	if(memcmp("WAVE", str, H_LEN) != 0) return 0;
	fread(str, 1, H_LEN, fp);
	if(memcmp("fmt ", str, H_LEN) != 0) return 0;
	fread(&fmtsize, 4, 1, fp);
	printf("# fmt size: %ld\n", fmtsize);
	fread(&fid, 2, 1, fp);
	printf("# fmt ID: %d\n", fid);
	
	if(fid != ID_LPCM) return 0;
	fread(ch, 2, 1, fp);
	printf("# CH: %d\n", *ch);
	fread(&smprate, 4, 1, fp);
	printf("# Sampling rate: %1lu\n", smprate);
	fread(&bytepersec, 4, 1, fp);
	printf("# Bytes per sec: %1lu\n", bytepersec);
	fread(&blksize, 2, 1, fp);
	printf("# Block size: %d\n", blksize);
	fread(qbit, 2, 1, fp);
	printf("# Q bit: %d\n", *qbit);

	fread(str, 4, H_LEN, fp);
	if(memcmp("data", str, H_LEN) != 0) return 0;
	fread(&datasize, 4, 1, fp);
	printf("# datasize: %1lu\n", datasize);
	return smprate;
}

void read_data(FILE *fp, uLong smprate, int start, int end) {
	short amp_l, amp_r;
	double now = 0;
	while (fread(&amp_l, 1, 1, fp) && fread(&amp_r, 1, 1, fp)) {
		if (now >= start && now <= end) printf("%f, %d, %d\n", now, amp_l, amp_r);
		now += 1000.0 / smprate;
	}
}

int main(int argc, char **argv) {
	uLong dsize;
	uShort ch, qbit;
	FILE *fp;
	
	if(argc != 4) {
		return EXIT_FAILURE;
	}
	if((fp = fopen(argv[1], "rb")) == NULL) {
		return EXIT_FAILURE;
	}
	read_data(fp, read_head(fp, &ch, &qbit), atoi(argv[2]), atoi(argv[3]));
	fclose(fp);
	return EXIT_SUCCESS;
}