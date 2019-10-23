#include <iostream>
#include "softwareStudent.h"
using std::cout;
using std::endl;

SoftwareStudent::SoftwareStudent() :Student()
{
	degree = SOFTWARE;
}

SoftwareStudent::SoftwareStudent(string studentId, string firstName, string lastName, string emailAddress, string age, int* courseDays, DegreeType degree)
{
	degree = SOFTWARE;
}


DegreeType SoftwareStudent::getDegreeType()
{
	return SOFTWARE;
}

void SoftwareStudent::print() {
	cout << getstudentId() << endl;
	cout << "First Name:" << getfirstName() << endl;
	cout << "Last Name" << getlastName() << endl;
	cout << "Age:" << getAge() << endl;
	cout << "Days In Course:" << getcourseDays()[0] << endl;
	cout << "SOFTWARE" << endl;
}

//destructor
SoftwareStudent::~SoftwareStudent()
{
	Student::~Student();
}
