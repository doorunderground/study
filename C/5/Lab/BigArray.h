#ifndef BIGARRAY_H
#define BIGARRAY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

void printBigArraySample(int* array, int size, int line_size, int num_sample_lines);
void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_sample_lines); 

void genBigRandArray(int* array, int size); // 난수 생성 
void shuffleArray(int* array, int size); // 무작위

void getArrayStatistics(int* array, int size); // 배열의 최소, 최대, 평균, 분산, 표준편차를 위한 구하고 출력
void fgetArrayStatistics(FILE* fout, int* array, int size); 

#endif
