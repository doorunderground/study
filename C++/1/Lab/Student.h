/* Student.h*/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <fstream>
#include <cstdlib> //rand()함수 사용을 위한

using namespace std;

typedef struct students
{
	int st_id;//학번
	char name[16];//이름
	char dept[16];//학과
	int grade;//학점
	double GPA;//평점
}Student;

void initStudents(Student students[], int student_id[], int num_students);
void fprintStudent(ofstream& fout, Student* pSt); 
void fprintStudents(ofstream& fout, Student* student, int num_students); 
void fprintStudentID(ofstream& fout, Student* student, int num_students);
void fprintBigArrayOfStudent_IDs(ofstream& fout, Student* student, int size_array, int size_first_last_block);
void fprintStudentGPA_ID(ofstream& fout, Student* students, int num_students);
void fprintBigArrayOfStudent_GPA_IDs(ofstream& fout, Student* students, int size_array, int size_first_last_block); 
void selectionSortStudents_By_ID(Student* student, int num_students); 
void selectionSortStudents_By_GPA_ID(Student* student, int num_students); 
Student* binarySearchStudentByID(Student* students, int num_students, int st_id);

