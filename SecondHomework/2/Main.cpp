/**
*
* Solution to homework task
* Object-Oriented-Programming course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2017/2018
*
* @author Gyokan Syuleymanov
* @idnumber 62117
* @task 2
* @compiler VC
* @github https://github.com/Nezhdetov/
* @email gyokan.nezhdetov@gmail.com
*/

#include <iostream>
#include <cstring>
#include <assert.h>

#include "Pair.h"
#include "Settings.h"

/*
* Function for testing Pair class with assertion
* Note: Do not change code, otherwise assertion may fail
*/
void testPairClassWithInteger()
{
	// Test default constructor, should have initial state
	Pair<int> emptyPair;
	assert(strcmp(emptyPair.getKey(), "Invalid Key\n") == 0);
	assert(emptyPair.getValue() == 0);

	// Test constructor with parameters, should set correct values
	const char* key = "!@#$";
	int value = 123456;
	Pair<int> pairA(key, value);
	assert(strcmp(pairA.getKey(), key) == 0);
	assert(pairA.getValue() == value);

	// Test setters, should set correctly new values
	emptyPair.setKey(key);
	emptyPair.setValue(value);
	assert(strcmp(emptyPair.getKey(), key) == 0);
	assert(emptyPair.getValue() == value);

	// Test copy constructor, should copy correctly
	Pair<int> copyPairA(pairA);
	assert(strcmp(copyPairA.getKey(), key) == 0);
	assert(copyPairA.getValue() == value);

	// Test assignment operator, should assign correctly
	Pair<int> pairB;
	pairB = pairA;
	assert(strcmp(pairB.getKey(), key) == 0);
	assert(pairB.getValue() == value);
}

/*
* Function for testing Settings class with assertion
* Note: Do not change code, otherwise assertion may fail
*/
void testSettingsClassWithInteger()
{
	// Test default constructor, should have zero count
	Settings<int> settings;
	assert(settings.getCount() == 0);

	// Test set elements, should add new elements properly
	Pair<int> ivan("Ivan", 61923);
	Pair<int> gosho("Gosho", 61132);
	settings.set(ivan.getKey(), ivan.getValue());
	settings.set(gosho.getKey(), gosho.getValue());
	assert(settings.getCount() == 2);

	int ivanFn = 0;
	int goshoFn = 0;
	settings.get(ivan.getKey(), ivanFn);
	settings.get(gosho.getKey(), goshoFn);
	assert(ivan.getValue() == ivanFn);
	assert(gosho.getValue() == goshoFn);

	// Test set elements with pair, should add properly
	Pair<int> peter("Peter", 63122);
	settings.set(peter);
	int peterFn = 0;
	settings.get("Peter", peterFn);
	assert(peter.getValue() == peterFn);
	assert(settings.getCount() == 3);

	// Test set existing pair, should not add new value, only chage
	settings.set("Peter", 60000);
	assert(settings.getCount() == 3);

	int newFn = 0;
	settings.get("Peter", newFn);
	assert(newFn == 60000);
}

int main()
{
	testPairClassWithInteger();
	testSettingsClassWithInteger();
	std::cout << "Tests passed!\n";

	Pair<double> dis("DIS", 4.5);
	Pair<double> up("UP", 6.0);
	Pair<double> dstr("DSTR", 4.49);

	Settings<double> firstSemester;
	firstSemester.set(dis);
	firstSemester.set(up);
	firstSemester.set(dstr);
	firstSemester.print();
	std::cout << "_______________\n";

	firstSemester.set("Algebra", 5);
	firstSemester.set("Algebra", 6);
	firstSemester.set("UP", 4);
	firstSemester.set("DSTR", 5);
	firstSemester.print();

	double algebraGrade = 0;
	firstSemester.get("Algebra", algebraGrade);
	std::cout << "Algebra grade: " << algebraGrade << "\n";

	return 0;
}