#include "student.h"
#include <iostream>
#include <iomanip>

using namespace std;

//Default Constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysToComplete = new double[daysToCompleteArraySize];
	for (int i = 0; i < daysToCompleteArraySize; i++) {
		this->daysToComplete[i] = 0;
	}
	this->degreeType = SOFTWARE;

}

//Constructor with parameters
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double daysToComplete[], DegreeProgram degreeType) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysToComplete = new double[daysToCompleteArraySize];
	for (int i = 0; i < daysToCompleteArraySize; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
	this->degreeType = degreeType;

}


//getters
string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

double* Student::getDaysToComplete() {
	return daysToComplete;
}

DegreeProgram Student::getDegreeProgram() {
	return degreeType;
}


//setters
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

void Student::setAge(int age) {
	this->age = age;
}

void Student::setDaysToComplete(double daysToComplete[]) {
	for (int i = 0; i < daysToCompleteArraySize; i++) {
		this->daysToComplete[i] = daysToComplete[i];
	}
}

void Student::setDegreeProgram(DegreeProgram degreeType) {
	this->degreeType = degreeType;
}


//Student Class Print Method
void Student::print() {
	double* dTC = getDaysToComplete();
	cout << getStudentID() << "\t";
	cout << getFirstName() << "\t";
	cout << getLastName() << "\t";
	cout << getEmailAddress() << "\t";
	cout << getAge() << "\t";
	cout << dTC[0] << "\t";
	cout << dTC[1] << "\t";
	cout << dTC[2] << "\t";
	cout << degreeProgramTypes[getDegreeProgram()] << "\t" << endl;

}


Student::~Student() {
	if (daysToComplete != nullptr) {
		delete[] daysToComplete;
		daysToComplete = nullptr;
	}
}