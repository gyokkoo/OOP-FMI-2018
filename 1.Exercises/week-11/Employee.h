#pragma once

class Employee
{
public:
	Employee();
	Employee(const char* name, int experience, double salary);
	Employee(const Employee& employee);
	Employee& operator=(const Employee& rhs);
	virtual ~Employee();

	virtual double work();

	const char* getName() const;
	int getExperience() const;
	double getSalary() const;

	void setName(const char* name);
	void setExperience(int experience);
	void setSalary(double salary);

	virtual void print() const;
protected:
	double getUsefulness(double moneyPerMonth);
private:
	char* name;
	int experience;
	double salary;
};