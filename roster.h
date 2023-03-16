/*
* File: roster.h
* Creator: Shane Short
* Date Completed: 03/01/2022
*/

#ifndef ROSTER_H
#define ROSTER_H

#include <string>
#include <iostream>
#include "student.h"

using namespace std;


class Roster {
	
public:
	void add(string studentID, string firstName, string lastName, string emailAdd, int age, int daysRemaining1, int daysRemaining2, int daysRemaining3, DegreeProgram degree);
	void remove(string studentID);
	void parse(string studentString);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);
	Student getRosterArray(int index);
	int lastIndex = -1;
	const int students = 5;
	~Roster();


private:
	Student* classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	
};
#endif // !ROSTER_H