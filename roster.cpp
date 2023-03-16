/*
* File: roster.cpp
* Creator: Shane Short
* Date Completed: 03/01/2022
*/

#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"


using namespace std;

void Roster::add(string studentID, string firstName, string lastName, string emailAdd, int age, int daysRemaining1, int daysRemaining2, int daysRemaining3, DegreeProgram degree) {

	int daysRemaining[3] = { daysRemaining1, daysRemaining2, daysRemaining3 };

	classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAdd, age, daysRemaining, degree);
}

void Roster::remove(string studentID) {

	bool found = false;

	for (int i = 0; i <= lastIndex; i++) {

		if (classRosterArray[i]->getID() == studentID) {

			found = true;
			
			delete classRosterArray[i];
			
			while (i < lastIndex) {
				classRosterArray[i] = classRosterArray[i + 1];
				i++;
			}
			
			classRosterArray[lastIndex] = nullptr;

			lastIndex--;
		}
	}
	
	if (found == true) {
		cout << "Student with ID " << studentID << " was removed." << endl;
	}
	else {
		cout << "Student with ID " << studentID << " was not found." << endl;
	}
	
	cout << endl;
}

void Roster::parse(string studentString) {

	size_t rhs = studentString.find(",");
	string studentID = studentString.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentString.find(",", lhs);
	string firstName = studentString.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentString.find(",", lhs);
	string lastName = studentString.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentString.find(",", lhs);
	string emailAdd = studentString.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentString.find(",", lhs);
	size_t age = stoi(studentString.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentString.find(",", lhs);
	size_t daysRemaining1 = stoi(studentString.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentString.find(",", lhs);
	size_t daysRemaining2 = stoi(studentString.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentString.find(",", lhs);
	size_t daysRemaining3 = stoi(studentString.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentString.find(",", lhs);
	string degree = studentString.substr(lhs, rhs - lhs);

	DegreeProgram degreeProgram;
	if (degree == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (degree == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (degree == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}
	else {
		degreeProgram = DegreeProgram::NONE;
	}

	add(studentID, firstName, lastName, emailAdd, age, daysRemaining1, daysRemaining2, daysRemaining3, degreeProgram);

}

void Roster::printAll() {

	cout << "Entire Student Roster " << endl << endl;
	
	for (int i = 0; i <= lastIndex; i++) {

		classRosterArray[i]->Print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	
	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i]->getID() == studentID) {

			int average = (
				(classRosterArray[i]->getDaysRemaining(0)) +
				(classRosterArray[i]->getDaysRemaining(1)) +
				(classRosterArray[i]->getDaysRemaining(2)) /
				3);

			cout << "Student ID: " << studentID << endl << "Average Days Remaining: " << average << endl << endl;
		}
	}
	
	cout << endl;
}

void Roster::printInvalidEmails() {

	cout << "Invalid Emails " << endl << endl;

	for (int i = 0; i < 5; i++) {

		string email = classRosterArray[i]->getEmail();
		string ID = classRosterArray[i]->getID();

		size_t atPos = email.find("@");

		if (email.find("@") == string::npos || email.find(".", atPos) == string::npos || email.find(" ") != string::npos) {

			cout << "Student " << ID << ": " << email << endl;
		}
	}
	
	cout << endl << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degree) {

	cout << "Students by Degree " << endl << endl;

	for (int i = 0; i < 5; i++) {

		if (classRosterArray[i]->getDegree() == degree) {

			classRosterArray[i]->Print();
		}
	}
}

Student Roster::getRosterArray(int index)
{
	return *classRosterArray[index];
}

Roster::~Roster() {
	
	for (int i = 0; i < students; i++) {
		
		if (classRosterArray[i] != nullptr) {
			
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
		}
	}
}