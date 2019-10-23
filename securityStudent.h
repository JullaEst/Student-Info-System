#pragma once
#include <string>
#include "Degree.h"
#include "Student.h"

class SecurityStudent : public Student {

	//constructors 
public:
	SecurityStudent();
	SecurityStudent(
		string studentId,
		string firstName,
		string lastName,
		string emailAddress,
		string age,
		int* courseDays,
		DegreeType degree
	);

	DegreeType getDegreeType();

	void print();

	//destructor
	~SecurityStudent();
};
