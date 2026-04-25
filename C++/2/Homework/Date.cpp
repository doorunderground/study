#include "Date.h"

enum WEEKDAY { SUN, MON, TUE, WED, THR, FRI, SAT};
enum MONTH { JAN = 1, FED, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, NUM_MONTHS};

const char* weekDayName[DAYS_PER_WEEK] = { "Sunday", "Monday", "Tuesday", "Wednesday","Thursday", "Friday", "Saturday" };
const char* weekDayNameShort[DAYS_PER_WEEK] = { "SUN", "MON", "TUE", "WED", "THR", "FRI", "SAT" };
const char* monthName[13] = { "", "January", "February", "March", "April", "May", "June", "July", "August","September", "October", "November", "December" };

// 클래스명 :: 함수명
// Date 클래스에 속한 Date() 함수
Date::Date()
{
    year = 0;
    month = 0;
    day = 0;
}

Date::Date(int y, int m, int d) 
{
    year = y;
    month = m;
    day = d;
}

Date::~Date()
{

}

bool Date::isValidDate(int y, int m, int d)
{
    int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    if (isLeapYear(y)) //윤년
        days_month[2] = 29;
    if ((m >= 1) && (m <= 12) && (d >= 1) && (d <= days_month[m]))
        return true;
    else
    {
        cout << "Illegal Date (" << m << ", " << d << ") ==> Program aborted. \n";
        return false; 
    }
}

void Date::setDate(int y, int m, int d)
{
    if (isValidDate(y, m , d))
    {
        year = y;
        month = m;
        day = d;
    }
    else
    {
        cout << "Invalid date (" << y << ", " << m << ", " << d << ")";
        cout << " Program aborted !!\n";
        exit(1);
    }
}

void Date::setRandDateAttributes()
{
    int days_month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    year = rand() % 2000 + 1000;
    month = rand() % 12 + 1;

    if(isLeapYear(year) && month == 2)
        days_month[2] = 29;
    day = rand() % days_month[month] + 1;
}

void Date::setMonth(int newMonth)
{
    if ((newMonth >= 1) && (newMonth <= 12))
        month = newMonth;
    else
    {
        cout << "Illegal month value! Program aborted.\n";
        exit(1);
    }
    day = 1;
}