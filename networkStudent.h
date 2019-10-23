#pragma once
#include <string>
#include "Degree.h"
#include "Student.h"

class NetworkStudent : public Student {

//constructors 
public:
	NetworkStudent();
	NetworkStudent(
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
	~NetworkStudent();
};
