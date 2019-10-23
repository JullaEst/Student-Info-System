#pragma once
#include <string>
#include <string>
#include "Degree.h"
#include "Student.h"

class SoftwareStudent : public Student {

	//constructors 
public:
	SoftwareStudent();
	SoftwareStudent(
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
	~SoftwareStudent();
};
	
