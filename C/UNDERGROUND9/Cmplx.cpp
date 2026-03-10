#include "Cmplx.h"
#include <stdio.h>
#include <math.h>

typedef struct{
    double real;
    double imag;
    double mgn;
} Cmplx;

Cmplx inputCmplx(Cmplx cmplx)
{
    scanf("%lf", &cmplx.real); //실수부
    scanf("%lf", &cmplx.imag); //허수부

    return cmplx
}

void printCmplx(const Cmplx c)
{
    printf("(%.3lf + j%.3lf (magnitude %.3lf))", c.real, c.imag, c.mgn);
}

Cmplx cmplxAdd(const Cmplx c1, const Cmplx c2) //덧셈
{
    Cmplx cmplx;
    cmplx.real = c1.real + c2.real;
    cmplx.imag = c1.imag + c2.imag;
    cmplx.mgn = sqrt(pow(cmplx.real, 2) + pow(cmplx.imag, 2));
    return cmplx;
}

Cmplx cmplxSub(const Cmplx c1, const Cmplx c2)
{
    Cmplx cmplx;
    cmplx.real = c1.real - c2.real;
    cmplx.imag = c1.imag - c2.imag;
    cmplx.mgn = sqrt(pow(cmplx.real, 2) + pow(cmplx.imag, 2));

    return cmplx;
}

Cmplx cmplxMul(const Cmplx c1, const Cmplx c2)
{
    Cmplx cmplx;
    cmplx.real = c1.real * c2.real - c1.imag * c2.imag;
    cmplx.imag = c1.imag * c2.imag + c1.real * c2.imag;
    cmplx.mgn = sqrt(pow(cmplx.real, 2.0) + pow(cmplx.imag, 2.0));

    return cmplx;
}

Cmplx cmplxDiv(const Cmplx c1, const Cmplx c2)
{
    Cmplx cmplx;
    cmplx.real = ((c1.real * c2.real) + (c1.imag * c2.imag)) / (pow(c2.real, 2.0) + pow(c2.imag, 2.0));
    cmplx.imag = ((c1.imag * c2.real) - (c1.real * c2.imag)) / (pow(c2.real, 2.0) + pow(c2.imag, 2.0));
    cmplx.mgn = sqrt(pow(cmplx.real, 2.0) + pow(cmplx.imag, 2.0));

    return cmplx;
}


void sortCmplx(Cmplx cmplxs[], int size);