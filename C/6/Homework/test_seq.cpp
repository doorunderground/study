#include <stdio.h>
#include "BigArray.h"

#define NUM_DATA 20
#define LINE_SIZE 20

int main()
{
    int data_array[NUM_DATA] = 
        { 37, 97, 75, 44, 65, 63, 0, 59, 82, 46, 56, 43, 40, 3, 89, 45, 26, 94, 54, 12 };
    int key_to_search;
    int pos;

    printf("Integer array to be searched: \n");
    printArray(data_array, NUM_DATA, LINE_SIZE);

    while (1)
    {
        printf("Input integer to be searched (-1 to quit) : ");
        scanf("%d", &key_to_search);

        if (key_to_search == -1)
            break;

        pos = sequentialSearch(data_array, NUM_DATA, key_to_search);

        if (pos == -1)
            printf("The key (%d) was NOT found.\n", key_to_search);
        else
            printf("The key (%d) was found at position [%d]\n", key_to_search, pos);
    }
    return 0;
}