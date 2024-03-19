#include "roster.h"
#include "student.h"

using namespace std;

Student** classRoster::getStudents()
{
	return classRoster::students;
}

void classRoster::parseStudents(string studentData)
{
	DegreeProgram degreeProgram = DegreeProgram::SOFTWARE;
	if (studentData.back() == 'K') degreeProgram = DegreeProgram::NETWORK;
	else if (studentData.back() == 'Y') degreeProgram = DegreeProgram::SECURITY;
	int rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);
	int lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);
	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string age = studentData.substr(lhs, rhs - lhs);
	int days[3];
	for (int i = 0; i < 3; ++i)
	{
		lhs = rhs + 1;
		rhs = studentData.find(",", lhs);
		days[i] = stoi(studentData.substr(lhs, rhs - lhs));
	}
	addStudent(studentID, firstName, lastName, emailAddress, age, days[0], days[1], days[2], degreeProgram);
}

void classRoster::addStudent(string studentID, string firstName, string lastName, string emailAddress, string age, int days1, int days2, int days3, DegreeProgram degreeProgram)
{
	int daysInCourse[3] = { days1, days2, days3 };
	students[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}

void classRoster::printAll()
{
	// remove slashes to add the header funciton Student::printHeader();
	for (int i = 0; i <= classRoster::lastIndex; ++i)
		classRoster::students[i]->print();
}

void classRoster::printByDegree(DegreeProgram degreeProgram)
{
	// remove slashes to add the header funciton Student::printHeader();
	for (int i = 0; i <= classRoster::lastIndex; ++i)
		if (classRoster::students[i]->getDegreeProgram() == degreeProgram) students[i]->print();
}

void classRoster::printInvalidEmails()
{
	for (int i = 0; i <= classRoster::lastIndex; ++i)
	{
		string email = classRoster::getStudents()[i]->getEmailAddress();
		if (email.find(' ') != string::npos || email.find('.') == string::npos || email.find('@') == string::npos)
			cout << email << " is invalid." << endl;
	}
}

void classRoster::printAverageDays(string studentID)
{
	for (int i = 0; i <= classRoster::lastIndex; ++i)
	{
		if (students[i]->getStudentID() == studentID)
		{
			cout << studentID << ":";
			cout << (students[i]->getDays()[0] + students[i]->getDays()[1] + students[i]->getDays()[2]) / 3 << endl;
		}
	}
}

void classRoster::removeStudent(string studentID)
{
	bool success = false;
	for (int i = 0; i <= classRoster::lastIndex; ++i)
	{
		if (students[i]->getStudentID() == studentID)
		{
			success = true;
			Student* temp = students[i];
			students[i] = students[numStudents - 1];
			students[numStudents - 1] = temp;
			classRoster::lastIndex--;
		}
	}
	if (success)
	{
		cout << "Student " << studentID << " removed." << endl;
		printAll();
	}
	else
		cout << "Student " << studentID << " not found." << endl;
}

classRoster::~classRoster()
{
	for (int i = 0; i < numStudents; ++i)
	{
		cout << "Student successfully destructed: " << students[i]->getStudentID() << endl;
		delete students[i];
		students[i] = nullptr;
	}
}