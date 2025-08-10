/*Class:c867
* Name: Emily Joseph
* Date: 10/6/24
*/
#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;


/* part d.1, student class variables */

class Student {

	/* private  strings, ints, degree program*/

private:

	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;
	
	/* public*/

public:

	/* student info */

	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
	void setID(string sID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int studentAge);
	void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void setDegreeProgram(DegreeProgram degreeProgram);
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getDaysInCourse();
	
	/* degree info*/

	DegreeProgram getDegreeProgram();
	void printID();
	void printFirstName();
	void printLastName();
	void printEmailAddress();
	void printAge();
	void printDaysToComp();
	void printDegreeProgram();
	void print();

};


#endif