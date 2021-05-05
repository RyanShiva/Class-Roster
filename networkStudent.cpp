#include <iostream>
#include "networkStudent.h"

using namespace std;

NetworkStudent::NetworkStudent()
	: Student() {
	major = NETWORKING;
}

NetworkStudent::NetworkStudent(string studID, string fstName, string lstName, string eAddress, int studAge, int* studCourseDays, Degree studMajor)
	: Student(studID, fstName, lstName, eAddress, studAge, studCourseDays, studMajor) {
	major = NETWORKING;
}

Degree NetworkStudent::GetDegree() {
	return NETWORKING;
}

void NetworkStudent::SetDegree(Degree studMajor) {
	major = studMajor;
}

void NetworkStudent::Print() {
	Student::Print();
	cout << "\tDegree Program: Network" << endl;
}

NetworkStudent::~NetworkStudent() {
	Student::~Student();
}