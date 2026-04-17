#ifndef BigArray_H
#define BigArray_H

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<math.h>
#include<Windows.h>
#include<conio.h>

void genBigRandArray(int* array, int size);
void suffleBigArray(int* array, int size);
void printBigArraySample(int* array, int size, int line_size, int num_sample_lines);
void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_sample_lines);
#endif