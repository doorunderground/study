#include <iostream>
using namespace std;

class Arr
{
private:
    float* data;
    int size;

public:
    Arr(int size)
    {
        this->size = size;
        this->data = new float[size];  // 동적 할당 + size로 초기화
    }

    ~Arr()
    {
        delete[] data;
    }

    void set(int index, float value)
    {
        data[index] = value;
    }

    float get(int index)
    {
        return data[index];
    }
};

int main()
{
    Arr* arr = new Arr(5);

    arr->set(0, 10);
    arr->set(4, 40);

    cout << arr->get(0) << "," << arr->get(4) << endl;

    delete arr;

    return 0;
}
