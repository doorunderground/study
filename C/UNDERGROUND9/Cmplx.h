/* Cmplx.h */
#ifndef CMPLX_H
#define CMPLX_

typedef struct{
    double real;
    double imag;
    double mgn;
} Cmplx;

Cmplx inputCmplx();
void printCmplx(const Cmplx c);
Cmplx cmplxAdd(const Cmplx c1, const Cmplx c2);
Cmplx cmplxSub(const Cmplx c1, const Cmplx c2);
Cmplx cmplxMul(const Cmplx c1, const Cmplx c2);
Cmplx cmplxDiv(const Cmplx c1, const Cmplx c2);
void sortCmplx(Cmplx cmplxs[], int size);

#endif