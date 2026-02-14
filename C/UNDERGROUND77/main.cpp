#include "Mtrx.h"

void checkAddress_2DimArray_for_Matrix();
void test_2D_DynamicArray_FileIO();
void test_Matrix_Addition_Subtraction();
void test_Matrix_Multiplication();

int main()
{
	int menu;
	while (true)
	{
		printf("Testing Matrix Operations with 2-Dimensional Dynamic Array\n");
		printf("1: Check addressed of 2-Dim array for Matrix\n");
		printf("2: Test 2-D Dynamic Array Creation for Matrix with File I/O\n");
		printf("3: Test Matrix Addition, Subtraction\n");
		printf("4: Test Matrix Multiplications\n");
		printf("-1: Quit\n");
		printf("Input menu (-1 to quit): ");
		scanf("%d", &menu);
		
        if (menu == -1)
		{
			break;
		}

		printf("\n");
		switch (menu)
		{
		case 1:
			checkAddress_2DimArray_for_Matrix();
			break;
		case 2:
			test_2D_DynamicArray_FileIO();
			break;
		case 3:
			test_Matrix_Addition_Subtraction();
			break;
		case 4:
			test_Matrix_Multiplication();
			break;
		}
	}
}


void checkAddress_2DimArray_for_Matrix() //2차원 배열의 원소의 주소
{
	int m[3][3] = { 10,20,30,40,50,60,70,80,90 };
	printf("m=%10p\n", m);
	printf("m[0]=%10p\n", m[0]);
	printf("m[1]=%10p\n", m[1]);
	printf("m[2]=%10p\n", m[2]);
	printf("&m[0][0]=%10p\n", &m[0][0]);
	printf("&m[1][0]=%10p\n", &m[1][0]);
	printf("&m[2][0]=%10p\n\n", &m[2][0]);
}

void test_2D_DynamicArray_FileIO()
{
	const char* matrixDataFile = "C:\\study\\C\\UNDERGROUND11\\mtrxInputData.txt";
	FILE* fin;
	int a_row_size, a_col_size;
	int b_row_size, b_col_size;
	double** dMA, ** dMB;
	fin = fopen(matrixDataFile, "r");
	if (fin == NULL)
	{
		printf("error!\n");
		exit(-1);
	}

	fscanf(fin, "%d %d", &a_row_size, &a_col_size);
	dMA = fgetDoubleMtrx(fin, a_row_size, a_col_size);
	printf("Input Matrix_A (%d x %d) : \n", a_row_size, a_col_size);
	printMtrx(dMA, a_row_size, a_col_size);
	printf("\n");

	fscanf(fin, "%d %d", &b_row_size, &b_col_size);
	dMB = fgetDoubleMtrx(fin, b_row_size, b_col_size);
	printf("Input Matrix_B (%d x %d) : \n", b_row_size, b_col_size);
	printMtrx(dMB, b_row_size, b_col_size);
	printf("\n");

	deleteDoubleMtrx(dMA, a_row_size, a_col_size);
	deleteDoubleMtrx(dMB, b_row_size, b_col_size);
	fclose(fin);
}

void test_Matrix_Addition_Subtraction()
{
	const char* matrixDataFile = "C:\\study\\C\\UNDERGROUND11\\mtrxInputData2.txt";
	FILE* fin;
	double** dMA, ** dMB, ** dMC, ** dMD;
	int a_row_size, a_col_size;
	int b_row_size, b_col_size;
	int c_row_size, c_col_size;
	int d_row_size, d_col_size;
	fin = fopen(matrixDataFile, "r");
	if (fin == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}
	fscanf(fin, "%d %d", &a_row_size, &a_col_size);
	dMA = fgetDoubleMtrx(fin, a_row_size, a_col_size);
	printf("Input Matrix_A ( %d x %d) : \n", a_row_size, a_col_size);
	printMtrx(dMA, a_row_size, a_col_size);
	printf("\n");
	fscanf(fin, "%d %d", &b_row_size, &b_col_size);
	dMB = fgetDoubleMtrx(fin, b_row_size, b_col_size);
	printf("Input Matrix_B ( %d x %d) : \n", b_row_size, b_col_size);
	printMtrx(dMB, b_row_size, b_col_size);
	printf("\n");
	if ((a_row_size != b_row_size) || (a_col_size != b_col_size))
	{
		printf("Error in input matrix dimension: row_size and/or col_size are not equal !!\n");
		fclose(fin);
		return;
	}
	// MC = MA + MB
	c_row_size = a_row_size;
	c_col_size = b_col_size;
	dMC = createDoubleMtrx(c_row_size, c_col_size);
	addMtrx(dMA, dMB, dMC, a_row_size, a_col_size);
	printf("Matrix_C (%d x %d) = Matrix_A + Matrix_B : \n", c_row_size, c_col_size);
	printMtrx(dMC, c_row_size, c_col_size);
	printf("\n");
	// MC = MA - MB
	d_row_size = a_row_size;
	d_col_size = b_col_size;
	dMD = createDoubleMtrx(d_row_size, d_col_size);
	subMtrx(dMA, dMB, dMD, a_row_size, a_col_size);
	printf("Matrix_D (%d x %d) = Matrix_A - Matrix_B : \n",
		d_row_size, d_col_size);
	printMtrx(dMD, d_row_size, d_col_size);
	printf("\n");
	deleteDoubleMtrx(dMA, a_row_size, a_col_size);
	deleteDoubleMtrx(dMB, b_row_size, b_col_size);
	deleteDoubleMtrx(dMD, d_row_size, d_col_size);
	deleteDoubleMtrx(dMC, c_row_size, c_col_size);
	fclose(fin);

}
void test_Matrix_Multiplication()
{
	const char* matrixDataFile = "C:\\study\\C\\UNDERGROUND11\\mtrxInputData.txt";
	FILE* fin;
	int a_row_size, a_col_size;
	int b_row_size, b_col_size;
	int c_row_size, c_col_size;
	double** dMA, ** dMB, ** dMC;
	fin = fopen(matrixDataFile, "r");
	if (fin == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}
	fscanf(fin, "%d %d", &a_row_size, &a_col_size);
	dMA = fgetDoubleMtrx(fin, a_row_size, a_col_size);
	printf("Input Matrix_A ( %d x %d) : \n", a_row_size, a_col_size);
	printMtrx(dMA, a_row_size, a_col_size);
	printf("\n");

	fscanf(fin, "%d %d", &b_row_size, &b_col_size);
	dMB = fgetDoubleMtrx(fin, b_row_size, b_col_size);
	printf("Input Matrix_B ( %d x %d) : \n", b_row_size, b_col_size);
	printMtrx(dMB, b_row_size, b_col_size);
	printf("\n");

	// MC = MA x MB
	c_row_size = a_row_size;
	c_col_size = b_col_size;
	dMC = createDoubleMtrx(c_row_size, c_col_size);
	multiplyMtrx(dMA, dMB, dMC, a_row_size, a_col_size, b_col_size);
	printf("Matrix_C (%d x %d) = Matrix_A x Matrix_B : \n", c_row_size, c_col_size);
	printMtrx(dMC, c_row_size, c_col_size);
	printf("\n");

	deleteDoubleMtrx(dMA, a_row_size, a_col_size);
	deleteDoubleMtrx(dMB, b_row_size, b_col_size);
	deleteDoubleMtrx(dMC, c_row_size, c_col_size);
	fclose(fin);
}

