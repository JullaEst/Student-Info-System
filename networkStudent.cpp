#include <iostream>
#include "networkStudent.h"
using std::cout;
using std::endl;

NetworkStudent::NetworkStudent():Student()
{
degree = NETWORK;
}

NetworkStudent::NetworkStudent(string studentId, string firstName, string lastName, string emailAddress, string age, int* courseDays, DegreeType degree)
{
	degree = NETWORK;
}


DegreeType NetworkStudent::getDegreeType()
{
	return NETWORK;
}

void NetworkStudent::print() {
cout << getstudentId() << endl;
cout << "First Name:" << getfirstName() << endl;
cout << "Last Name" << getlastName() << endl;
cout << "Age:" << getAge() << endl;
cout << "Days In Course:" << getcourseDays()[0] << endl;
cout << "NETWORK" << endl;
}

//destructor
NetworkStudent::~NetworkStudent() 
{
	Student::~Student();
}
