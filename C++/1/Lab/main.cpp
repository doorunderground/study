#include "Student.h"

#define NUM_STUDENTS 5000
#define NUM_SESRCH 5
#define NUM_FITST_LAST_BLOCK 100

//void genBigRandArray(int *randArray, int num_rands)
void genBigRandArray(int pArray[], int num_rands) //난수생성 함수
{
	char* flag;
	int count = 0;
	unsigned int u_int32 = 0; //초기화
	unsigned int bigRand = 0; //초기화
	
	srand(time(NULL));

	flag = (char*)calloc(sizeof(char), num_rands); //동적할당 선언 + 초기화
	while (count < num_rands)
	{
		u_int32 = ((long)rand() << 15) | rand(); //비트를 왼쪽으로 15비트만큼 bitwise + or연산
		bigRand = u_int32 % num_rands;  //0~랜덤넘버-1 의 값을 생성
		if (flag[bigRand] == 1) // 생성숫자를 flag 배열에 넣고 flag 배열 안 값이 1인지 확인
		{ 
			continue;
		}
		flag[bigRand] = 1; //flag배열에 1을 넣음 
		pArray[count++] = bigRand; //배열에 bigRand 저장
	}
}

int main()
{
	ofstream fout;

	int* student_ids;
	Student* students, * pst;
	int student_search[NUM_SESRCH] = { 1,123,999,2500,4999 };

	fout.open("output.txt");
	if (fout.fail())
	{
		fout << "Error in opening output txt" << endl;
		exit(1);
	}

	student_ids = (int*)calloc(NUM_STUDENTS, sizeof(int));
	genBigRandArray(student_ids, NUM_STUDENTS);
	students = (Student*)calloc(NUM_STUDENTS, sizeof(Student));
	initStudents(students, student_ids, NUM_STUDENTS);

	fout << endl << endl;
	fout << "Initialized array of students : " << endl;
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FITST_LAST_BLOCK);

	fout << endl << endl;
	fout << "Selection sorting the array of students by (incrasing order of ID) :" << endl;
	selectionSortStudents_By_ID(students, NUM_STUDENTS);
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FITST_LAST_BLOCK);

	fout << endl << endl;
	fout << "Selection sorting the array of students by (decreasing order of GPA,incrasing order of ID) :" << endl;
	selectionSortStudents_By_GPA_ID(students, NUM_STUDENTS);
	fprintBigArrayOfStudent_GPA_IDs(fout, students, NUM_STUDENTS, NUM_FITST_LAST_BLOCK);

	fout << endl << endl;
	fout << "Selection sorting the array of students by (incrasing order of ID) :" << endl;
	selectionSortStudents_By_ID(students, NUM_STUDENTS);
	fprintBigArrayOfStudent_IDs(fout, students, NUM_STUDENTS, NUM_FITST_LAST_BLOCK);

	fout << endl << endl;
	fout << "Searching student with student_ID : " << endl;
	for (int i = 0; i < NUM_SESRCH; i++)
	{
		pst = binarySearchStudentByID(students, NUM_STUDENTS, student_search[i]);
		fout << "Student search by ID (" << setw(4) << student_search[i] << ")";
		if (pst != NULL)
			fprintStudent(fout, pst);
		else
			fout << "NULL-student was not found !!" << endl;
		fout << endl;
	}
	fout.close();
}

