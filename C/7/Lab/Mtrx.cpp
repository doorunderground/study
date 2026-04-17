#include "Mtrx.h"

double** createDoubleMtrx(int row_size, int col_size)
{
    double** dM;
    dM = (double**)calloc(row_size, sizeof(double*));
    for (int r = 0; r < row_size; r++)
    {
        dM[r] = (double*)calloc(col_size, sizeof(double));
    }
    return dM;
}

//  동적 배열이 메모리에 어떻게 저장되는지 확인
void checkAddr_2D_Array(double** dM, int row_size, int col_size) 
{
	printf("m = %p\n", dM);
	
    for (int i = 0; i < row_size; i++)
	{
		printf("dM[%d]   = %p\n", i, (void*)dM[i]);
	}
	for (int i = 0; i < row_size; i++)
	{
		for(int j = 0; j < col_size; j++)
            {
                printf("&dM[%d][%d] = %p\n", i , j, (void*)&dM[i][j]);
            }
	}
	printf("\n");
}

/*
    동적 배열 dM
    - for 1
    dM[0] = 0x00600500   ← 1행 데이터 위치
    dM[1] = 0x00600800   ← 2행 데이터 위치 (500과 멀리 떨어짐)
    dM[2] = 0x00600300   ← 3행 데이터 위치 (순서도 뒤죽박죽 가능)

    - for 2
    &dM[0][0] = 0x00600500
    &dM[0][1] = 0x00600508   ← +8 (double은 8바이트)
    &dM[0][2] = 0x00600510   ← +8
    &dM[1][0] = 0x00600800   ← 갑자기 다른 위치!
    &dM[1][1] = 0x00600808

    행들이 연속되지 않음을 확인하는 용도
    같은 행 안에서만 주소가 8씩 증가, But 행 간에는 불연속
*/

//  2차원 동적 할당 해제
void deleteDoubleMtrx(double** dM, int row_size, int col_size)
{
    for (int r = 0; r < row_size; r++)
    {
        free(dM[r]);
    }
    free(dM);
}

// .txt 파일에서 원소값 받아옴
double** fgetDoubleMtrx(FILE * fin, int row_size, int col_size)
{
    double** dM;
    double data;
    dM = createDoubleMtrx(row_size, col_size);
    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            fscanf(fin, "%lf", &dM[r][c]);
        }
    }
    return dM;
}

void printMtrx(double** dM, int row_size, int col_size)
{
	for (int i = 0; i < row_size; i++)
	{
		for (int j = 0; j < col_size; j++)
		{
			if (j == 0)
				printf("|%7.2lf", dM[i][j]);
			else if (j == col_size - 1)
				printf("%7.2lf |", dM[i][j]);
			else
				printf("%7.2lf", dM[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void addMtrx(double** mA, double** mB, double** MR, int row_size, int col_size)
{
    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            MR[r][c] = mA[r][c] + mB[r][c];
        }
    }
}

void subMtrx(double** mA, double** mB, double** MR, int row_size, int col_size)
{
    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            MR[r][c] = mA[r][c] - mB[r][c];
        }
    }
}

void multiplyMtrx(double** mA, double** mB, double** MR, int row_size, int size_k, int col_size)
{
    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            MR[r][c] = 0;
            for (int k = 0; k < size_k; k++)
            {
                MR[r][c] += mA[r][k] * mB[k][c];
            }
        }
    }
}

