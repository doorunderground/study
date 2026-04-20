#ifndef TIME_H
#define TIME_H

#include <stdio.h>
#include <time.h>

typedef struct
{
	int hour;
	int min;
	int sec;
} Time;

void printTime(const Time* t);
void incrementTime(Time* time, int s);
int elapsedSeconds(const Time* t);
int compareTime(Time* t1, Time* t2);
void selectSortTime(Time* times, int size);

#endif