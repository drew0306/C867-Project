#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = "";
	for (int i = 0; i < 3; ++i)
	{
		this->daysInCourse[i] = 0;
	}
	this->degreeProgram = DegreeProgram::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, string age, int daysInCourse[], DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < 3; ++i)
	{
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

void Student::printHeader()
{
	cout << "StudentID ";
	cout << "First Name ";
	cout << "Last Name ";
	cout << "Email Address ";
	cout << "Age ";
	cout << "Days In Course ";
	cout << "Degree Program";
	cout << endl;
}

void Student::print()
{
	cout << this->studentID << '\t';
	cout << this->firstName << '\t';
	cout << this->lastName << '\t';
	cout << this->emailAddress << '\t';
	cout << this->age << '\t';
	for (int i = 0; i < 3; ++i)
	{
		cout << this->daysInCourse[i] << '\t';
	}
	cout << degreeProgramString[(int)this->degreeProgram];
	cout << endl;
}

void Student::setStudentID(string studentID)
{
	this->studentID = studentID;
}

void Student::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Student::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress)
{
	this->emailAddress = emailAddress;
}

void Student::setAge(string age)
{
	this->age = age;
}

void Student::setDays(int daysInCourse[])
{
	for (int i = 0; i < 3; ++i)
	{
		this->daysInCourse[i] = daysInCourse[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeProgram)
{
	this->degreeProgram = degreeProgram;
}

string Student::getStudentID()
{
	return this->studentID;
}

string Student::getFirstName()
{
	return this->firstName;
}

string Student::getLastName()
{
	return this->lastName;
}

string Student::getEmailAddress()
{
	return this->emailAddress;
}

string Student::getAge()
{
	return this->age;
}

const int* Student::getDays()
{
	return this->daysInCourse;
}

DegreeProgram Student::getDegreeProgram()
{
	return this->degreeProgram;
}