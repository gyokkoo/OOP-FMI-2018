#pragma once

const int INITIAL_CAPACITY = 2;

class List
{
private:
	int size;
	int capacity;
	int* arr;
public:
	List();
	List(int capacity);
	List(const List& list);
	~List();

	void resize(int s);
	void insertAt(int i, int value);
	void pushBack(int value);
	int popBack();
	void removeAt(int i);
	void clear();

	bool isEmpty() const;
	int getAt(int i) const;
	int getCapacity() const;
	int getSize() const;

	void print() const; // only for testing
private:
	void shiftLeft(int i);
	void shiftRight(int i);
};