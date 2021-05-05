#pragma once
#include <iostream>
#include <string>
#include "student.h"
using namespace std;

const int NUM_STUDENTS = 5;



class Roster {
public:
	int lastIndex;
	
	Roster();					// Default Constructor
	
	void add(string studID, string fstName, string lstName, string eAddress, int studAge, int CourseDays1, int CourseDays2, int CourseDays3, Degree studMajor);
	void remove(string studID);
	void printAll();
	void printDaysInCourse(string studID);
	void printInvalidEmails();
	void printByDegreeProgram(int studMajor);
	Student* getStudentAt(int index);

	virtual ~Roster();			// Destructor

private:
	Student* classRosterArray[NUM_STUDENTS];
};