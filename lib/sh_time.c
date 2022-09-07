#include <stdio.h>
#include "../include/sh_time.h"

int sh_fromTime(Time *time){
	return time->ms + (time->ss * 1000) + (time->mm * 60 * 1000) + (time->hh * 3600 * 1000);
}

Time sh_fromNumber(int number){
	Time time;
	int hh, mm, ss, ms;

	hh = (number/1000) / 3600;
	number -= hh * 3600 * 1000;

	mm = (number/1000) / 60;
	number -= mm * 60 * 1000;

	ss = number/1000;
	ms = number-(ss*1000);

	time.ms = ms;
	time.ss = ss;
	time.mm = mm;
	time.hh = hh;

	return time;
}
