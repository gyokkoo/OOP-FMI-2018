#include <iostream>
#include <cstring>

const int MAX_NUMBER_SIZE = 20;

class TimeDate
{
private:
	int day;
	int month;
	int year;
	int hours;
	int minutes;
	int seconds;
public:
	TimeDate() : day(1), month(1), year(1900), hours(0), minutes(0), seconds(0)
	{
	}

	TimeDate(int day, int month, int year) : hours(0), minutes(0), seconds(0)
	{
		this->year = year;
		this->month = month;
		this->day = day;
	}

	TimeDate(int day, int month, int year, int hours, int minutes, int seconds)
	{
		this->year = year;
		this->month = month;
		this->day = day;
		this->hours = hours;
		this->minutes = minutes;
		this->seconds = seconds;
	}

	void print()
	{
		std::printf("%d/%d/%d -> %d:%d:%d\n", day, month, year, hours, minutes, seconds);
	}
};

class PhoneCall
{
private:
	char calledNumber[MAX_NUMBER_SIZE];
	TimeDate callStart;
	int callDurationSeconds;
public:
	PhoneCall() : calledNumber("N/A"), callStart(), callDurationSeconds(0)
	{
	}

	PhoneCall(const char* calledNumber, int callDuration,
		int day, int month, int year, int hours = 0, int minutes = 0, int seconds = 0)
		: callStart(day, month, year, hours, minutes, seconds)
	{
		this->setCalledNumber(calledNumber);
		this->setCallDurationSeconds(callDuration);
	}

	void setCalledNumber(const char* calledNumber)
	{
		if (strlen(calledNumber) > MAX_NUMBER_SIZE)
		{
			std::cout << "Called number is too long! \n";
		}
		strcpy_s(this->calledNumber, calledNumber);
	}

	char* getCalledNumber()
	{
		return this->calledNumber;
	}

	TimeDate getCallStart()
	{
		return this->callStart;
	}

	void setCallDurationSeconds(int seconds)
	{
		if (seconds < 0)
		{
			std::cout << "Call duration cannot be negative!\n";
			return;
		}
		this->callDurationSeconds = seconds;
	}

	int getCallDurationSeconds()
	{
		return this->callDurationSeconds;
	}

	double getCallCost(double minutePrice)
	{
		return minutePrice * (int)(this->callDurationSeconds / 60);
	}

	void print()
	{
		std::cout
			<< "_______________________\n"
			<< "Phone call to: " << calledNumber 
			<< " with " << callDurationSeconds << " seconds duration\non ";
		callStart.print();
	}
};

int main()
{
	double minuteCost = 1.53;

	PhoneCall callOne;
	callOne.print();
	std::cout << "Call cost: " << callOne.getCallCost(minuteCost) << "\n";

	PhoneCall callTwo("+359888034554", 160, 3, 3, 2018, 12, 35, 20);
	callTwo.print();
	std::cout << "Call cost: " << callTwo.getCallCost(minuteCost) << "\n";

	PhoneCall callThree("+43123323423", 650, 2, 2, 2018, 19, 30, 0);
	callThree.print();
	std::cout << "Call cost: " << callThree.getCallCost(minuteCost) << "\n";

	PhoneCall callFour("+35534343232", 450, 20, 4, 2016, 20);
	callFour.print();
	std::cout << "Call cost: " << callFour.getCallCost(minuteCost) << "\n";

	return 0;
}