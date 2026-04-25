#include "Student.h"

/*
typedef struct students
{
	int st_id;//학번
	char name[16];//이름
	char dept[16];//학과
	int grade;//학점
	double GPA;//평점
}Student;
*/

// num_students 명의 학생 배열을 초기화
// void initStudents(Student* students, int* student_id, int num_students)
void initStudents(Student students[], int student_id[], int num_students)
{
    int name_len = 0;

    srand(time(NULL));

    /*
        student_id = [1001, 1002, 1003]
        student_id[0].st_id = 1001
        student_id[1].st_id = 1002
        student_id[2].st_id = 1003
    */
    for (int i=0; i<num_students; i++)
    {
        students[i].st_id = student_id[i];

        name_len = rand() % 11 + 5;
        //이름의 첫 글자만 랜덤 대문자로 설정
        students[i].name[0] = 'A' + rand() % 26;
        
        for (int j=1; j<name_len; j++)
        {
            students[i].name[j] = 'a' + rand() % 26;
        }
        students[i].name[name_len] = NULL;

        name_len = rand() % 3 + 3;
        for (int j=0; j<name_len; j++)
        {
            students[i].dept[j] = 'A' + rand() % 26;
        }
        students[i].dept[name_len] = NULL;

        students[i].grade = rand() % 8 + 1;
        students[i].GPA = (rand() % 10000) / 100.0;
    }
}

void fprintStudent(ofstream& fout, Student* pSt)
{
    int count = 0;
    fout.setf(ios::fixed);
    fout.setf(ios::showpoint);
    fout.precision(2);

    fout << "Student(ID: " << setw(4) << pSt->st_id;
    fout << ", Name: " << setw(16) << pSt->name;
    fout << ", Dept : " << setw(6) << pSt->dept;
    fout << ", Grade : " << pSt->GPA;
}

void fprintStudents(ofstream& fout, Student* student, int num_students)
{
    for (int i=0; i<num_students; i++)
    {
        fprintStudent(fout, &student[i]);
    } 
}

void fprintStudentID(ofstream& fout, Student* students, int size_array, int size_first_last_block)
{
    int count = 0;

    if (size_array <= size_first_last_block * 2)
    {
        for (int i=0; i<size_array; i++)
        {
            fprintStudentID(fout, &students[i], size_array);
            count++;
            if (count % 20 == 0)
                fout << endl;
        }
        return;
    }
    for (int i=0; i<size_first_last_block; i++)
    {
        fprintStudentID(fout, &students[i], size_array);
        count++;
        if (count % 20 == 0)
            fout << endl;
    }
    fout << "....." << endl;
    count = 0;
    for (int i=(size_array - size_first_last_block); i<size_array; i++)
    {
        fprintStudentID(fout, &students[i], size_array);
        count++;
        if (count % 20 == 0)
            fout << endl;
    }
}

void fprintStudentGPA_ID(ofstream& fout, Student* students, int num_students)
{
    fout.setf(ios::fixed);
    fout.setf(ios::showpoint);
    fout.precision(2);

    fout << "(" << setw(5) << students->GPA << "," << setw(6) << students->st_id << ") ";
}

// size_array = 총 학생 수,  size_first_last_block = 앞/뒤에서 출력할 학생 수
void fprintBigArrayOfStudent_GPA_IDs(ofstream& fout, Student* students, int size_array, int size_first_last_block)
{
    int count = 0;

    for (int i=0; i<size_first_last_block; i++)
    {
        fprintStudentGPA_ID(fout, &students[i], i++);
        count++;
        if (count % 20 == 0)
            fout << endl;
    }
    fout << "....." << endl;
    count = 0;
    for (int i=(size_array - size_first_last_block); i<size_array; i++)
    {
        fprintStudentGPA_ID(fout, &students[i], i++);
        count++;
        if (count % 20 == 0)
            fout << endl;
    }
}

void selectionSortStudents_By_ID(Student* student,int num_students)
{
    double min_gpa;
    int min_num;
    Student temp;
    
    for (int i=0; i<num_students; i++)
    {
        min_num = i;
        for (int j=i+1; j<num_students; j++)
        {
            if (student[j].GPA > student[min_num].GPA)
                min_num = j;
            else if (student[j].GPA == student[min_num].GPA)
            {
                if (student[j].st_id < student[min_num].st_id)
                    min_num = j;
            }
        }

        if (min_num != i)
        {
            temp = student[i];
            student[i] = student[min_num];
            student[min_num] = temp;
        }
    }
}

Student* binarySearchStudentByID(Student* students, int num_students, int st_id)
{
    int mid, low, high;
    
    low = 0;
    high = num_students -1 ;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (st_id == students[mid].st_id)
            return &students[mid];
        else if (st_id < students[mid].st_id)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return NULL;

}