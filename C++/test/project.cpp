#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> list = {1, 2, 3, 4};

    //list의 모든 값을 출력
    for (vector<int>::iterator i = list.begin(); i < list.end(); i++)
    {
        cout << *i << endl;
    }

    for (auto i = list.begin(); i < list.end(); i++)
    {
        cout << *i << endl;
    }

    for (auto v : list)
    {
        cout << v << endl;
    }

    int arr[] = {1, 2, 3, 4};
    for (int* i = arr; i < arr + 4; i++)
    {
        cout << *i << endl;
    }

    for (int  i = 0; i < 4; i++)
    {
        cout << arr[i] << endl;
    }


}