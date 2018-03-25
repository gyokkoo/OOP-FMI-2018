#pragma once

const int MAX_LENGTH = 35;

class Grade
{
private:
	char subject[MAX_LENGTH];
	double grade;
public:
	Grade();

	Grade(const char* subject, double grade);

	// Copy constructor
	Grade(const Grade& grade);

	void setGrade(double grade);

	double getGrade() const;

	void setSubject(const char* subject);

	const char* getSubject() const;

	void print() const;
};