#include <iostream>
#include "Book.h"
#include "Library.h"

int main()
{
	Book geometriq("Sbornik Geometriq", 350);
	Book dis("Sbornik Analiz", 1300);

	Library fmi;
	fmi.addBook(geometriq);
	fmi.addBook(dis);

	std::cout << fmi;

	return 0;
}