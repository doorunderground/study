#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#define WEEKDAY_AD01Jan01 MON //the weekday of AD Jan 1.
#define DAYS_PER_WEEK 7
#define Secs_in_Minute 60                         //60초
#define Secs_in_Hour (Secs_in_Minute * 60)        //1시간 = 3600초
#define Secs_in_DAY (Secs_in_Hour * 24)           //1일 = 86400초
#define LOCAL_GMT_OFFSET_HOUR 9

class Date
{
public:
	Date(); //default 생성자
	Date(int y, int m, int d); //생성자
	~Date(); //소멸자

	void input(); //오늘날짜 입력 받는 함수
	void print(); //출력
	void setDate(int y, int m, int dy);
	void setRandDateAttributes();
	void setMonth(int m);
	void setYear(int y);
	int getYear() { return year; }
	int getMonth() { return month; } 
	int getDay() { return day; }
	int getYearDay();
	int getYearDay(int m, int d);
	int getWeekDay();
	int getElapsedDaysFromAD010101(); //AD1년1월1일 부터 지금까지 며칠인지
	int getElapsedDaysFromAD010101(Date d);
private:
	bool isLeapYear(); //윤년 확인
	bool isLeapYear(int y); //
	bool isValidDate(int y, int m, int d); //유효 날짜 인지 확인
	int year;
	int month;
	int day;
};
#endif