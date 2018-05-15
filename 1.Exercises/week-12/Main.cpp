#include <iostream>

#include "TimestampWithDescription.h"

int main()
{
	Timestamp oneYear(31556926);
	std::cout << "One year " << oneYear;

	Timestamp oneDay;
	for (int i = 0; i < 86400; ++i) {
		oneDay += 1;
	}
	std::cout << "One day " << oneDay;

	Timestamp result = oneYear + oneDay;
	std::cout << "One year and one day " << result;
	
	TimestampWithDescription exam(1526806800, "OOP Exam Date");
	std::cout << exam;

	std::cout << "Copy date:\n";
	TimestampWithDescription copyDate(exam);
	std::cout << exam;

	std::cout << "Operator= \n";
	TimestampWithDescription assignmentOperatorTest;
	assignmentOperatorTest = exam;
	std::cout << assignmentOperatorTest;
	
	std::cout << "\nTesting user input:\n";
	Timestamp timestamp;
	std::cin >> timestamp;
	std::cout << timestamp;

	TimestampWithDescription timestampDescription;
	std::cout << "Enter timestamp with description\n";
	std::cin >> timestampDescription;
	std::cout << timestampDescription;

	return 0;
}