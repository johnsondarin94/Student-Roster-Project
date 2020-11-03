#include <iostream>
#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;

int main() {
	cout << "Scripting and Programming - Applications - C867, C++, #001216025, Darin Johnson" << endl << endl;

	const int numStudentEntries = 5;
	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Darin,Johnson,djo1001@wgu.edu,26,30,28,35,SOFTWARE"
	};

	Roster* classRoster = new Roster(numStudentEntries);

	cout << "Parsing and adding students to roster..." << endl;
	for (int i = 0; i < numStudentEntries; i++) {
		classRoster->parsingTool(studentData[i]);
	}
	cout << "Done." << endl << endl;

	cout << "Displaying the entire roster of students..." << endl;
	classRoster->printAll();
	cout << "Done." << endl << endl;

	cout << "Displaying any invalid Emails..." << endl;
	classRoster->printInvalidEmails();
	cout << "Done." << endl << endl;

	cout << "Displaying average days in each course for the given students..." << endl;
	for (int i = 0; i < numStudentEntries; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudent(i)->getStudentID());
	}
	cout << "Done." << endl << endl;

	cout << "Displaying Students from Software program" << endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << "Done." << endl << endl;

	cout << "Removing student A3 from the roster..." << endl;
	classRoster->remove("A3");
	cout << "Done." << endl << endl;

	cout << "Displaying the entire roster of students..." << endl;
	classRoster->printAll();
	cout << "Done." << endl << endl;

	cout << "Removing student A3 from the roster..." << endl;
	classRoster->remove("A3");
	cout << "Done." << endl << endl;


	cout << "Calls the destructor to remove any dynamically allocated memory" << endl;
	classRoster->~Roster();
	cout << "Done." << endl << endl;

	system("pause");
	return 0;
}