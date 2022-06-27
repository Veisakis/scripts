#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int dayOfYear(int year, int month, int day);
void monthDay(int year, int yearday, int *pmonth, int *pday);

int main(int argc, char *argv[]){
	int month, day;
	
	int *pmonth = &month;
	int *pday = &day;

	monthDay((int)strtol(argv[1], NULL, 10), 
					 (int)strtol(argv[2], NULL, 10), pmonth, pday);
					 	
	printf("%d-%d-%d\n", *pday, *pmonth, (int)strtol(argv[1], NULL, 10));
}

char days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
char ldays[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

static char *daytab[] = {days, ldays};

int dayOfYear(int year, int month, int day){
	if (day < 1 || day > 31){
		printf("Day must be in valid range (1-31)");
		return -1;
	}

	if (month < 1 || month > 12){
		printf("Month must be in valid range (1-12)");
		return -1;
	}

	if (year < 1 || year > 2100){
		printf("Year must be in valid range (1-2100)");
		return -1;
	}

	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];

	return day;
}
	
void monthDay(int year, int yearday, int *pmonth, int *pday){
	if (yearday < 1 || yearday > 365){
		printf("Yearday must be in valid range (1-365)");
		return -1;
	}

	if (year < 1 || year > 2100){
		printf("Year must be in valid range (1-2100)");
		return -1;
	}

	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++) 
		yearday -= daytab[leap][i];

	*pmonth = i;
	*pday = yearday;
}
