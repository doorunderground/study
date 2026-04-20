#ifndef CMPLX_H
#define CMPLX_H

#include <stdio.h>
#include <math.h>

typedef struct
{
	double real;
	double imag; // imaginary
	double mgn;
} Cmplx;

Cmplx inputCmplx(Cmplx cmplx);
void printCmplx(const Cmplx c);
Cmplx cmplxAdd(const Cmplx c1, const Cmplx c2); //const -> 함수 내부에서 그 복사본을 수정하지 못하게 막음
Cmplx cmplxSub(const Cmplx c1, const Cmplx c2);
Cmplx cmplxMul(const Cmplx c1, const Cmplx c2);
Cmplx cmplxDiv(const Cmplx c1, const Cmplx c2);
void sortCmplx(Cmplx cmplxs[], int size);
int partition(Cmplx cmplx[], int size, int left, int right, int pivotindex);
void _sortCmplx(Cmplx cmplx[], int size, int left, int right, int level);

#endif // CMPLX_H