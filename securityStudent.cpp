#include <iostream>
#include "securityStudent.h"
using std::cout;
using std::endl;

SecurityStudent::SecurityStudent() :Student()
{
	degree = SECURITY;
}

SecurityStudent::SecurityStudent(string studentId, string firstName, string lastName, string emailAddress, string age, int* courseDays, DegreeType degree)
	:Student(studentId, firstName, lastName, emailAddress, age, courseDays, degree)
{
	degree = SECURITY;
}


DegreeType SecurityStudent::getDegreeType()
{
	return NETWORK;
}

void SecurityStudent::print() 
{
	Student::print();
	cout << "SECURITY" << endl;
}

//destructor
SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}

