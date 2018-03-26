#include <iostream>
#include "Grade.h"
#include "Student.h"

bool compare(const Student& a, const Student& b)
{
	return a.getAverage() > b.getAverage();
}

int main()
{
	Grade dis("Dis", 5.5);
	Grade algebraFirst("Algebra", 5);
	Grade algebraSecond("Algebra", 5.5);
	Grade up("UP", 6);
	Grade dstr("DSTR", 3.5);
	
	Student ivancho(62193, "Ivan Ivanov", 2);
	// Grade copy constructor is invoked x5 times
	ivancho.addGrade(dis);
	ivancho.addGrade(up);
	ivancho.addGrade(algebraFirst);
	ivancho.addGrade(algebraSecond);
	ivancho.addGrade(dstr);

	ivancho.printAll();
	std::cout << "-------> Average mark: " << ivancho.getAverage() << "\n";
	std::cout << "Ivancho's algebra average mark: " << ivancho.getAverage("Algebra") << "\n";
	std::cout << "------------------------\n";

	Student pesho(61234, "Petyr Petrov", 2);
	// Grade copy constrcutor is not invoked
	pesho.addGrade(Grade("Dis", 5.5));
	pesho.addGrade(Grade("Algebra", 5.5));
	pesho.addGrade(Grade("Algebra", 6));
	pesho.addGrade(Grade("UP", 4));
	pesho.addGrade(Grade("DSTR", 5));

	pesho.printAll();
	std::cout << "-------> Average mark: " << pesho.getAverage() << "\n";
	std::cout << "Pesho's algebra average mark: " << pesho.getAverage("Algebra") << "\n\n";

	std::cout << (compare(ivancho, pesho) ? 
		"Ivancho has higher marks\n" : 
		"Pesho has higher marks\n"); 

	return 0;
}