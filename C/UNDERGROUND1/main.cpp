/*
    7.2 파일 입력, 2차원 배열의 동적 생성, 행렬의 덧셈, 뺄셈, 곱셈 연산
 
    - 행렬의 행의 크기와 열의 크기를 나타내는 정수 데이터 2개와 (행의 크기 x 열의
크기) 개수의 double 자료형 데이터를 포함하고 있는 입력 데이터 파일
(input_data.txt)를 읽어 2차원 배열을 동적으로 생성하는 함수 double **

inputMtrx(FILE *fin, int *row_size, int * col_size)를 작성하라. 
동적으로 생성된 dM, row_size와 col_size는 return-by-pointer 방식으로 호출한 함수에게 전달할 것.

1. void deleteMtrx(double **ppM, int row_size, int col_size)를 작성하라.
2. void printMtrx(double **ppM, int row_size, int col_size)를 작성하라.
각 배열 원소의 값은 소숫점 이하 2자리 까지 출력할 것.

double ** addMtrx(double **A, double **B, int row_size, int col_size);
double ** subMtrx(double **A, double **B, int row_size, int col_size);
double ** mulMtrx(double **A, double **B, int row_size, int col_size);

파일로 부터 행렬 A와 B를 입력받고,  덧셈, 뺄셈, 곱셈 연산

*/

#include "Mtrx.h"

int main()
{
    const char * matrixDataFile = "C:\\study\\C\\input_data.txt";
    //파일 이름 같은 변하면 안 되는 문자열에 const를 붙여서,
    //의도치 않은 변경을 차단하는 것    
    FILE * fin;
    double **dMA, **dMB, **dMC, ** dMD, **dME;
    int a_row_size, a_col_size;
    int b_row_size, b_col_size;
    int c_row_size, c_col_size;
    int d_row_size, d_col_size;
    int e_row_size, e_col_size;

    fin = fopen(matrixDataFile, "r");
    if (fin == NULL)
    {
        printf("Error in opening input.txt file \n");
        exit(-1);
    }

    fscanf(fin, "%d %d", &a_row_size, &a_col_size);
    dMA = fgetDoubleMtrx(fin, a_row_size, a_col_size); //행렬 
    printf("Input Matrix A : \n");
    printMtrx(dMA, a_row_size, a_col_size); //행렬 출력

    fscanf(fin, "%d %d", &b_row_size, &b_col_size);
    dMB = fgetDoubleMtrx(fin, b_row_size, b_col_size); //행렬 
    printf("Input Matrix B : \n");
    printMtrx(dMB, b_row_size, b_col_size); //행렬 출력

    if ((a_row_size != b_row_size) || (a_col_size != b_col_size))
    {
        printf("Error in input matrix dimension: row_size and/or col_size are not equal !!\n");
        fclose(fin);
        return 0;
    }
    
    
    // MC = MA + MB
    c_row_size = a_row_size;
    c_col_size = b_col_size;

    dMC = addMtrx(dMA, dMB, c_row_size, c_col_size);
    printf("Matrix C = A + B : \n");
    printMtrx(dMC, c_row_size, c_col_size);

    // MD = MA - MB
    d_row_size = a_row_size;
    d_col_size = b_col_size;

    dMD = subMtrx(dMA, dMB, d_row_size, d_col_size);
    printf("Matrix D = A - B : \n");
    printMtrx(dMD, d_row_size, d_col_size);

    // ME = MA x MB
    e_row_size = a_row_size;
    e_col_size = b_col_size;

    dME = mulMtrx(dMA, dMB, e_row_size, e_col_size, a_col_size);
    printf("Matrix E = A x B : \n");
    printMtrx(dME, e_row_size, e_col_size);

    //동적 할당 해제
    delete2DimDoubleArray(dMA, a_row_size, a_col_size);
    delete2DimDoubleArray(dMB, b_row_size, b_col_size);
    delete2DimDoubleArray(dMC, c_row_size, c_col_size);
    delete2DimDoubleArray(dMD, d_row_size, d_col_size);
    delete2DimDoubleArray(dME, e_row_size, e_col_size);
    return 0;


//double ** addMtrx(double **A, double **B, int row_size, int col_size);

}


//double ** addMtrx(double **mA, double **mB, int row_size, int col_size)
//double ** subMtrx(double **mA, double **mB, int row_size, int col_size)
//void printMtrx(double** dM, int row_size, int col_size)
//double ** mulMtrx(double **mA, double **mB, int row_size, int col_size, int size_k)