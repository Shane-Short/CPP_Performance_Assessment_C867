/*
* File: main.cpp
* Creator: Shane Short
* Date Completed: 03/01/2022
*/

#include <string>
#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;

int main() {
	
	//Initial student data that was provided for testing.
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Shane,Short,shane-short@outlook.com,27,30,40,50,SOFTWARE"
	};
	
	//Tracks the number of elements in the studentData array
	int studentSize = sizeof(studentData) / sizeof(studentData[0]);

	//The remaining code in main() is provided by the course material for testing purposes.
	cout << "Course: Scripting and Programming - Applications - C867" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID: #000890378" << endl;
	cout << "Name: Shane Short" << endl << endl << endl;

	Roster classRoster;

	for (int i = 0; i < studentSize; i++) {
		classRoster.parse(studentData[i]);
	}

	classRoster.printAll();

	classRoster.printInvalidEmails();

	cout << "Average Number of Days Remaining" << endl << endl;
	
	for (int i = 0; i < studentSize; i++) {

		classRoster.printAverageDaysInCourse(classRoster.getRosterArray(i).getID());
	}

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");

	return 0;
}