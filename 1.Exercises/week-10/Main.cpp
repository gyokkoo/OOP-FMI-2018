#include <iostream>

#include "Manager.h"
#include "Programmer.h"
#include "QA.h"
#include "Company.h"

int main()
{
	Manager boss("Ivo Andonov", 36, 9000, 50);
	Manager subBoss("Petyr Tudzharov", 180, 7000, 35);
	Programmer programist("Programist Programistov", 12, 1800, "Steal Kredit Cards", "C++, JavaScript");
	Programmer pitakov("Ivan Pitakov", 1, 200, "Web-site maintenance", "HTML && CSS");
	QA tester("Zdrawi Nerwi", 18, 2500, "Cloud system", false);

	Company techCompany;
	techCompany += boss;
	techCompany += subBoss;
	techCompany += programist;
	techCompany += pitakov;
	techCompany += tester;
	techCompany += Programmer("Junior Juniorov", 2, 1300, "Migration to React.js", "ES2017 React.js");
	
	techCompany.printAll();
	
	techCompany.removeNewEmployees();
	std::cout << "Shortage of money!!! Removed newbies!\n";
	techCompany.printAll();

	std::cout << "All expenses = ";
	std::cout << techCompany.getTotalExpenses() << "\n";

	std::cout << "Average Salary ~ ";
	std::cout << techCompany.getAverageSalary() << "\n";

	return 0;
}