#pragma once

const int MAX_LENGTH = 35;

class Grade
{
private:
	int grade;
	char subject[MAX_LENGTH];
public:
	Grade();

	Grade(const char* subject, int grade);

	void setGrade(int grade);

	void setSubject(const char* subject);

	int getGrade() const;

	const char* getSubject() const;

	void print() const;
};