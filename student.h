#pragma once
#include <string>
#include <array>
#include "degree.h"

using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double* daysToComplete;
	DegreeProgram degreeType;

public:
	const static int daysToCompleteArraySize = 3;
	Student(); // Empty Constructor
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysToComplete[], DegreeProgram degreeType); // Constructor with parameters
	//getters
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	double* getDaysToComplete();
	DegreeProgram getDegreeProgram();
	//setters or manipulators
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysToComplete(double daysToComplete[]);
	void setDegreeProgram(DegreeProgram degreeProgram);
	void print();

	~Student();//destructor used to remove anything dynamically allocated 

};