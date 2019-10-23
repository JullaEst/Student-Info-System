#include <iostream>
#include "securityStudent.h"
using std::cout;
using std::endl;

SecurityStudent::SecurityStudent() :Student()
{
	degree = SECURITY;
}

SecurityStudent::SecurityStudent(string studentId, string firstName, string lastName, string emailAddress, string age, int* courseDays, DegreeType degree)
{
	degree = SECURITY;
}


DegreeType SecurityStudent::getDegreeType()
{
	return NETWORK;
}

void SecurityStudent::print() {
	cout << getstudentId() << endl;
	cout << "First Name:" << getfirstName() << endl;
	cout << "Last Name" << getlastName() << endl;
	cout << "Age:" << getAge() << endl;
	cout << "Days In Course:" << getcourseDays()[0] << endl;
	cout << "SECURITY" << endl;
}

//destructor
SecurityStudent::~SecurityStudent()
{
	Student::~Student();
}

