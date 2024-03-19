#pragma once
#include <iostream>
#include "degree.h"

using namespace std;

class Student {
public:
	const static int daysArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	string age;
	int daysInCourse[daysArraySize];
	DegreeProgram degreeProgram;

public:
	Student(); // default constructor

	Student(string studentID, string firstName, string lastName, string emailAddress, string age, int daysInCourse[], DegreeProgram degreeProgram); // constructor with parameters

	// setters

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(string age);
	void setDays(int daysInCourse[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

	// getters

	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	string getAge();
	const int* getDays();
	DegreeProgram getDegreeProgram();

	static void printHeader();
	void print();
};
