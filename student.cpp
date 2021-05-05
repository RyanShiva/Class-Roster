#include <iostream>
#include <string>
#include <iomanip>
#include "student.h"
using namespace std;

Student::Student() {
	
	studentID = "";
	firstName = "";
	lastName = "";
	email = "";
	age = 0;

	int i = 0;
	for (i = 0; i < NUM_ARRAY_ELEMENTS; ++i) {
		daysInCourse[i] = 0;
	}

	// major = SECURITY;

	return;
}

Student::Student(string studID, string fstName, string lstName, string eAddress, int studAge, int* studCourseDays, Degree studMajor) {
	studentID = studID;
	firstName = fstName;
	lastName = lstName;
	email = eAddress;
	age = studAge;

	int i = 0;
	for (i = 0; i < NUM_ARRAY_ELEMENTS; ++i) {
		daysInCourse[i] = studCourseDays[i];
	}

	return;
}

void Student::SetStudentID(string studID) {
	studentID = studID;
	return;
}

void Student::SetFirstName(string fstName) {
	firstName = fstName;
	return;
}

void Student::SetLastName(string lstName) {
	lastName = lstName;
	return;
}

void Student::SetEmail(string eAddress) {
	email = eAddress;
	return;
}

void Student::SetAge(int studAge) {
	age = studAge;
	return;
}

void Student::SetDaysInCourse(int studCourseDays[]) {
	int i = 0;
	for (i = 0; i < NUM_ARRAY_ELEMENTS; ++i) {
		daysInCourse[i] = studCourseDays[i];
	}
return;
}

string Student::GetStudentID() const {
	return studentID;
}

string Student::GetFirstName() const {
	return firstName;
}

string Student::GetLastName() const {
	return lastName;
}

string Student::GetEmail() const {
	return email;
}

int Student::GetAge() const {
	return age;
}

int* Student::GetDaysInCourse() {
	return daysInCourse;
}

void Student::Print() {
	cout << GetStudentID();
	cout << "\tFirst Name: " << GetFirstName();
	cout << "\tLast Name: " << GetLastName();
	/*cout << "\tEmail: " << email;*/
	cout << "\tAge: " << GetAge();
	cout << "\tDays In Course: {" << GetDaysInCourse()[0] << ", " << GetDaysInCourse()[1] << ", " << GetDaysInCourse()[2] << "}";
}

Student::~Student() {
	return;
}