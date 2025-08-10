/*Class:c867
* Name: Emily Joseph
* Date: 10/6/24
*/
#pragma once

#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include <array>
#include "degree.h"

using namespace std;

/* declarations */

class Roster {

private:

	Student* classRosterArray[5];
	int classSize;
	int ind;

public:

	Roster(int classSize);
	string GetStudentID(int index);
	void parse(string studentData);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

	void add(string studentID, string firstName, string lastName, string email,
		int studentAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	~Roster();

};

#endif
