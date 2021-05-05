#include <string>
#include "roster.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "degree.h"
using namespace std;

Roster::Roster() {
	lastIndex = -1;
	int i = 0;
	for (i = 0; i < NUM_STUDENTS; ++i) {
		classRosterArray[i] = nullptr;
	}
}

void Roster::add(string studID, string fstName, string lstName, string eAddress, int studAge, int CourseDays1, int CourseDays2, int CourseDays3, Degree studMajor) {
	int CourseDays[Student::NUM_ARRAY_ELEMENTS];
	CourseDays[0] = CourseDays1;
	CourseDays[1] = CourseDays2;
	CourseDays[2] = CourseDays3;
	if (studMajor == SECURITY) {
		classRosterArray[lastIndex] = new SecurityStudent(studID, fstName, lstName, eAddress, studAge, CourseDays, studMajor);
	}
	else if (studMajor == SOFTWARE) {
		classRosterArray[lastIndex] = new SoftwareStudent(studID, fstName, lstName, eAddress, studAge, CourseDays, studMajor);
	}
	else {
		classRosterArray[lastIndex] = new NetworkStudent(studID, fstName, lstName, eAddress, studAge, CourseDays, studMajor);
	}
}

void Roster::remove(string studID) {
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) {
		if (classRosterArray[i]->GetStudentID() == studID) {
			found = true;
			delete classRosterArray[i];
			classRosterArray[i] = classRosterArray[lastIndex];
			--lastIndex;
		}
	}
	if (found == false) {
		cout << "Student with ID number " << studID << " does not exist." << endl;
	}
	else {
		cout << "Student with ID number " << studID << " successfully removed." << endl;
	}
	cout << endl;
}


void Roster::printAll() {
	for (int i = 0; i <= lastIndex; ++i) {
		classRosterArray[i]->Print();
	}
}

void Roster::printDaysInCourse(string studID) {
	for (int i = 0; i <= lastIndex; ++i) {
		if (classRosterArray[i]->GetStudentID() == studID) {
			int* pointer = classRosterArray[i]->GetDaysInCourse();
			cout << "The average number of days for " << classRosterArray[i]->GetFirstName() << " " << classRosterArray[i]->GetLastName() << " to finish a course is "
				<< (pointer[0] + pointer[1] + pointer[2]) / Student::NUM_ARRAY_ELEMENTS << "." << endl;
		}
	}
}


void Roster::printInvalidEmails() {
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i) {
		string tempEmail = classRosterArray[i]->GetEmail();
		if (tempEmail.find('.') == string::npos ||
			tempEmail.find(' ') != string::npos ||
			tempEmail.find('@') == string::npos) {
			cout << tempEmail << " is an invalid email address." << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "All student emails are valid." << endl;
	}
	cout << endl;
}

void Roster::printByDegreeProgram(int studMajor) {
	cout << "Printing students with " << degreeStrings[studMajor] << " major:" << endl;
	for (int i = 0; i <= lastIndex; ++i) {
		if (classRosterArray[i]->GetDegree() == studMajor) {
			classRosterArray[i]->Print();
		}
	}
	cout << endl;
}

Student* Roster::getStudentAt(int index) {
	return classRosterArray[index];
}

Roster::~Roster() {
	for (int i = 0; i <= lastIndex; ++i) {
		delete classRosterArray[i];
	}
}

void main() {
	cout << "Scripting and Programming - Applications - C867" << endl
		<< "Language: C++" << endl
		<< "Student ID: #001172628" << endl
		<< "Alec Shiva" << endl << endl;
		
	//Raw string student data.
	const string studentData[NUM_STUDENTS] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Alec,Shiva,ashiva@wgu.edu,21,26,4,55,SOFTWARE"
	};
	Roster classRoster;
	
	// This loop parses the strings and adds the Student objects to classRoster.
	for (int i = 0; i < NUM_STUDENTS; ++i) {
		++classRoster.lastIndex;
		Degree tempDegree;
		string tempString = studentData[i];
		if (tempString.substr(tempString.length() - 8, 8) == "SECURITY") {
			tempDegree = SECURITY;
		}
		else if (tempString.substr(tempString.length() - 8, 8) == "SOFTWARE") {
			tempDegree = SOFTWARE;
		}
		else if (tempString.substr(tempString.length() - 7, 7) == "NETWORK") {
			tempDegree = NETWORKING;
		}
		else {
			cout << "Error. Invalid major." << endl;
			exit(-1);
		}

		int startFind = 0;
		int length = tempString.find(",");
		string tempID = tempString.substr(startFind, length);

		startFind = startFind + length + 1;
		length = tempString.find(",", startFind) - startFind;
		string tempFirstName = tempString.substr(startFind, length);

		startFind = startFind + length + 1;
		length = tempString.find(",", startFind) - startFind;
		string tempLastName = tempString.substr(startFind, length);

		startFind = startFind + length + 1;
		length = tempString.find(",", startFind) - startFind;
		string tempEmail = tempString.substr(startFind, length);

		startFind = startFind + length + 1;
		length = tempString.find(",", startFind) - startFind;
		int tempAge = stoi(tempString.substr(startFind, length));

		startFind = startFind + length + 1;
		length = tempString.find(",", startFind) - startFind;
		int tempDays1 = stoi(tempString.substr(startFind, length));

		startFind = startFind + length + 1;
		length = tempString.find(",", startFind) - startFind;
		int tempDays2 = stoi(tempString.substr(startFind, length));

		startFind = startFind + length + 1;
		length = tempString.find(",", startFind) - startFind;
		int tempDays3 = stoi(tempString.substr(startFind, length));

		classRoster.add(tempID, tempFirstName, tempLastName, tempEmail, tempAge, tempDays1, tempDays2, tempDays3, tempDegree);
	}
		
	classRoster.printAll();
	cout << endl;
	classRoster.printInvalidEmails();
	for (int i = 0; i <= classRoster.lastIndex; ++i) {
		classRoster.printDaysInCourse(classRoster.getStudentAt(i)->GetStudentID());
	}
	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");
	classRoster.~classRoster();
	system("pause");
	return;
}