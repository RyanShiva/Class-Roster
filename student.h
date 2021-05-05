#pragma once

#include <string>
#include "degree.h"
using namespace std;

class Student {
	public:
		const static int NUM_ARRAY_ELEMENTS = 3;

		Student();																														// Default Constructor
		Student(string studID, string fstName, string lstName, string eAddress, int studAge, int* studCourseDays, Degree studMajor);	// Overloaded Constructor

		void SetStudentID(string studID);								// Mutator
		void SetFirstName(string fstName);								// Mutator
		void SetLastName(string lstName);								// Mutator
		void SetEmail(string eAddress);									// Mutator
		void SetAge(int studAge);										// Mutator
		void SetDaysInCourse(int studCourseDays[]);						// Mutator
		virtual void SetDegree(Degree studMajor) = 0;					// Mutator

		string GetStudentID() const;									// Accessor
		string GetFirstName() const;									// Accessor
		string GetLastName() const;										// Accessor
		string GetEmail() const;										// Accessor
		int GetAge() const;												// Accessor
		int* GetDaysInCourse();											// Accessor
		virtual Degree GetDegree() = 0;									// Accessor

		virtual void Print() = 0;
		~Student();														// Destructor
		

	protected:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int daysInCourse[NUM_ARRAY_ELEMENTS];
		Degree major;
};