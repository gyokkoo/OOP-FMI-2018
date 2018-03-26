#include <iostream>
#include <stdio.h>
#include <assert.h>

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
		this->setYear(year);
		this->setMonth(month);
		this->setDay(day);
	}

	TimeDate(int day, int month, int year, int hours, int minutes, int seconds)
	{
		this->setYear(year);
		this->setMonth(month);
		this->setDay(day);
		this->setHours(hours);
		this->setMinutes(minutes);
		this->setSeconds(seconds);
	}

	void setYear(const int year)
	{
		if (year < 0)
		{
			std::cout << "Invalid year, cannot be negative!\n";
			return;
		}
		this->year = year;
	}

	int getYear()
	{
		return this->year;
	}

	void setMonth(const int month)
	{
		if (month < 1 || month > 12)
		{
			std::cout << "Invalid month! \n";
			return;
		}
		this->month = month;
	}

	int getMonth()
	{
		return this->month;
	}

	void setDay(const int day)
	{
		int maxDays = calculateDaysInMonth(this->month);
		if (day < 1 || day > maxDays)
		{
			std::cout << "Invalid day! \n";
			return;
		}
		this->day = day;
	}

	int getDay()
	{
		return this->day;
	}

	void setHours(const int hours)
	{
		if (hours < 0 || hours > 24)
		{
			std::cout << "Invalid hour!\n";
			return;
		}
		this->hours = hours;
	}

	int getHours()
	{
		return this->hours;
	}

	void setMinutes(const int minutes)
	{
		if (minutes < 0 || minutes > 59)
		{
			std::cout << "Invalid minutes! \n";
			return;
		}
		this->minutes = minutes;
	}

	int getMinutes()
	{
		return this->minutes;
	}

	void setSeconds(const int seconds)
	{
		if (seconds < 0 || seconds > 59)
		{
			std::cout << "Invalid seconds!\n";
			return;
		}
		this->seconds = seconds;
	}

	int getSeconds()
	{
		return this->seconds;
	}

	bool isLeapYear(int year)
	{
		if (this->year % 4 != 0)
			return false;
		else if (this->year % 100 != 0)
			return true;
		else if (this->year % 400 != 0)
			return false;
		else
			return true;
	}

	int calculateDaysInMonth(int month)
	{
		switch (month)
		{
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				return 31;
			case 2:
				if (isLeapYear(this->year))
					return 29;
				else
					return 28;
			case 4:
			case 6:
			case 9:
			case 11:
				return 30;
			default:
				std::cout << "Invalid month provided!\n";
				return -1;
		}
	}

	void print()
	{
		std::printf("%d/%d/%d -> %d:%d:%d\n", day, month, year, hours, minutes, seconds);
	}
};

int main()
{
	TimeDate defaultTime;
	defaultTime.print();

	TimeDate onlyDate(20, 4, 2015);
	onlyDate.print();

	TimeDate fullTime(14, 2, 2017, 19, 29, 45);
	fullTime.print();

	const int year = 2001;
	const int month = 3;
	const int day = 3;
	const int hours = 10;
	const int minutes = 25;
	const int seconds = 30;

	TimeDate testTime(day, month, year, hours, minutes, seconds);
	testTime.print();

	// Test setters and getters
	assert(day == testTime.getDay());
	assert(month == testTime.getMonth());
	assert(year == testTime.getYear());
	assert(hours == testTime.getHours());
	assert(minutes == testTime.getMinutes());
	assert(seconds == testTime.getSeconds());

	testTime.setYear(-1);
	testTime.setMonth(0);
	testTime.setMonth(13);
	testTime.setDay(0);
	testTime.setDay(32);
	testTime.setHours(-1);
	testTime.setHours(25);
	testTime.setMinutes(-1);
	testTime.setMinutes(60);
	testTime.setSeconds(-1);
	testTime.setSeconds(60);
	
	// The values must not be changed:
	assert(day == testTime.getDay());
	assert(month == testTime.getMonth());
	assert(year == testTime.getYear());
	assert(hours == testTime.getHours());
	assert(minutes == testTime.getMinutes());
	assert(seconds == testTime.getSeconds());

	return 0;
}