#include <iostream>
#include "EBook.h"
#include "Book.h"
#include "Library.h"

int main()
{
	Book dis("DIS Uchebnik", 150);
	Book algebra("Algebra Sbornik", 600);
	Book oop("OOP Knijka", 500);
	EBook dstr("DSTR Uchebnik", 134, 1024, 5);
	EBook eAlgebra("Spravochnik po Algebra", 250, 512, 194);

	Library fmi;
	fmi.addBook(dis);
	fmi.addBook(algebra);
	fmi.addBook(oop);
	fmi.addBook(dstr);
	fmi.addBook(eAlgebra);

	fmi.sortByTitle();
	std::cout << fmi;

	return 0;
}