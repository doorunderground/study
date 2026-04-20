#ifndef DATE_H
#define DATE_H

#include <stdio.h>

typedef struct // 년,월,일 구조체
{
	int year;
	int month;
	int day;
} Date;

void printDate(Date date);
int compareDate(Date d1, Date d2);
#endif