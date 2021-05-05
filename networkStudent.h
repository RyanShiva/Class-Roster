#pragma once
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

class NetworkStudent : public Student {
public:
	NetworkStudent();																														//Default Constructor
	NetworkStudent(string studID, string fstName, string lstName, string eAddress, int studAge, int* studCourseDays, Degree studMajor);	// Overloaded Constructor

	Degree GetDegree();
	void SetDegree(Degree studMajor);
	void Print();

	~NetworkStudent();									//Destructor
};