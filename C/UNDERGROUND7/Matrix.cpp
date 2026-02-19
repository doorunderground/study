#include "Mtrx.h"

// 2차원 배열 동적 생성
double** createDoubleMtrx(int row_size, int col_size) //2차원 실수(double) 배열의 동적 생성 함수
{
    double ** dM;
    dM = (double **)calloc(row_size, sizeof(double *));

    for (int r = 0; r < row_size; r++)
    {
        dM[r] = (double*)calloc(col_size, sizeof(double)); 
    }
    return dM;
}

// 동적할당 free
void delete2DimDoubleArray(double **dM, int row_size, int col_size)
{  
    for (int r = 0; r < row_size; r++)
    {
        free(dM[r]);
    }
    free(dM);
}

// .txt파일에서 원소값을 가져오는 
double** fgetDoubleMtrx(FILE* fin, int row_size, int col_size)
{
    double **dM;
    double date;
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


// 행렬 출력
void printMtrx(double** dM, int row_size, int col_size)
{
    unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
    unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5; 

    // 0xA6A1 → ─ (가로선)
    // 0xA6A2 → │ (세로선)
    // 0xA6A3 → ┌ (왼쪽 위 모서리)
    // 0xA6A4 → ┐ (오른쪽 위 모서리)
    // 0xA6A5 → └ (왼쪽 아래 모서리)
    // 0xA6A6 → ┘ (오른쪽 아래 모서리)

    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            if ((r == 0) && (c == 0))
                printf("%c%c%7.2lf", a6, a3, dM[r][c]); // ┌
            else if ((r == 0) && c == (col_size -1))   
                printf("%7.2lf%c%c", dM[r][c], a6, a4); // ┐
            else if ((r > 0) && (r < row_size -1) && (c == 0))
                printf("%c%c%7.2lf", a6, a2, dM[r][c]); // │
            else if ((r > 0) && (r < row_size -1) && (c == col_size-1))
                printf("%7.2lf%c%c", dM[r][c], a6, a2); // │
            else if ((r == (row_size -1)) && (c == 0))
                printf("%c%c%7.2lf", a6, a5, dM[r][c]); // └
            else if ((r == (row_size -1)) && c ==(col_size -1))
                printf("%7.2lf%c%c", dM[r][c], a6, a6); // ┘    
            else
                printf("%7.2lf", dM[r][c]);
        }
        printf("\n");
    }
    printf("\n");
}


double ** addMtrx(double **mA, double **mB, int row_size, int col_size)
{
    double **MR;
    MR = createDoubleMtrx(row_size, col_size);
    
    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            MR[r][c] = mA[r][c] + mB[r][c];
        }
    }
    return MR;
}

double ** subMtrx(double **mA, double **mB, int row_size, int col_size)
{
    double **MR;
    MR = createDoubleMtrx(row_size, col_size);
    
    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            MR[r][c] = mA[r][c] - mB[r][c];
        }
    }
    return MR;
}


double ** mulMtrx(double **mA, double **mB, int row_size, int col_size, int size_k)
{
    double **MR;
    MR = createDoubleMtrx(row_size, col_size);
    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            MR[r][c] = 0;
            for (int k = 0; k < size_k; k++)
                MR[r][c] += mA[r][k] * mB[k][c];
        }
    }
    return MR;
}


