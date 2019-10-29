#include <iostream>
#include "softwareStudent.h"
using std::cout;
using std::endl;

SoftwareStudent::SoftwareStudent() :Student()
{
	degree = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, string age, int* courseDays, DegreeType degree)
	:Student(studentId, firstName, lastName, emailAddress, age, courseDays, degree)
{
	degree = SOFTWARE;
}


DegreeType SoftwareStudent::getDegreeType()
{
	return SOFTWARE;
}

void SoftwareStudent::print() 
{
	Student::print();
	cout << "SOFTWARE" << endl;
}

//destructor
SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}
