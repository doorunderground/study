/*
    3.1  입력 문자 1개를 받고, 
    대문자, 소문자, 모음 (a e i o u), 자음, 숫자, 기호를 구분
    그 결과를 출력하는 알고리즘을 작성해라.

    char ch;

    if ( (ch >= 'a') && (ch <= 'z') )
        if ( ch == 'a' 'e' 'i' 'o' 'u')
    
    if ( (ch >= 'A') && (ch <= 'Z') )
        if ( ch == 'A' 'E' 'I' 'O' 'U')

    if ( (ch >= '0') && (ch <= '9') )
    
    else 
        기호
*/

/*
    3.2  연도(year)를 입력받고,
    그 년도의 1~12월 달력을 월별로 출력하는 알고리즘을 작성해라.
    윤년 확인



*/


#include <stdio.h>


const char * WEEKNAME[2] = {"SUN", "MON"};
enum WEEK {SUN, MON, TUE};

int main()
{
    printf("%s \n", WEEKNAME[1]);

    printf("%d \n", SUN);
    return 0;
}