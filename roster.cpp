/*Class:c867
* Name: Emily Joseph
* Date: 10/6/24
*/
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <array>
#include <string>
using namespace std;

/* part e */
/* class constructor */

/* part e.1 */
Roster::Roster(int classSize) {
	this->classSize = classSize;
	this->ind = 0;
	for (int i = 0; i < classSize; i++) {
		this->classRosterArray[i] = nullptr;
	}
}

string Roster::GetStudentID(int index) {

	string sID = classRosterArray[index]->getStudentID();
	return sID;
}

/* part e.2 */
/* parse method */

void Roster::parse(string studentDataTable) {

	string sID, firstname, lastname, emailAddress;
	int studentAge, daysInCourse1, daysInCourse2, daysInCourse3;

	if (ind < classSize) {

		classRosterArray[ind] = new Student();

		int i = studentDataTable.find(",");
		sID = studentDataTable.substr(0, i);
		classRosterArray[ind]->setID(sID);

		int d = i + 1;
		i = studentDataTable.find(",", d);
		firstname = studentDataTable.substr(d, i - d);
		classRosterArray[ind]->setFirstName(firstname);

		d = i + 1;
		i = studentDataTable.find(",", d);
		lastname = studentDataTable.substr(d, i - d);
		classRosterArray[ind]->setLastName(lastname);

		d = i + 1;
		i = studentDataTable.find(",", d);
		emailAddress = studentDataTable.substr(d, i - d);
		classRosterArray[ind]->setEmailAddress(emailAddress);

		d = i + 1;
		i = studentDataTable.find(",", d);
		studentAge = stoi(studentDataTable.substr(d, i - d));
		classRosterArray[ind]->setAge(studentAge);

		d = i + 1;
		i = studentDataTable.find(",", d);
		daysInCourse1 = stoi(studentDataTable.substr(d, i - d));

		d = i + 1;
		i = studentDataTable.find(",", d);
		daysInCourse2 = stoi(studentDataTable.substr(d, i - d));

		d = i + 1;
		i = studentDataTable.find(",", d);
		daysInCourse3 = stoi(studentDataTable.substr(d, i - d));
		classRosterArray[ind]->setDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);

		d = i + 1;
		i = studentDataTable.find(",", d);
		string type = studentDataTable.substr(d, i - d);
		if (type == "SOFTWARE") {
			classRosterArray[ind]->setDegreeProgram(SOFTWARE);
		}
		else if (type == "SECURITY") {
			classRosterArray[ind]->setDegreeProgram(SECURITY);
		}
		else if (type == "NETWORK") {
			classRosterArray[ind]->setDegreeProgram(NETWORK);
		}
		else {
			cout << "Degree not found" << endl;
		}
		ind++;
	}
}

/* part d.3 */
/* add Student to roster */

void Roster::add(string studentID, string firstName, string lastName, string email, int age,
	int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {

	int daysInCourse[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };

	classRosterArray[classSize] = new Student(studentID, firstName, lastName, email, age, daysInCourse, degreeProgram);
};



/* remove student */

void Roster::remove(string id) {
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] && classRosterArray[i]->getStudentID() == id) {
			delete classRosterArray[i];
			classRosterArray[i] = nullptr;
			cout << "Student " << id << " removed." << endl;
			return;
		}
	}
	cout << "Error: Student " << id << " Not Found." << endl;
}

/* print all students */

void Roster::printAll() {
	cout << "All current students: " << endl;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i] == nullptr) {
			continue;
		} else {
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}
/* print average days in class */

void Roster::printAverageDaysInCourse(string id) {
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i]->getStudentID() == id) {
			auto days = classRosterArray[i]->getDaysInCourse();
			cout << id << "'s average days: " << (days[0] + days[1] + days[2]) / 3 << endl;
		}
	}
}

/* print invalid emails */

void Roster::printInvalidEmails() {
	cout << "Display invalid emails: " << endl;
	for (int i = 0; i < classSize; ++i) {
		string emailAd = classRosterArray[i]->getEmailAddress();
		if ((emailAd.find('@') == string::npos) || (emailAd.find(' ') != string::npos) || (emailAd.find('.') == string::npos)) {
			cout << "Invalid Email Addresses:" << classRosterArray[i]->getStudentID() << " email address " << emailAd << " is invalid." << endl;
		}
	}
	cout << endl;
}


/* print students with degree program */

void Roster::printByDegreeProgram(DegreeProgram degPro) {
	cout << "Students in degree program: " << (degPro == SECURITY ? "SECURITY" : degPro == NETWORK ? "NETWORK" : "SOFTWARE") << endl;
	for (int i = 0; i < classSize; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degPro) classRosterArray[i]->print();
	}
}

/* destructor */

Roster::~Roster() {
	
}