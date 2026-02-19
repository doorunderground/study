#include "Mtrx.h"

double ** createDoubleMtrx(int row_size, int col_size)
{
    double ** dM;
    dM = (double **)calloc(row_size, sizeof(double*));

    for(int r = 0; r < row_size; r++)
    {
        dM[r] = (double *)calloc(col_size, sizeof(double));
    }
    return dM;
}


void checkAddr_2D_Array(double **dM, int row_size, int col_size)
{
    printf("m = %p\n", dM);
    for (int r = 0; r < row_size; r++)
    {
        printf("m[%d]     = %p\n", r, dM[r]);
    }
    for (int c = 0; c < col_size; c++)
    {
        printf("m[%d][0]     = %p\n", c, dM[c][0]);
    }
    printf("\n");
}


void deleteDoubleMtrx(double **dM, int row_size, int col_size)
{
    for (int r = 0; r < row_size; r++)
    {
        free(dM[r]);
    }
    free(dM);
}


double ** fgetDoubleMtrx(FILE *fin, int row_size, int col_size)
{
    double **dM;
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


void printMtrx(double **dM, int row_size, int col_size)
{
    unsigned char a6 = 0xA6, a1 = 0xA1, a2 = 0xA2;
    unsigned char a3 = 0xA3, a4 = 0xA4, a5 = 0xA5; 

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


// void fprintMtrx(FILE *fout, double **mA, int row_size, int col_size)
// {

// }

double ** addMtrx(double **mA, double **mB, double **mR, int row_size, int col_size)
{
    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            mR[r][c] = mA[r][c] + mB[r][c];
        }
    }
    return mR;
}

double ** subMtrx(double **mA, double **mB, double **mR, int row_size, int col_size)
{
    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            mR[r][c] = mA[r][c] - mB[r][c];
        }
    }
    return mR;
}

double ** multiplyMtrx(double **mA, double **mB, double **mR, int row_size, int col_size, int size_k)
{
    for (int r = 0; r < row_size; r++)
    {
        for (int c = 0; c < col_size; c++)
        {
            mR[r][c] = 0;
            for (int k = 0; k < size_k; k++)
            {
                mR[r][c] += mA[r][k] * mB[k][c]; 
            }
        }
    }
    return mR;
}




