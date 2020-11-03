#pragma once
#include "student.h"
#include "degree.h"
#include <iostream>
using namespace std;

class Roster {
private:
	int lastIndex;
	int maxCap;
	Student** classRosterArray;
public:
	Roster();  //Empty constructor 
	Roster(int maxCap); // Constructor that takes the maximum capacity of the roster as a parameter
	void parsingTool(string row); // Parses string separating it into parameters for student class
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram); // adds parsed string to the class roster
	void remove(string studentId); // removes a student from the roster based on whether the passed parameter student ID exists
	void printAll(); // prints all students in the roster 
	void printAverageDaysInCourse(string studentID); // takes the average of the 3 days in course and prints the result as a double, takes student ID as a parameter
	void printInvalidEmails(); //searches through the email roster for any spaces, @, and . symbols and prints any results that lack or contain them.
	void printByDegreeProgram(DegreeProgram degreeProgram); //Prints students in the roster based on the enumerated value
	Student* getStudent(int lastIndex);// Returns current student in roster
	~Roster(); // removes any dynamically allocated memory from the roster
};