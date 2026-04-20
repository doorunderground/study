#include "Cmplx.h"

//  typedef struct
//  {
//	    double real;
//	    double imag; // imaginary
//	    double mgn;
//  } Cmplx;


Cmplx inputCmplx(Cmplx cmplx)
{
    scanf("%lf", &cmplx.real); //실수
    scanf("%lf", &cmplx.imag); //허수
    return cmplx;
}

void printCmplx(Cmplx c)
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

Cmplx cmplxSub(const Cmplx c1, const Cmplx c2) //뺄셈
{
    Cmplx cmplx;
    cmplx.real = c1.real - c2.real;
    cmplx.imag = c1.imag - c2.imag;
    cmplx.mgn = sqrt(pow(cmplx.real, 2) + pow(cmplx.imag, 2));
    return cmplx;
}

Cmplx cmplxMul(const Cmplx c1, const Cmplx c2) //곱셈
{
	Cmplx cmplx;
	cmplx.real = c1.real * c2.real - c1.imag * c2.imag;
	cmplx.imag = c1.imag * c2.imag + c1.real * c2.imag;
	cmplx.mgn = sqrt(pow(cmplx.real, 2.0) + pow(cmplx.imag, 2.0));

	return cmplx;
}

Cmplx cmplxDiv(const Cmplx c1, const Cmplx c2) //나눗셈
{
	Cmplx cmplx;
	cmplx.real = ((c1.real * c2.real) + (c1.imag * c2.imag)) / (pow(c2.real, 2.0) + pow(c2.imag, 2.0));
	cmplx.imag = ((c1.imag * c2.real) - (c1.real * c2.imag)) / (pow(c2.real, 2.0) + pow(c2.imag, 2.0));
	cmplx.mgn = sqrt(pow(cmplx.real, 2.0) + pow(cmplx.imag, 2.0));

	return cmplx;
}

void sortCmplx(Cmplx cmplxs[], int size) //퀵소팅
{
    _sortCmplx(cmplxs, size, 0, size - 1, 0);
}

void _sortCmplx(Cmplx cmplx[], int size, int left, int right, int level)
{
    int pI =0, newpI = 0;

    if (left >= right)
    {
        return;
    }
    else if (left < right)
    {
        pI = (left + right) / 2;
    }
    newpI = partition(cmplx, size, left, right, pI);

    if (left < (newpI - 1)) //왼쪽 정렬
    {
	    _sortCmplx(cmplx, size, left, newpI - 1, level + 1);
    }
    if ((newpI + 1) < right) //왼쪽 정렬 후 오른쪽 정렬
    {
	    _sortCmplx(cmplx, size, newpI + 1, right, level + 1);
    }
}

int partition(Cmplx cmplx[], int size, int left, int right, int pivotindex)
{
    int pivotValue;
    int newpI;
    Cmplx temp;

    pivotValue = cmplx[pivotindex].mgn; //가운데를 피봇 값으로 정렬
    
    temp = cmplx[pivotindex];  //swap
    cmplx[pivotindex] = cmplx[right];
    cmplx[right] = temp;

    newpI = left;
    for (int i = left; i <= (right - 1); i++)
    {
        if (cmplx[i].mgn < pivotValue)
        {
            temp = cmplx[i];
            cmplx[i] = cmplx[newpI];
            cmplx[newpI] = temp;

            newpI = newpI + 1;
        }
    }

    temp = cmplx[newpI];
    cmplx[newpI] = cmplx[right];
    cmplx[right] = temp;

    return newpI;
}

