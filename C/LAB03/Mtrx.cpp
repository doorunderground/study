#include "Mtrx.h"

#define WEEKDAY_AD01Jan01 MON  // the weekday of AD Jan 1
#define DAYS_PER_WEEK 7

enum WEEKDAY { SUN, MON, TUE, WED, THR, FRI, SAT };
enum MONTH { JAN = 1, FED, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

const char* weekDayName[DAYS_PER_WEEK] = { "SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT" };
const char* monthName[13] = {"", "January", "February", "March", "April","May", "June", "July", "August", "September", "October", "November", "December" };

// 윤년이 되는 조건
bool isLeapYear(int year)
{
    if (year % 4 == 0  && year % 100 != 0 || year % 400 == 0)
        return true;
    else
        return false;
}

//  서기 1년으로 부터 year 직전 연도까지의 날짜 수 계산
int getDaysFromJan01AD01(int year, int month, int day)
{
    int daysFromAD01Jan01 = 0;
    int daysInYear;
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int y = 1; y < year; y++)
    {
        daysInYear = isLeapYear(y) ? 366 : 365;
        // 윤년 True - 366 , 윤년 False - 365
        daysFromAD01Jan01 += daysInYear;
    }

    if (isLeapYear(year)) // 윤년이면?
        daysInMonth[2] = 29;

    for (int m = 1; m < month; m++)
    {
        daysFromAD01Jan01 += daysInMonth[month];
    }

    daysFromAD01Jan01 += day;
    return daysFromAD01Jan01;
}

void printCalendar(int year)
{
    int weekDay;
    int daysFromJan01AD01 = 0;
    int daysInMonth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    daysFromJan01AD01 = getDaysFromJan01AD01(year, 1, 1);
    weekDay = (daysFromJan01AD01 - 1 + WEEKDAY_AD01Jan01) % DAYS_PER_WEEK;

    if (isLeapYear(year))
        daysInMonth[2] = 29;

    printf(">>>>>>> Calendar of %d <<<<<<<<\n", year);

    for (int month = JAN; month <= DEC; month++)
    {
        printf("%s\n", monthName[month]);
        printf("=====================================\n");
        for (int wk = SUN; wk <= SAT; wk++)
        {
            printf("%5s", weekDayName[wk]);
        }

        printf("\n-------------------------------------\n");
        // 각 달 별로 1일 ~ 마지막 날까지 날짜 별로 요일에 맞추어 출력
        

        printf("=====================================\n");
        
        if (((month % 3) == 0) && (month != DEC))
        {
            printf("Hit any key to continue to next 3 months :");
            _getch();
            printf("\n");
        }

    }
}