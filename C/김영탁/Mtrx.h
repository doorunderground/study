/* Mtrx.h*/
#ifndef MTRX_H
#define MTRX_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double** createDoubleMtrx(int row_size, int col_size); //2차원 실수(double) 배열의 동적 생성 함수

void delete2DimDoubleArray(double **dM, int row_size, int col_size);

double** fgetDoubleMtrx(FILE* fin, int row_size, int col_size);

void print2DimDoubleArray(double **dM, int row_size, int col_size);
void printMtrx(double** dM, int row_size, int col_size); //행렬 출력

double ** addMtrx(double **A, double **B, int row_size, int col_size);
double ** subMtrx(double **A, double **B, int row_size, int col_size);
double ** mulMtrx(double **A, double **B, int row_size, int col_size, int size_k);

#endif