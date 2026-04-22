#include <iostream>
#using namespace std;

class Arr
{
private:
	float* data; // 이 데이터를 외부에서 직접 접근
	int size;
public:
	//생성자 __init__
	Arr(int size)
	{
		data = new float[size];
		this->size = size;
	}

	//직접 지정하지 않으면 기본 복사생성자가 발동
	// Arr b(3);
	// Arr a(b); 상황에서
	// a.size = b.size
	// a.data = b.data -> 심각한 에러
	Arr(const Arr& arr)
	{
		printf("copy const...\n");
		//최초의 this가 만들어지는 상황 (생성자니까)
		this->size = arr.size;
		// this->data = arr.data; //이거 안됌!

		//새로 메모리 생성
		this->data = new float[this->size];
		for (int i = 0; i < this->size; i++)
		{
			this->data[i] = arr.data[i];
		}
		//     destnation  source    size(byte단위)
		// 큰 크기를 한꺼번에 복사할 경우 오버헤드가 줄어든다.
		// 보통의 PC는 복사 전용 명령어+하드웨어가 있음. cpu의 제어를 받지 않고 그냥 메모리 복사
		memcpy(this->data, arr.data, sizeof(float) * this->size);
	}

	void operator=(const Arr& arr)
	{
		printf("operator = assign...\n");
		//a = b  .... a.operator=(b)    a + b  ... a.operator+(b)
		//this의 데이터를 날려버리고 b 데이터로 채워준다.
		delete this->data;
		this->size = arr.size;
		this->data = new float[this->size];
		memcpy(this->data, arr.data, sizeof(float) * this->size);
	}

	//소멸자
	~Arr()
	{
		delete data;
	}

	//접근자
	float * const Data()
	{
		return data;
	}

	int Size()
	{
		return size;
	}

    void reverser_in()
    {
        float* new_data = new float[size];
        
        for (int i = 0; i < size; i++)
        {
            int i2 = size - i - 1;
            new_data[i2] = data[i];
        }

        delete[] data;
        data = new_data;
    }

    Arr* reverse_out()
    {
        Arr* new_arr = new Arr(size);
        float* new_data = new_arr->data;

        for (int i = 0; i < size; i++)
        {
            int i2 = size - i - 1;
            new_data[i2] = data[i];
        }

        return new_arr;

    }


	// elementwise 연산 +덧셈만
	//   크기가 같으면 그냥 연산
	//   정수나 실수를 더하면 다 같이 연산

	// reverse -> inplace, new return

	// concat -> inplace 버전으로 만들어보고
	//        -> 새로운 객체 리턴 버전 ...??? 
	//             로컬 변수를 만들어서 리턴이 가능한가? x 동적 할당...
	//             call by ref ->

	// 객체는 모두 동적할당해서 다루는 방식으로...
	

	//Arr concat(Arr& src2)	
	//{
	//	Arr dst(3);
	//	//this와 src2를 결합한 내용을 dst에 넣는다.

	//	return dst; //되긴 되지만 비효율적... 복사 생성자 자체가 deep copy라서
	//}

	Arr* concat2(Arr* src)
	{
		Arr* dst = new Arr(3);
		return dst; //가장 효율적이고 깔끔하고 될지 안 될지 걱정도 안 되고 너무 편하다!
	}
};

void main()
{
    Arr* arr = new Arr(5);

    float* data = arr->Data();
    for (int i = 0; i < arr->Size(); i++)
    {
        data[i] = i * 10;
    }

    arr -> reverser_in();

    for (int i = 0; i < arr->Size(); i++)
    {
        cout << arr->Data()[i] << std::endl;
    }

    Arr* rev = arr->reverse_out();

    for (int i = 0; i < arr->Size(); i++)
    {
        std::cout << rev->Data()[i] << std::endl;
    }
    
}


