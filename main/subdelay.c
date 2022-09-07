#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/sh_time.h"
#include "../include/files.h"

#define MAXLINE 500

int main(int argc, char* argv[]){
	FILE *fp_src, *fp_dst;

	int offset_ms;
	char buffer[MAXLINE], fform[MAXLINE];

	int hh1, mm1, ss1, ms1;
	int hh2, mm2, ss2, ms2;

	Time original_time1, original_time2, offset_time1, offset_time2;

	offset_ms = atoi(argv[2]);

	if ((fp_src = fopen(argv[1], "r")) == NULL)
		return 1;

	if ((fp_dst = fopen(strcat(argv[1], ".off"), "w")) == NULL)
		return 2;

	while (fgetline(fp_src, buffer)){
		if (strstr(buffer, "-->") != NULL){
			sscanf(buffer, "%d:%d:%d,%d --> %d:%d:%d,%d", 
							&hh1, &mm1, &ss1, &ms1, &hh2, &mm2, &ss2, &ms2);
					
			original_time1.ms = ms1;
			original_time1.ss = ss1;
			original_time1.mm = mm1;
			original_time1.hh = hh1;

			original_time2.ms = ms2;
			original_time2.ss = ss2;
			original_time2.mm = mm2;
			original_time2.hh = hh2;

			int number_offset_time1, number_offset_time2;
			number_offset_time1 = sh_fromTime(&original_time1) + offset_ms;
			number_offset_time2 = sh_fromTime(&original_time2) + offset_ms;

			offset_time1 = sh_fromNumber(number_offset_time1);
			offset_time2 = sh_fromNumber(number_offset_time2);

			sprintf(buffer, "%02d:%02d:%02d,%03d --> %02d:%02d:%02d,%03d\n", 
							offset_time1.hh, offset_time1.mm, offset_time1.ss, offset_time1.ms,
							offset_time2.hh, offset_time2.mm, offset_time2.ss, offset_time2.ms);
		}
		fputs(buffer, fp_dst);
	}
	fclose(fp_src);
	fclose(fp_dst);
	return 0;
}
