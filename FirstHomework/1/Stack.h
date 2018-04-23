#pragma once

const int INITIAL_CAPACITY = 2;

class Stack
{
public:
	Stack();
	Stack(const Stack& other);
	Stack& operator=(const Stack& rhs);
	~Stack();

	void push(double value);
	double pop();
	double peek() const;

	bool isEmpty() const;
private:
	void resize();
	bool isFull() const;

	void allocate(int n);
	void copyFrom(const Stack& other);
	void clear();
private:
	int topIndex;
	int capacity;
	double* arr;
};