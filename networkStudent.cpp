#include <iostream>
#include "networkStudent.h"
using std::cout;
using std::endl;

NetworkStudent::NetworkStudent() :Student()
{
	degree = NETWORK;
}

NetworkStudent::NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, string age, int* courseDays, DegreeType degree)
	:Student(studentId, firstName, lastName, emailAddress, age, courseDays, degree)
{
	degree = NETWORK;
}


DegreeType NetworkStudent::getDegreeType()
{
	return NETWORK;
}

void NetworkStudent::print() 
{
	Student::print();
	cout << "NETWORK" << endl;
}

//destructor
NetworkStudent::~NetworkStudent()
{
	Student::~Student();
}
