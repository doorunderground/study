#include "Mtrx.h"

int main()
{
	const char* matrixDataFile = "input_data.txt"; 
	FILE* fin;
	double** dMA, ** dMB, ** dMC, ** dMD;
	int a_row_size, a_col_size;
	int b_row_size, b_col_size;
	int c_row_size, c_col_size;
	int d_row_size, d_col_size;

	fin = fopen(matrixDataFile, "r"); //외부파일을 읽어들임
	if (fin == NULL)
	{
		printf("Error in opening input.txt file !!\n");
		exit(-1);
	}
    
	fscanf(fin, "%d %d", &a_row_size, &a_col_size); //A배열의 행과 열을 받는 부분
	dMA = fgetDoubleMtrx(fin, a_row_size, a_col_size);
    printf("Input Matrix_A : \n");
	printMtrx(dMA, a_row_size, a_col_size); //A행렬 출력 

	fscanf(fin, "%d %d", &b_row_size, &b_col_size); //B배열의 행과 열을 받는 부분
	dMB = fgetDoubleMtrx(fin, b_row_size, b_col_size);
	printf("Input Matrix_B : \n");
	printMtrx(dMB, b_row_size, b_col_size); //B행렬 출력

	if ((a_row_size != b_row_size) || (a_col_size != b_col_size))
	{
		printf("Error in input matrix dimension: row_size and/or col_size are not equal !!\n");
		fclose(fin);
		return -1;
	}

	// MC = MA + MB
	c_row_size = a_row_size;
	c_col_size = b_col_size;
	dMC = createDoubleMtrx(c_row_size, c_col_size);
	addMtrx(dMA, dMB, dMC, a_row_size, a_col_size);
	printf("Matrix_C = A + B: \n");
	printMtrx(dMC, c_row_size, c_col_size); //A+B행렬 출력

	// MC = MA - MB
	d_row_size = a_row_size;
	d_col_size = b_col_size;
	dMD = createDoubleMtrx(d_row_size, d_col_size);
	subMtrx(dMA, dMB, dMD, a_row_size, a_col_size);
	printf("Matrix_D = A - B: \n");
	printMtrx(dMD, d_row_size, d_col_size); //A-B행렬 출력

	// MC = MA x MB
	c_row_size = a_row_size;
	c_col_size = b_col_size;
	dMC = createDoubleMtrx(c_row_size, c_col_size);
	multiplyMtrx(dMA, dMB, dMC, a_row_size, a_col_size, b_col_size);
	printf("Matrix_E = A* B:\n");
	printMtrx(dMC, c_row_size, c_col_size); //A*B행렬 출력
	
	//2차원 배열 동적할당 해제
	deleteDoubleMtrx(dMA, a_row_size, a_col_size); 
	deleteDoubleMtrx(dMB, b_row_size, b_col_size);
	deleteDoubleMtrx(dMD, d_row_size, d_col_size);
	deleteDoubleMtrx(dMC, c_row_size, c_col_size);
	fclose(fin);
}
