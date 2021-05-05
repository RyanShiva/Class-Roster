#pragma once
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

class SoftwareStudent : public Student {
public:
	SoftwareStudent();																														//Default Constructor
	SoftwareStudent(string studID, string fstName, string lstName, string eAddress, int studAge, int* studCourseDays, Degree studMajor);	// Overloaded Constructor

	Degree GetDegree();
	void SetDegree(Degree studMajor);
	void Print();

	~SoftwareStudent();									//Destructor
};