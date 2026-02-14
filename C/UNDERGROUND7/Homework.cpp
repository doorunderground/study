// #include <stdio.h>
// #include <stdlib.h>
// #include "Mtrx.h"

// /*
// 두 개의 double 자료형 데이터를 함수의 인수로 전달하고, 그 평균값을 계산하여
// double 자료형으로 반환하는 간단한 average()함수를 call-by-value, call-by-pointer,
// call-by-reference 방식으로 각각 구현하고, 정상적으로 실행되는 것을 확인하라.
// */

// double average_value(double x, double y) //call value
// {
//     double avg = 0.0, sum;
//     sum = x + y;
//     avg = sum / 2.0;

//     return avg;
// }
// void average_pointer(double *px, double *py, double *pavg) //call pointer
// {
//     double sum;
//     sum = *px + *py;
//     *pavg = sum / 2.0;

//     printf("%lf \n", *pavg);
// }


// void average_reference(double &x, double &y, double &avg) //call reference
// {
//     double sum;
//     sum = x + y;
//     avg = sum / 2.0;

//     printf("%lf \n", avg);
// }


// int main()
// {
//     double x = 3, y = 5;
//     double v1;
//     double pavg;
//     double avg;

//     v1 = average_value(x, y);
//     printf("%lf \n", v1);

//     average_pointer(&x, &y, &pavg);
    
//     average_reference(x, y, avg);

//     return 0;
// }
