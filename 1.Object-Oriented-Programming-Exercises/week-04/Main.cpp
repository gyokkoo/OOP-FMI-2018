#include <iostream>
#include "Grade.h"

int main()
{
	Grade initialGrade;
	Grade grade("Algebra", 5);

	initialGrade.print();
	grade.print();


	return 0;
}