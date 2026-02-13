// /*

//     7.1 함수의 인수 전달 방식에 대한 비교
//  - 두 개의 double 자료형 데이터를 함수의 인수로 전달하고, 그 평균값을 계산하여
//   double 자료형으로 반환하는 간단한 average()함수를 call-by-value, call-by-pointer,
//   call-by-reference 방식으로 각각 구현하고, 정상적으로 실행되는 것을 확인하라.

//   double average_value(double x, double y); // call-by-value
//   void average_pointer(double *px, double *py, double *pavg); // call-by-pointer
//   void average_reference(double &x, double &y, double &avg); // call-by-reference

//  - 이 세가지 함수 인수 전달 방법의 장점과 단점을 비교하여 설명하라

// */


// //double **create2DimDoubleArray(int row_size, int col_size);
// //void delete2DimDoubleArray(double **dM, int row_size, int col_size);
// //void fget2DimDoubleArray(FILE *fp, double **dM, int row_size, int col_size);
// //void print2DimDoubleArray(double **dM, int row_size, int col_size);
// //double getRow_Avg(double **dM, int row, int num_cols);
// //double getTotal_Avg(double **dM, int num_cols);

// /* Mtrx.cpp */
// #include <stdio.h>
// #include <stdlib.h>
// #include "Mtrx.h"

// // row x col 2차원 double 배열을 만들어서 주소를 반환
// double **create2DimDoubleArray(int row_size, int col_size)
// {
//     double **ppDA;

//     ppDA = (double **)calloc(row_size, sizeof(double*));
//     // double *를 row_size만큼 할당 -
//     for (int r = 0; r < row_size; r++)
//     {
//         ppDA[r] = (double *)calloc(col_size, sizeof(double));
//     }

//     return ppDA;
// }

// void delete2DimDoubleArray(double **dM, int row_size, int col_size)
// {
//     for (int r = 0; r < row_size; r++)
//     {
//         free(dM[r]);
//     }
//     free(dM);
// }


// /*
// 3 4
// 1.1 2.2 3.3 4.4
// 5.5 6.6 7.7 8.8
// 9.9 10.1 11.2 12.3

// 파일에서 읽은 숫자를 이미 할당된 2차원 배열에 채워 넣는 함수
// */
// void fget2DimDoubleArray(FILE *fp, double **dM)
// {
//     double data = 0.0;
//     int row_size, col_size;

//     if (fp == NULL)
//     {
//         printf(" Error in get2DimDouleArray() - file pointer is Null \n");
//         exit(-1);
//     }
//     fscanf(fp, "%d %d", &row_size, &col_size);
//     for (int r = 0; r < row_size; r++)
//         for (int c = 0; c < col_size; c++)
//     {
//         if (fscanf(fp, "%lf", &data) != EOF)
//             dM[r][c] = data;
//     }
// }

// void print2DimDoubleArray(double **mA, int row_size, int col_size)
// {
//     for (int r = 0; r < row_size; r++)
//     {
//         for (int c = 0; c < col_size; c++)
//         {
//             printf("%8.2lf", mA[r][c]);
//         }
//         printf("\n");
//     }
// }

// // 행(row)의 평균을 구하는
// double getRow_Avg(double **array, int row, int col_size)
// {
//     double sum = 0.0, row_avg;

//     for (int c = 0; c < col_size; c++)
//     {
//         sum += array[row][c];
//     }

//     row_avg = sum / (double) col_size;
//     return row_avg;
// }

// // 2차원 배열 전체의 원소의 평균을 구하는
// double getTotal_Avg(double **dM, int row_size, int col_size)
// {
//     double sum = 0.0, avg;

//     for (int r = 0; r < row_size; r++)
//     {
//         for (int c = 0; c < col_size; c++)
//         {
//             sum += dM[r][c];
//         }
//     }

//     avg = sum / (double) (row_size * col_size);
//     return avg;
// }


// // Homework7
// // 