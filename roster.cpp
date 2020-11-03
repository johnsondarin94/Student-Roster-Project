#include "roster.h"
#include "student.h"
#include "degree.h"
#include <iostream>
using namespace std;

Roster::Roster() {
	this->maxCap = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int maxCap) {
	this->maxCap = maxCap;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [maxCap];
}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	double daysInCourse[Student::daysToCompleteArraySize];

	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

	classRosterArray[lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}



void Roster::parsingTool(string row) {

	if (lastIndex < maxCap) {
		lastIndex++;
	}
	string tempDegreeStr;
	DegreeProgram degreeProgram{};

	int commaFinder = row.find(",");
	string studentID = row.substr(0, commaFinder);
	int commaPasser = commaFinder + 1;

	commaFinder = row.find(",", commaPasser);
	string firstName = row.substr(commaPasser, commaFinder - commaPasser);
	commaPasser = commaFinder + 1;

	commaFinder = row.find(",", commaPasser);
	string lastName = row.substr(commaPasser, commaFinder - commaPasser);
	commaPasser = commaFinder + 1;

	commaFinder = row.find(",", commaPasser);
	string emailAddress = row.substr(commaPasser, commaFinder - commaPasser);
	commaPasser = commaFinder + 1;

	commaFinder = row.find(",", commaPasser);
	string stiAge = row.substr(commaPasser, commaFinder - commaPasser);
	int age = stoi(stiAge);
	commaPasser = commaFinder + 1;

	commaFinder = row.find(",", commaPasser);
	int daysInCourse1 = stoi(row.substr(commaPasser, commaFinder - commaPasser));
	commaPasser = commaFinder + 1;

	commaFinder = row.find(",", commaPasser);
	int daysInCourse2 = stoi(row.substr(commaPasser, commaFinder - commaPasser));
	commaPasser = commaFinder + 1;

	commaFinder = row.find(",", commaPasser);
	int daysInCourse3 = stoi(row.substr(commaPasser, commaFinder - commaPasser));
	commaPasser = commaFinder + 1;

	commaFinder = row.find(",", commaPasser);
	tempDegreeStr = row.substr(commaPasser, commaFinder - commaPasser);
	if (tempDegreeStr == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (tempDegreeStr == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else if (tempDegreeStr == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

}

void Roster::remove(string studentID) {
	bool studentIDFound = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			studentIDFound = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
		}
	}
	if (studentIDFound != true) {
		cout << "Student ID Not Found!" << endl;
	}

}

void Roster::printAll() {
	for (int i = 0; i <= lastIndex; i++) {
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			found = true;
			double* days = classRosterArray[i]->getDaysToComplete();
			cout << "Student ID: " << classRosterArray[i]->getStudentID() << " " << (days[0] + days[1] + days[2]) / 3 << endl;
		}
	}
	if (!found) cout << "Student not found, please check StudentID and try again." << endl;
}

void Roster::printInvalidEmails() {
	for (int i = 0; i <= lastIndex; i++) {
		string emailTester = classRosterArray[i]->getEmailAddress();
		if (emailTester.find('@') == string::npos) {
			cout << emailTester << endl;
		}
		else if (emailTester.find('.') == string::npos) {
			cout << emailTester << endl;
		}
		else if (emailTester.find(" ") != string::npos) {
			cout << emailTester << endl;
		}

	}
}
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int i = 0; i <= lastIndex; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == degreeProgram) {

			this->classRosterArray[i]->print();
		}

	}

}

// Pointer to student, used to retrieve student at given index (Primarily used for average day calculator)
Student* Roster::getStudent(int lastIndex) {
	return classRosterArray[lastIndex];
}

Roster::~Roster() {

	for (int i = 0; i < lastIndex; i++) {
		delete classRosterArray[i];
	}
	delete classRosterArray;
	cout << "Done." << endl;
}