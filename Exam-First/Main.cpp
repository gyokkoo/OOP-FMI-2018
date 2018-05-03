#include <iostream>
#include "Path.h"

int main()
{
	Point a(1, 3, "A");
	Point b(3, 4, "B");
	Point c(4, 5, "C");

	Path abc("ABC");
	abc += a;
	abc += b;
	abc += c;
	abc.print();

	abc.deletePoint(1);
	abc.print();

	abc.setName("AC");
	abc.print();

	return 0;
}