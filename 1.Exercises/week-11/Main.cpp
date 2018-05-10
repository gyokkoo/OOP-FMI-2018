#include <iostream>

#include "Manager.h"
#include "Programmer.h"
#include "QA.h"
#include "Company.h"

int main()
{
	Manager* boss = new Manager("Ivo Andonov", 36, 9000, 50);
	Programmer* senior = new Programmer("Programist Programistov", 150, 3800, "Steal Kredit Cards", "C++, JavaScript");
	Programmer* mid = new Programmer("Javar Javarov", 60, 2500, "Java Back-end", "Java");
	Programmer* junior = new Programmer("Junior Juniorov", 2, 1300, "Migration to React.js", "ES2017 React.js");
	Programmer* intern = new Programmer("Pitai Pitakov", 1, 200, "Web-site maintenance", "HTML && CSS");
	QA* tester = new QA("Zdravi Nervi", 18, 2500, "Cloud system", false);

	Company techCompany;
	techCompany.setBoss(boss);
	techCompany.addEmployee(senior);
	techCompany.addEmployee(mid);
	techCompany.addEmployee(junior);
	techCompany.addEmployee(intern);
	techCompany.addEmployee(tester);
	techCompany.printAll();

	std::cout << "Employees working... \n";
	std::cout << "Sum ~ " << techCompany.getTotalWork() << " leva" << "\n";

	Company copy(techCompany);
	copy.printAll();

	return 0;
}