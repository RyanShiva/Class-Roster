#include <iostream>
#include "softwareStudent.h"

using namespace std;

SoftwareStudent::SoftwareStudent()
	: Student() {
	major = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studID, string fstName, string lstName, string eAddress, int studAge, int* studCourseDays, Degree studMajor)
	: Student(studID, fstName, lstName, eAddress, studAge, studCourseDays, studMajor) {
	major = SOFTWARE;
}

Degree SoftwareStudent::GetDegree() {
	return SOFTWARE;
}

void SoftwareStudent::SetDegree(Degree studMajor) {
	major = studMajor;
}

void SoftwareStudent::Print() {
	Student::Print();
	cout << "\tDegree Program: Software" << endl;
}

SoftwareStudent::~SoftwareStudent() {
	Student::~Student();
}