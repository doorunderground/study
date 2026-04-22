#include <iostream>
using namespace std;

struct Arr
{
    float* data;
    int size;
};

Arr* creatArr(int size)
{
    Arr* arr = (Arr*)malloc(sizeof(Arr));
    arr->data = (float*)malloc(sizeof(float) * size);
    arr->size = size;
    return arr;
}

void releaseArr(Arr* arr)
{
    free(arr->data);
    free(arr);
}

void main()
{
    Arr * arr = creatArr(5);
    float *data = arr->data;
    data[0] = 10;
    data[4] = 40;
    cout << data[0] << "," << data[4] << endl;
    releaseArr(arr);

}