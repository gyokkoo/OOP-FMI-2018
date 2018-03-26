#pragma once
#include "Grade.h"

class Student
{
private:
	int fn;
	char name[MAX_LENGTH];
	Grade* grades;
	int maxGradesCount;
	int gradesCount;
public:
	// Default constructor
	Student();

	// Constructor with parameters
	Student(int fn, const char* name, int gradesCount);

	// Destructor
	~Student();

	void setFn(int fn);

	int getFn() const;

	void setName(const char*);

	const char* getName() const;

	int getMaxGradesCount() const;

	int getGradesCount() const;

	void addGrade(Grade g);

	double getAverage() const;

	double getAverage(const char* subject) const;

	void print() const;

	void printGrades() const;

	void printAll() const;
};