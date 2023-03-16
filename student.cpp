/*
* File: student.cpp
* Creator: Shane Short
* Date Completed: 03/01/2022
*/

#include "student.h"
#include "degree.h"
#include <iostream>
#include <string>


string Student::getID() const
{
	return studentID;
}

int Student::getAge() const
{
	return age;
}

string Student::getFirstName() const
{
	return firstName;
}

string Student::getLastName() const
{
	return lastName;
}

string Student::getEmail() const
{
	return emailAdd;
}

DegreeProgram Student::getDegree()
{
	return degree;
}

int Student::getDaysRemaining(int index) const
{
	if (index == 0) {

		return daysRemaining[0];
	}

	else if (index == 1) {

		return daysRemaining[1];
	}

	else if (index == 2) {

		return daysRemaining[2];
	}

	else {

		return 0;
	}
}


void Student::setID(const string& studentID)
{
	this->studentID = studentID;
}

void Student::setAge(const int& studentAge)
{
	age = studentAge;
}

void Student::setFirstName(const string& studentFirstName)
{
	firstName = studentFirstName;
}

void Student::setLastName(const string& studentLastName)
{
	lastName = studentLastName;
}

void Student::setEmail(const string& studentEmailAddress)
{
	emailAdd = studentEmailAddress;
}

void Student::setDegree(DegreeProgram& studentDegreeProgram)
{
	degree = studentDegreeProgram;
}

void Student::setDaysRemaining(
	const int& daysRemainingInCourse1,
	const int& daysRemainingInCourse2,
	const int& daysRemainingInCourse3
)
{
	daysRemaining[0] = daysRemainingInCourse1;
	daysRemaining[1] = daysRemainingInCourse2;
	daysRemaining[2] = daysRemainingInCourse3;
}


Student::Student() {
	studentID = "";
	firstName = "";
	lastName = "";
	emailAdd = "";
	age = 0;
	daysRemaining[0] = 0;
	daysRemaining[1] = 0;
	daysRemaining[2] = 0;
	degree = DegreeProgram::NONE;
}

Student::Student(
	string studentID,
	string firstName,
	string lastName,
	string emailAdd,
	int age,
	int daysRemaining[3],
	DegreeProgram degree
)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAdd = emailAdd;
	this->age = age;
	this->daysRemaining[0] = daysRemaining[0];
	this->daysRemaining[1] = daysRemaining[1];
	this->daysRemaining[2] = daysRemaining[2];
	this->degree = degree;
}

void Student::Print()
{
	cout << "Student ID: " << studentID << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Email Address: " << emailAdd << endl;
	cout << "Age: " << age << endl;
	cout << "Days Remaining in Course 1: " << daysRemaining[0] << endl;
	cout << "Days Remaining in Course 2: " << daysRemaining[1] << endl;
	cout << "Days Remaining in Course 3: " << daysRemaining[2] << endl;
	cout << "Degree: ";
	if (degree == DegreeProgram::SECURITY) {
		cout << "Security" << endl << endl;
	}
	else if (degree == DegreeProgram::NETWORK) {
		cout << "Network" << endl << endl;
	}
	else if (degree == DegreeProgram::SOFTWARE) {
		cout << "Software" << endl << endl;
	}
	else {
		cout << "None" << endl << endl;
	}
	
	cout << endl;
}