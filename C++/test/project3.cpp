#include <iostream>


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

	
};



void main()
{
	//java, c#, python 에서 다 이런식으로 함
	Arr* arr = new Arr(5);

	float * const d2 = arr->Data();
	d2[0] = 10;
	d2[4] = 40;

	printf("%lf, %lf\n", d2[0], d2[4]);
	//f문자열 포맷팅....

	std::cout << d2[0] << ',' << d2[4] << std::endl;

	//참조는 일반 변수처럼 취급
	Arr& a2 = *arr;
	float* const d3 = a2.Data();

	//참조는 죽으면서 소멸자를 호출하지 않는다.
	//그냥 포인터가 사라지듯 조용히 참조 자체만 사라짐.
	delete arr;

	int a[5] = { 1, 2, 3, 4, 5 };
	int total = 0;
	for (int v : a) // c#, java의 foreach, python의 for
	{
		total += v;
	}

	//--------------------
	//데이터를 로컬변수로 생성하는 패러다임.
	Arr b[3] = {Arr(2), Arr(3), Arr(4)};

	//나는 b 속에 있는 값을 다 확인하고 싶고, 내용 수정은 하기 싫다.
	for (const Arr& v : b) // v = b[0], v = b[1], v = b[2] ...  복사 자체가 비효율
	{
		// ???
	}

	for (int i = 0; i < 3; i++)
	{
		const Arr& v = b[i];
		// ???
	}

	//-------------------------------
	//모든 객체를 동적 할당으로 처리하는 패러다임
	// java, c#과 비슷한 원리
	Arr* c[3] = { new Arr(2), new Arr(3), new Arr(4) };
	
	for (const Arr* p : c)
	{
		
	}


	Arr x1(10);
	Arr x2 = x1; // 복사생성자(o)

	Arr x3(5);
	x3 = x1; // 대입연산자 (operator=)

}