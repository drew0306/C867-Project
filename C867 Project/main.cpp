// C867 Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "roster.h"

using namespace std;

int main()
{
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Andrew,Barry,abar649@wgu.edu,29,25,30,40,SOFTWARE",
    };
    const int numStudents = 5;
    classRoster classRoster; // sets everything to 0
        
    
    cout << "Scripting and Programming - Applications - C867\n";
    cout << "Coded in C++\n";
    cout << "Student ID: 001512200\n";
    cout << "Student name: Andrew Barry\n";

    cout << endl;
    for (int i = 0; i < numStudents; ++i)
        classRoster.parseStudents(studentData[i]);
    cout << "Displaying all students:" << endl;
    classRoster.printAll();

  
    cout << endl;
    cout << "Displaying invalid emails:" << endl;
    cout << endl;
    classRoster.printInvalidEmails();

    cout << endl;
    cout << "Displaying average number of days spent in courses:" << endl;
    for (int i = 0; i < numStudents; ++i)
        classRoster.printAverageDays(classRoster.getStudents()[i]->getStudentID());

    cout << endl;
    cout << "Showing students in degree program: SOFTWARE";
    cout << endl;
    cout << endl;
    classRoster.printByDegree(DegreeProgram::SOFTWARE);

    cout << endl;
    cout << "Removing student A3:" << endl;
    classRoster.removeStudent("A3");
    cout << "Removing student A3:" << endl;
    classRoster.removeStudent("A3");
    system("pause");
    cout << "The End\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
