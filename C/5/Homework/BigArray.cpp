#include "BigArray.h"

void genBigRandArray(int* array, int size) // 난수 생성
// size > 10,000 이상
{
    int *flag;
    unsigned long num;
    int count = 0;

    srand(time(0));

    flag = (int *)calloc(size, sizeof(int));

    while (count < size)
    {
        num = (rand() << 15) | rand();
        num = num % size;

        if (flag[num] == 1)
            continue;

        flag[num] = 1;
        array[count++] = num;
    }

    free(flag);
}


void suffleBigArray(int* array, int size)
{
    int index1, index2; // 랜덤으로 뽑은 두 위치(index)
    int temp = 0; // swap

    srand((unsigned)time(NULL));

    for (int i = 0; i < size / 2; i++)
    {
        index1 = (((unsigned long)rand() << 15) | rand()) % size;
        index2 = (((unsigned long)rand() << 15) | rand()) % size;

        temp = array[index1];
        array[index1] = array[index2];
        array[index2] = temp;
    }
}


void printBigArraySample(int* array, int size, int line_size, int num_sample_lines)
// line_size = 10, num_sample_line = 2
{
    int count = 0;

    if (size < 50)
    {
        for (int i = 0; i < size; i++)
        {
            if (((i % 10) == 0) && (i != 0))
                printf("\n");
            printf("%8d", array[count++]);
        }
        printf("\n");
        return;
    }

    for (int i = 0; i < num_sample_lines; i++)
    {
        for (int j = 0; j < line_size; j++)
        {
            printf("%8d", array[count++]);
        }
        printf("\n");
    }
    printf(". . . . . . . . . . \n");


    count = size - (num_sample_lines * line_size);
    for (int i = 0; i < num_sample_lines; i++)
    {
        for (int j = 0; j < line_size; j++)
        {
            printf("%8d", array[count++]);
        }
        printf("\n");
    }
}


void fprintBigArraySample(FILE* fout, int* array, int size, int line_size, int num_sample_lines)
// line_size = 10, num_sample_line = 2
{
    int count = 0;
    fprintf(fout, "Total (%3d) interger data : \n", size);
    if (size < 50)
    {
        for (int i = 0; i < size; i++)
        {
            if (((i % 10) == 0) && (i !=0))
                fprintf(fout, "\n");
            fprintf(fout, "%8d", array[count++]);
        }
        fprintf(fout, "\n");
        return ;
    }

    for (int i = 0; i < num_sample_lines; i++)
    {
        for (int j = 0; j < line_size; j++)
        {
            fprintf(fout, "%8d", array[count++]);
        }
        fprintf(fout, "\n");
    }
    fprintf(fout, ". . . . . . . . . . \n");


    for (int i = 0; i < num_sample_lines; i++)
    {
        for (int j = 0; j < line_size; j++)
        {
            fprintf(fout, "%8d", array[count++]);
        }
        fprintf(fout, "\n");
    }
    fprintf(fout, "\n");
}


