/* BigArray.cpp */
#include "BigArray.h"

int sequentialSearch(int *array, int size, int key_to_search)
{
    for (int pos = 0; pos < size; pos++)
    {
        if (array[pos] == key_to_search)
        {
            return pos;  // 찾으면 -> 해당 인덱스 반환
        }
    }
    return -1; // 못 찾으면 -1 반환
}

void printArray(int *array, int size, int line_size)  // 출력
{
    for (int i = 0; i < size; i++)
    {
        printf("%3d", array[i]);

        if ((i + 1) % line_size == 0)
            printf("\n");
    }
    printf("\n");
}

// 이진 탐색
int binarySearch(int *array, int size, int key_to_search)
{
    int low, high, mid;
    int loop = 0;

    if (key_to_search > array[size-1])
    {
        printf("Binary_Search :: given key (%d) is beyond the maximum value of the array (%d)\n", key_to_search, array[size - 1]);
        return -1;
    }

    low = 0;
    high = size - 1;
    loop++;
    
    while(low <= high)
    {
        printf("%2d-th loop: Serach range: [%2d ~ %2d]\n", loop, low, high);
        mid = (low + high) / 2;
        if (key_to_search == array[mid])
            return mid;
        else if (key_to_search > array[mid])
            low = mid + 1;
        else
            high = mid - 1;
        loop++;
    }
    return -1;
}

void selectionSort(int *array, int size)
{
    int index_min;       // index
    int minElement;      // value


}