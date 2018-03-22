#pragma once
#include "Grade.h"

class Student
{
private:
	int fn;
	char name[MAX_LENGTH];
	Grade* grades;
	int gradesCount;
public:
	Student();

	Student(int, const char*, int);

	~Student();

	void setFn(int fn);

	int getFn() const;

	void setName(const char*);

	const char* getName() const;	

	void print() const;
};