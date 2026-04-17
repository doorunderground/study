/*
    정수형 난수 배열 생성
*/

#include "BigArray.h"

int main()
{
	FILE* fout;
	int* array = NULL;
	int size;
	fout = fopen("output.txt", "w");
	printf("Input size of big array (more than 100000) =  ");
	scanf("%d", &size);
	array = (int*)calloc(size, sizeof(int)); //동적 할당

	genBigRandArray(array, size); // 난수 생성 함수
	//suffleBigArray(array, size); 
	printBigArraySample(array, size, 10, 2);
	fprintBigArraySample(fout, array, size, 10, 2);

    return 0;
}