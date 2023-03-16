/*
* File: student.h
* Creator: Shane Short
* Date Completed: 03/01/2022
*/

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include "degree.h"

using namespace std;

class Student {
public:
	//Getters
	int getDaysRemaining(int) const;
	int getAge() const;
	string getID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	DegreeProgram getDegree();



	//Setters
	void setDaysRemaining(
		const int& daysRemainingInCourse1,
		const int& daysRemainingInCourse2,
		const int& daysRemainingInCourse3
	);
	void setAge(const int& studentAge);
	void setID(const string& studentID);
	void setFirstName(const string& studentFirstName);
	void setLastName(const string& studentLastName);
	void setEmail(const string& studentEmailAddress);
	void setDegree(DegreeProgram& studentDegreeProgram);

	//Object Constructor
	Student();
	Student(
		string studentID,
		string firstName,
		string lastName,
		string emailAdd,
		int age,
		int daysRemaining[3],
		DegreeProgram degree
	);

	void Print();


private:
	int daysRemaining[3];
	int age;
	string studentID;
	string firstName;
	string lastName;
	string emailAdd;
	DegreeProgram degree;
};
#endif //STUDENT_H