#include "Mtrx.h"

//  2차원 동적 할당               행          열
double ** createDoubleMtrx(int row_size, int col_size) 
{
    double** dM;
    dM = (double**)calloc(row_size, sizeof(double*));
    for (int r = 0; r < row_size; r++)
    {
        dM[r] = (double*)calloc(col_size, sizeof(double));
    }
    return dM;
}

/*
    dM -> [NULL] [NULL] [NULL] -> calloc (할당 + '0'초기화)
          dM[0]  dm[1]  dm[2]
    
    dM → [ ptr | ptr | ptr ]
           ↓     ↓     ↓
        [0][0][0][0]  ← dM[0]
        [0][0][0][0]  ← dM[1]
        [0][0][0][0]  ← dM[2]
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

