#include <stdio.h>
#include <conio.h>
#include <math.h>
#include "BigArray.h"

#define ESC 0x1B
#define MAX_NUM_DATA 100

void arrayStatistics_basicArray(FILE* fout);
void arrayStatistics_externArray(FILE* fout);
void arrayStatistics_fileDataArray(FILE* fout);
void arrayStatistics_inputArray(FILE* fout);
void arrayStatistics_genBigRandArray(FILE* fout);

#define Data_Input_File "Data_input.txt" 
#define Data_Output_File "Data_output.txt"

int main(int argc, char argv[]) 
{
	FILE* fout;
	char menu;

	fout = fopen(Data_Output_File, "w"); // 작성.txt 출력
	if (fout == NULL) {
		printf("Error in creation of %s !!\n", Data_Output_File);
		return -1;
	}

	while (1) {
		printf("\nTest Array Hadling (1: data_array; 2: extern_array; 3: data_file; 4: data_input; 5: genBigRandArray; ESC: terminate) : ");
		menu = _getche();
		if (menu == ESC)
			break;
		switch (menu) {
		case '1':
			arrayStatistics_basicArray(fout); //소스코드에 입력되어있는 배열
			break;
		case '2':
			arrayStatistics_externArray(fout); //외부 .txt을 위한 배열
			break;
		case '3':
			arrayStatistics_fileDataArray(fout); //.txt파일에서 받아온 배열
			break;
		case '4':
			arrayStatistics_inputArray(fout); //키보드로 입력받은 배열
			break;
		case '5':
			arrayStatistics_genBigRandArray(fout); //랜덤 생성 난수 배열
			break;
		default:
			break;
		}
	}
	fclose(fout);
	return 0;
}

void arrayStatistics_basicArray(FILE* fout) 
{
	int num_data = 10;
	int data_array[MAX_NUM_DATA] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	printf("\nArrayStatistics_basicArray .....\n");
	fprintf(fout, "\nArrayStatistics_basicArray .....\n");
	printBigArraySample(data_array, num_data, 10, 3);
	fprintBigArraySample(fout, data_array, num_data, 10, 3);
	getArrayStatistics(data_array, num_data);
	fgetArrayStatistics(fout, data_array, num_data);
	printf("arrayStatistics_basicArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
}

void arrayStatistics_externArray(FILE* fout) 
{
	int num_data = 0, num = 0;
	extern int ex_data_array[MAX_NUM_DATA]; //외부파일 배열
	printf("\nArrayStatistics externArray .....\n");
	fprintf(fout, "\nArrayStatistics externArray .....\n");

	while (num != -1) {
		num = ex_data_array[num_data];
		if (num != -1)
			num_data++;
	}
	printBigArraySample(ex_data_array, num_data, 10, 3);
	fprintBigArraySample(fout, ex_data_array, num_data, 10, 3);
	getArrayStatistics(ex_data_array, num_data);
	fgetArrayStatistics(fout, ex_data_array, num_data);
	printf("arrayStatistics_externArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
}

void arrayStatistics_fileDataArray(FILE* fout) {
	int num_data = 0, num = 0;
	int data_array[20];
	FILE* fin;

	fin = fopen(Data_Input_File, "r");
	printf("\nArrayStatistics_fileDataArray .....\n");
	fprintf(fout, "\nArrayStatistics_fileDataArray ......\n");

	while (num != -1) {
		fscanf(fin, "%d", &num);
		if (num != -1)
			data_array[num_data++] = num;  //데이터 파일 입력 기능
	}
	printBigArraySample(data_array, num_data, 10, 3);
	fprintBigArraySample(fout, data_array, num_data, 10, 3);
	getArrayStatistics(data_array, num_data);
	fgetArrayStatistics(fout, data_array, num_data);
	printf("arrayStatistics_fileDataArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
}

void arrayStatistics_inputArray(FILE* fout) {
	int num_data = 0;
	int data_array[MAX_NUM_DATA] = { 0 };

	printf("\nArrayStatistics_inputArray .....\n");
	fprintf(fout, "\nArrayStatistics_inputArray .....\n");
	printf("Please input the number of integers (less than %d) = ", MAX_NUM_DATA);
	scanf("%d", &num_data);
	printf("Input %d integer data : \n", num_data);

	for (int i = 0; i < num_data; i++) {
		scanf("%d", &data_array[i]); // 키보드를 사용한 데이터 입력
	}
	printBigArraySample(data_array, num_data, 10, 3);
	fprintBigArraySample(fout, data_array, num_data, 10, 3);
	getArrayStatistics(data_array, num_data);
	fgetArrayStatistics(fout, data_array, num_data);
	printf("arrayStatistics_inputArray - completed. Result is also stored in output file(%s).\n", Data_Output_File);
}

void arrayStatistics_genBigRandArray(FILE* fout) 
{
	int num_data;
	int* dyn_array = NULL;
	printf("\nArrayStatistics_genBigRandArray .....\n");
	fprintf(fout, "\nArrayStatistics_genBigRandArray .....\n");
	printf("Big Array Size (more than 50000) = ");
	scanf("%d", &num_data);
	printf("Creating big random integer array (size: %d)\n", num_data);

	dyn_array = (int*)calloc(num_data, sizeof(int)); //동적할당

	if (dyn_array == NULL) {
		printf("Error in dynamic creation of big_array (size = %d) !!!", num_data);
		exit;
	}
	genBigRandArray(dyn_array, num_data);
	printBigArraySample(dyn_array, num_data, 10, 2);
	fprintBigArraySample(fout, dyn_array, num_data, 10, 2);
	getArrayStatistics(dyn_array, num_data);
	fgetArrayStatistics(fout, dyn_array, num_data);
	printf("arrayStatistics_genBigRandArray - completed. Result is also stored in output file (%s). \n", Data_Output_File);
	free(dyn_array);
}
