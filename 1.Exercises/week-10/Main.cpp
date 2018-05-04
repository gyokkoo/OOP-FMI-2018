#include <iostream>

#include "Manager.h"
#include "Programmer.h"
#include "QA.h"

int main()
{
	Manager boss("Ivo Andonov", 36, 9000, 50);
	boss.print();

	Manager subBoss("Petyr Tudzharov", 180, 7000, 35);
	subBoss.print();

	Programmer programist("Programist Programistov", 12, 1800, "Steal Kredit Cards", "C++, JavaScript");
	programist.print();

	Programmer pitakov("Ivan Pitakov", 1, 200, "Web-site maintenance", "HTML && CSS");
	pitakov.print();

	QA tester("Zdrawi Nerwi", 18, 2500, "Cloud system", false);
	tester.print();

	return 0;
}