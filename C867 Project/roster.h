#pragma once
#include <string>
#include "student.h"

using namespace std;

class classRoster {
private:
	int lastIndex = -1;
	const static int numStudents = 5;
	Student* students[numStudents] = { nullptr, nullptr, nullptr, nullptr, nullptr }; // array of pointers
public:

	Student** getStudents(); // gets the pointer to the array of objects

	void parseStudents(string row);
	void addStudent(string studentID, string firstName, string lastName, string emailAddress, string age, int days1, int days2, int days3, DegreeProgram degreeProgram);
	void printAll();
	void printByDegree(DegreeProgram degreeProgram);
	void printInvalidEmails();
	void printAverageDays(string studentID);
	void removeStudent(string studentID);

	~classRoster(); // destructor

};