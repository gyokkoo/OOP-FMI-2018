#pragma once
#include "Timestamp.h"

class TimestampWithDescription : public Timestamp
{
public:
	TimestampWithDescription();
	TimestampWithDescription(unsigned long value, const char* description);
	TimestampWithDescription(const TimestampWithDescription& other);
	TimestampWithDescription& operator=(const TimestampWithDescription& other);
	~TimestampWithDescription();

	const char* getDescription() const;

	void setDescription(const char* description);
private:
	char* description;
};

std::istream& operator>>(std::istream& is, TimestampWithDescription& timestamp);
std::ostream& operator<<(std::ostream& os, const TimestampWithDescription& timestamp);