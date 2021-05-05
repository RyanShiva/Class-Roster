#include <iostream>
#include "securityStudent.h"
using namespace std;

SecurityStudent::SecurityStudent()
	: Student() {
	major = SECURITY;
}

SecurityStudent::SecurityStudent(string studID, string fstName, string lstName, string eAddress, int studAge, int* studCourseDays, Degree studMajor)
	: Student(studID, fstName, lstName, eAddress, studAge, studCourseDays, studMajor) {
	major = SECURITY;
}

Degree SecurityStudent::GetDegree() {
	return SECURITY;
}

void SecurityStudent::SetDegree(Degree studMajor) {
	major = studMajor;
}

void SecurityStudent::Print() {
	Student::Print();
	cout << "\tDegree Program: Security" << endl;
}

SecurityStudent::~SecurityStudent() {
	Student::~Student();
}