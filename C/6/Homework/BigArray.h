/* BigArray.h */

#ifndef BIG_ARRAY_H
#define BIG_ARRAY_H

#include <stdio.h>

void printArray(int *array, int size, int line_size);
void fprintArray(FILE *fout, int *array, int size, int line_size);
void printBigArraySample(int *array, int size, int items_per_line, int num_sample_lines);
void fprintBigArraySample(FILE *fout, int *array, int size, int item_per_line, int num_sample_lines);
void genBigRandArray(int *array, int size, int base);
void suffleArray(int *array, int size);
int sequentialSearch(int *array, int size, int key_to_search);
int binarySearch(int *array, int size, int key);
void selectionSort(int *array, int size);
void quickSort(int *array, int size);
void getArrayStatistics(int *array, int size);
void fgetArrayStatistics(FILE *fout, int *array, int size);

#endif