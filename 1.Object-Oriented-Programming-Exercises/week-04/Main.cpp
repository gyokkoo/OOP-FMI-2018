#include <iostream>
#include "Grade.h"
#include "Student.h"

int main()
{
	Grade initialGrade;
	Grade grade("Algebra", 5);

	initialGrade.print();
	grade.print();

	Student initialStudent;
	Student ivancho(62193, "Ivan Ivanov", 10);
	
	initialStudent.print();
	ivancho.print();

	return 0;
}