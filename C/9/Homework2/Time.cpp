#include "Time.h"

//  typedef struct
//  {
//	    int hour;
//      int min;
//      int sec;
//  } Time;

void printTime(const Time* t)
{
    printf("(%02d: %02d: %02d)\n", t->hour, t->min, t->sec);
}

void incrementTime(Time* time, int s)
{
    time->sec = time->sec + s;

    if (time->sec >= 60) //60초 -> 1분
    {
        time->min = time->min + time->sec / 60;
        time->sec = time->sec % 60;

        if (time->min >= 60) //60분 -> 1시간
        {
            time->hour = time->hour + time->min / 60;
            time->min = time->min % 60;
            time->hour = time->hour % 24;
        }
    }
}

int elapsedSeconds(Time* t)
{
    t->min += t->sec / 60;
    t->sec = t->sec % 60;
    t->hour += t->min / 60;
    t->min = t->min % 60;
    t->hour = t->hour % 24;
    
    return t->sec;
}

int compareTime(Time* tptr1, Time* tptr2)
{
    double sum1, sum2;

    sum1 = elapsedSeconds(tptr1);
    sum2 = elapsedSeconds(tptr2);

    if (sum1 > sum2)
        return 60 - (sum1 - sum2);
    else if (sum1 < sum2)
        return 60 - (sum2 - sum1);
    else
        return 0;
}

void selectSortTime(Time* times, int size)
{
    int min;
    double minElementH, minElementM, minElementS;
    Time temp;

    for (int i = 0; i < size - 1; i++)
    {
        min = i;

        minElementH = times[min].hour;
        minElementM = times[min].min;
        minElementS = times[min].sec;

        for (int j = i +1; j < size; j++)
        {
            min = j;

            if (times[min].hour < minElementH)
            {
                minElementM = times[min].hour;
            }
            else if (times[min].hour == minElementH)
            {
                if (times[min].min < minElementM)
                {
                    minElementM = times[min].min;
                }
                else if (times[min].min == minElementM)
                {
                    if (times[min].sec < minElementS)
                    {
                        minElementS = times[min].sec;
                    }
                }
            }
        }
        if (min != i)
        {
            temp = times[min];
            times[min] = times[i];
            times[i] = temp;

            times[i].hour = minElementH;
            times[i].min = minElementM;
            times[i].sec = minElementS;
        }
    }
}