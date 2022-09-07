#ifndef SHTIME_H
#define SHTIME_H

typedef struct Time {
	int ms;
	int ss;
	int mm;
	int hh;
} Time;

int sh_fromTime(Time *time);
Time sh_fromNumber(int number);

#endif
