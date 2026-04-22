#include <vector>
#include <iostream>

using namespace std;

void print_vec(vector<int>& list)
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << endl;
    }
    cout << endl;
}

//입력으로 받은 list의 내용을 2배로 늘린다.
void repeat(vector<int> &list)
{
    int size = list.size();
    for (int i = 0; i < size; i++)
    {
        list.push_back(list[i]);
    }
}


class Module
{
private:
    int value;
public:
    int getValue() const
    {
        return value;
    }

    //set value
    void setValue(int value)
    {
        this->value = value;
    }  
};

void func(int a, int b)
{
    cout << "f1" << endl;
}   

void func(int a) 
{
    cout << "f2" << endl;
}

// 지금 func() 이름은 똑같은데, type 이 다륾


class Person
{
public:
    string name;
    void print()
    {
        cout << name << endl;
    }    
};

class Student : public Person
{
public:
    int score;
    // 연산자 오버라이딩
    // Person에도 이미 똑같은 print 함수가 있는데,
    // 그걸 재정의(over riding)

    void print()
    {
        cout << name << "," << score << endl;
    }
};


// int add(int a, int b)
// {
//     return a + b;
// }

// float add(float a, float b)
// {
//     return a + b;
// }
// ...............? double, unsigned..?

template<typename QWER> // int, float, .... -> QWER
QWER add(QWER a, QWER b)
{
    return a + b;
}

template<typename T1, typename T2>
T2 add(T1 a, T2 b)   // T2 타입으로 return 됨 
{
    return a + b;
}


int main()
{
    Module a;
    a.setValue(10);

    Module& b = a;
    b.setValue(20);

    Person p;
    p.name = "문지하";
    p.print();

    Student s;
    s.name = "doorunderground";
    s.score = 100;
    s.print();

    Person* p2 = &s;
    p2->print();

    Person& p3 = s;
    p3.print();

    vector<Person*> plist;
    plist.push_back(new Person());
    plist.push_back(new Student());

    cout << typeid(*plist[1]).name() << endl;

    cout << add(3.14, 4.56) << endl; //QWER   -> 둘다 double -> 동일 타입
    cout << add(3.14, 7) << endl;  //T1/T2   -> double, int -> 타입이 다름
}
