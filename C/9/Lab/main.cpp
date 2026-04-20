#include <stdio.h>
#include "Student.h"
#define MAX_NUM_STUDENTS 100

int main()
{
	int num_students = 0;	
	int menu;
	Student* pST_GPA_max, * pST_GPA_min;
	Student students[] = {
  //학번,      이름,        생년월일,          전화번호,       학점 
{ 21911000, "Kim, G-M", { 1990, 10, 5 }, { 82, 53, 805, 1234 }, 3.57 },
{ 21822075, "Yoon, S-M", { 1990, 4, 5 }, { 82, 53, 811, 1550 }, 4.37 },
{ 21433015, "Hwang, S-S", { 1989, 1, 10 }, { 82, 53, 817, 1005 }, 2.72 },
{ 21644054, "Lee, K-M", { 1991, 5, 15 }, { 82, 10, 9112, 9876 }, 3.35 },
{ 21255340, "Hong, G-M", { 1990, 2, 5 }, { 82, 55, 810, 5678 }, 3.57 },
{ 21766056, "Zang, S-M", { 1990, 3, 15 }, { 82, 10, 9112, 1600 }, 4.45 },
{ 21177017, "Park, S-S", { 1989, 7, 10 }, { 82, 34, 817, 1098 }, 4.12 },
{ 21588053, "Choi, Y-H", { 1992, 9, 25 }, { 82, 53, 845, 5764 }, 3.85 },
{ 21399019, "Ahn, D-J", { 1988, 10, 3 }, { 82, 31, 817, 1038 }, 3.21 },
{ 21010053, "Kwak, S-B", { 1994, 11, 15 }, { 82, 2, 897, 8778 }, 4.43 },
{ 21021053, "Song, W-B", { 1993, 5, 15 }, { 82, 34, 345, 1234 }, 4.47 },
{ 21133053, "Gong, G-W", { 1992, 6, 25 }, { 82, 55, 543, 4321 }, 2.35 },
{ 20911042, "Bhang, S-H", { 1987, 12, 25 }, { 82, 2, 123, 4567 }, 3.75 },
{-1}

	};
	for (int i = 0; i < MAX_NUM_STUDENTS; i++)
	{
		if (students[i].st_id == -1)
			break;
		else
			num_students++;
	}
	printf("Number of studetns = %d\n", num_students);
	while (1)
	{
		printf("\n");
		printf(" 1 : print student records\n");
		printf(" 2 : calculate statistics GPA (max, min, avg) of students' \n");
		printf(" 3 : search students of best GPA and worst GPA\n");
		printf(" 4 : sort students by student ID\n");
		printf(" 5 : sort students by GPA\n");
		printf(" 6 : sort students by name\n");
		printf(" 7 : sort students by date of birth\n");
		printf(" 8 : sort studetns by telephone number\n");
		printf("-1 : Quit\n");
		printf("Input menu = ");
		scanf("%d", &menu);
		if (menu == -1)
			break;
		switch (menu)
		{
		case 1:
			printStudents(students, num_students);
			printf("\n");
			break;
		case 2:
			statisticsGPA(students, num_students);
			break;
		case 3:
			pST_GPA_max = searchBestGPAStudent(students, num_students);
			pST_GPA_min = searchWorstGPAStudent(students, num_students);
			printf("Student with best GPA : ");
			printStudent(pST_GPA_max);
			printf("\n");
			printf("Student with worst GPA : ");
			printStudent(pST_GPA_min);
			printf("\n");
			break;
		case 4:
			sortStudents_by_ST_ID(students, num_students);
			printf("After sorting students by increasing order of student ID:\n");
			printStudents(students, num_students);
			printf("\n");
			break;
		case 5:
			sortStudents_by_GPA(students, num_students);
			printf("After sorting students by decreasing order of GPA:\n");
			printStudents(students, num_students);
			printf("\n");
			break;
		case 6:
			sortStudents_by_name(students, num_students);
			printf("After sorting students by increasing order of student name:\n");
			printStudents(students, num_students);
			printf("\n");
			break;
		case 7:
			sortStudents_by_BirthDate(students, num_students);
			printf("After sorting students by increasing order of student birth date:\n");
			printStudents(students, num_students);
			printf("\n");
			break;
		case 8:
			sortStudents_by_TelNumber(students, num_students);
			printf("After sorting students by increasing order of student's telephone number:\n");
			printStudents(students, num_students);
			printf("\n");
			break;
		default:
			break;
		}
		shuffleStudents(students, num_students); //shuffle array for next experiments
	}
}