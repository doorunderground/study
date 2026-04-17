#ifndef MTRX_H
#define MTRX_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double** createDoubleMtrx(int row_size, int col_size); 
void checkAddr_2D_Array(double** dM, int row_size, int col_size);
void deleteDoubleMtrx(double** dM, int row_size, int col_size);
double** fgetDoubleMtrx(FILE* fin, int row_size, int col_size); 
void printMtrx(double** dM, int row_size, int col_size); 

void addMtrx(double** mA, double** mB, double** MR, int row_size, int col_size); 
void subMtrx(double** mA, double** mB, double** MR, int row_size, int col_size); 
void multiplyMtrx(double** mA, double** mB, double** MR, int row_size, int size_k, int col_size); 

#endif
