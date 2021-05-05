#pragma once
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

class SecurityStudent : public Student {
	public:
		SecurityStudent();																														//Default Constructor
		SecurityStudent(string studID, string fstName, string lstName, string eAddress, int studAge, int* studCourseDays, Degree studMajor);	// Overloaded Constructor
		
		Degree GetDegree();
		void SetDegree(Degree studMajor);
		void Print();

		~SecurityStudent();									//Destructor
};