// Homework 9
/*
    9.1 구조체를 사용하여 함수에 인수를 전달하고,
    결과값을 반환시키는 기능을 예를 들어 설명하라.

    
*/

#include <stdio.h>

typedef struct{
    int x;
    int y;
} Point;

Point move(Point p, int dx, int dy)
{
    p.x += dx;
    p.y += dy;

    return p;
}

void move2(Point *p, int dx, int dy)
{
    (*p).x += dx;
    (*p).y += dy;
    
    //p->x += dx;
    //p->y += dy
}

int main()
{
    Point a = {1, 2};
    Point b = move(a, 3, 4);

    Point c = {3, 4};
    move2(&c, 3, 4);

    printf("a : (%d  %d)\n", a.x, a.y);
    printf("b : (%d  %d)\n", b.x, b.y);
    printf("c : (%d  %d)\n", c.x, c.y);
}