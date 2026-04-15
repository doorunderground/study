#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "BigArray.h"
#include "String_Algorithms.h"

#define ESC 0x1B
#define NUM_DATA 20
#define LINE_SIZE 20

void testSequentialSearch(FILE *fout);
void testBinarySearch(FILE *fout);
void testSelectionSort(FILE *fout);
void testQuickSort(FILE *fout);
void testSelectionSort_Words(FILE *fout);
void testQuickSort_Words(FILE *fout);
void PM_QuickSort_IntArray(FILE *fout);
void PM_SelectionSort_IntArray(FILE *fout);

int main()
{
    FILE *fout;
    char menu;

    fout = fopen("output.txt", "w");
    if (fout == NULL)
    {
        printf("Error in creation of array_output.txt \n");
        return -1;
    }

    while (1)
    {
        printf("\n");
        printf(" Test Array Algorithms :\n");
        printf(" 1: Test Sequential Search\n");
        printf(" 2: Test Binary Search\n");
        printf(" 3: Test Selection Sort\n");
        printf(" 4: Test Quick Sort\n");
        printf(" 5: Test Selection Sort for Words\n");
        printf(" 6: Test Quick Sort for Words\n");
        printf(" 7: Performance Measurements of Quick Sort for Integer Array\n");
        printf(" 8: Performance Measurements of Selection Sort for Integer Array\n");
        printf(" Esc: terminate\n");
        printf("Input menu : ");
        menu = getchar();
        printf("\n");

        if (menu == ESC)
            break;

        switch (menu)
        {
            case '1':
                testSequentialSearch(fout);
                break;
            case '2':
                testBinarySearch(fout);
                break;
            case '3':
                testSelectionSort(fout);
                break;
            case '4':
                testQuickSort(fout);
                break;
            case '5':
                testSelectionSort_Words(fout);
                break;
            case '6':
                testQuickSort_Words(fout);
                break;
            case '7':
                PM_QuickSort_IntArray(fout);
                break;
            case '8':
                PM_SelectionSort_IntArray(fout);
                break;
            default:
                break;
        }
    }
    fclose(fout);
    return 0;
}

// 순차적 탐색
void testSquentialSearch(FILE *fout)
{
    int data_array[NUM_DATA] = 
        { 37, 97, 75, 44, 65, 63, 0, 59, 82, 46, 56, 43, 40, 3, 89, 45, 26, 94, 54, 12 };
    int key_to_search; //key 값
    int pos;  //위치

    printf("Integer array to be searched: \n");
    printArray(data_array, NUM_DATA, LINE_SIZE);

    while (1)
    {
        printf("Input integer to be searched (-1 to quit) : ");
        scanf("%d", &key_to_search);

        if (key_to_search == -1)
            break;
        else
        {
            printf("Sequenital searching key (%d) from array of %d data... \n", key_to_search, NUM_DATA);
            pos = sequentialSearch(data_array, NUM_DATA, key_to_search);

            if (pos == -1)
            {
                printf("The key (%2d) was not found from the array\n", key_to_search);
            }
            else
            {
                printf("The key (%2d) was found at position (%2d) \n", key_to_search);
            }
        }
    }
}

// 이진탐색 - 정렬된 배열에서 가능
void testBinarySearch(FILE *fout)
{
    int data_array[NUM_DATA] = { 0, 3, 12, 26, 37, 40, 43, 44, 45, 46, 54, 56, 59, 63, 66, 75, 82, 89, 94, 97 };
    
    int key_to_search;
    int pos;
    
    printf("Integer array to be searched: \n");
    printArray(data_array, NUM_DATA, LINE_SIZE);
    while (1)
    {
        printf("INPUT integer to be searched (-1 to quit) : ");
        scanf("%d", &key_to_search); 

        if (key_to_search == -1)
            break;
        else
        {
            printf("Binary searching key (%d) from array of %d data ...\n", key_to_search, NUM_DATA);
            pos = binarySearch(data_array, NUM_DATA, key_to_search);
            if(pos == -1)
            {
                printf("The key (%2d) was not found from the array\n", key_to_search);
            }
            else
            { 
                printf("The key (%2d) was found at position (%2d)\n", key_to_search, pos);
            }
        }
    }
}


