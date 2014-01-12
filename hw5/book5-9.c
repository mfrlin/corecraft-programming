#include <stdio.h>
#define MONTHNUM 13

void month_day(int year, int day, int *m, int *d);
int day_of_year(int year, int month, int day);

static char daytab[2][MONTHNUM] = {
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void) {
	int m, d;
	month_day(1988, 60, &m, &d);
	printf("%d %d\n", m, d);
	printf("%d\n", day_of_year(1987, 2, 29));
	printf("%d\n", day_of_year(1988, 2, 29));

	return 0;
}
/* *(*daytab + (MONTHNUM * leap + i)) == *(*(daytab + leap) + i) */
int day_of_year(int year, int month, int day) {
	if (year < 0 || month < 1 || day < 0 || month > 12) {
		return -1;
	}
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if (day > *(*(daytab + leap) + month)) {
		return -1;
	}
	for (i = 1; i < month; i++) {
		day += *(*(daytab + leap) + i);
	}
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
	int i, leap;

	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if ((!leap && yearday > 365) || yearday > 366) {
		*pmonth = -1;
		*pday = -1;
	}
	for (i = 1; yearday > *(*daytab + (MONTHNUM * leap + i)); i++) {
		yearday -= *(*daytab + (MONTHNUM * leap + i));
	}
	*pmonth = i;
	*pday = yearday;
}