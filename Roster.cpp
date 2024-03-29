#include <iostream>
#include <string>
#include "Degree.h"
#include "Roster.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <iomanip>
using namespace std;
using std::cout;
using std::endl;
using std::cerr;


Roster::Roster()
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int capacity)
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student * [capacity];

}

Student* Roster::getStudentAt(int index)
{
	return classRosterArray[index];
}

void Roster::parseThenAdd(string row)

{
	if (lastIndex < capacity)
	{
		lastIndex++;
		DegreeType degree;

		//student Id
		int rhs = row.find(",");
		string studentId = row.substr(0, rhs);

		//first name
		int lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string firstName = row.substr(lhs, rhs - lhs);

		//last name
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string lastName = row.substr(lhs, rhs - lhs);

		//email address
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string emailAddress = row.substr(lhs, rhs - lhs);

		//age
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		string age = row.substr(lhs, rhs - lhs);

		//courseDays
		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs));

		lhs = rhs + 1;
		rhs = row.find(",", lhs);
		int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs));

		//degree
		//lhs = rhs + 1;
		//rhs = row.find(",", lhs);

		if (row.back() == 'K') {
			degree = NETWORK;
		}

		else if (row.back() == 'Y') {
			degree = SECURITY;
		}

		else if (row.back() == 'E') {
			degree = SOFTWARE;
		}

		else {
			cerr << "Invalid degree! Exit now!" << endl;
			exit(-1);
		}
		//std::cout << daysInCourse2 << "        " ; 

		add(studentId, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
	}
}

void Roster::add(string studentId, string firstName, string lastName, string emailAddress, string age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degree)
{
	int daysInCourse[Student::courseArraySize];
	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;
	switch (degree) {
	case NETWORK:
		classRosterArray[lastIndex] = new NetworkStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degree);
		break;
	case SECURITY:
		classRosterArray[lastIndex] = new SecurityStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degree);
		break;
	case SOFTWARE:
		classRosterArray[lastIndex] = new SoftwareStudent(studentId, firstName, lastName, emailAddress, age, daysInCourse, degree);
		break;

	default:
		cout << "Invalid degree type" << endl;
		break;
	}
}

void Roster::remove(string studentId) {
	bool found = false;
	
	for (int i = 0; i <= lastIndex && !found; i++) {
		if (this->classRosterArray[i]->getstudentId() == studentId) {
			found = true;
			delete this->classRosterArray[i];
			this->classRosterArray[i] = this->classRosterArray[lastIndex];
			lastIndex--;
			cout << studentId << " Removed" << endl;
		}
	}
	if (!found)
		cout << studentId << " Not Found" << endl;
}

void Roster::printAll() {
	for (int i = 0; i <= this->lastIndex; i++) {
		(this->classRosterArray[i]->print());
	}
}
void Roster::printAverageCourseDays(string studentId) {
	bool found = false;
	for (int i = 0; i <= lastIndex && !found; i++) {
		if (this->classRosterArray[i]->getstudentId() == studentId) {
			found = true;
			int* courseDays = this->classRosterArray[i]->getcourseDays();
			cout << "Average days in course for Student Id: " << studentId << " is " << (courseDays[0] + courseDays[1] + courseDays[2]) / 3.0 << endl;
		}
		else if (i >= this->lastIndex && !found) {
			cout << "Can not find " << studentId << "." << endl;
		}
	}
}

void Roster::printInvalidEmails() {
	for (int i = 0; i <= lastIndex; i++) {
		string emailAddress = classRosterArray[i]->getemailAddress();
		if ((emailAddress.find("@") == string::npos) || (emailAddress.find(" ") != string::npos) || (emailAddress.find(".") == string::npos)) {
			cout << "The email address for: " << classRosterArray[i]->getfirstName() << " " << classRosterArray[i]->getlastName() << " is not valid." << endl;
		}
	}
}

void Roster::printByDegreeType(int degree) {
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getDegreeType() == degree) {
			(this->classRosterArray)[i]->print();
		}
	}
}

int main() {
	cout << "C 867 Scripting and Programming - Applications" << endl;
	cout << "Programming language: C++" << endl;
	cout << "Student ID: 001040445" << endl;
	cout << "Name: Julla Estella" << endl;


	int numStudentData = 5;
	string studentData[5] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Julla,Estella,jestell@wgu.edu,33,30,20,24,SOFTWARE"
	};

	Roster* classRoster = new Roster(numStudentData);
	for (int i = 0; i < numStudentData; i++)
	{
		classRoster->parseThenAdd(studentData[i]);
	}

	classRoster->printAll();

	classRoster->printInvalidEmails();

	for (int i = 0; i < numStudentData; i++) {
		classRoster->printAverageCourseDays(classRoster->getStudentAt(i)->getstudentId());
	}

	cout << "Remove A3 \n";
	classRoster->remove("A3");

	cout << "Remove A3 \n";
	classRoster->remove("A3");


	
	system("pause");
	return 0;

};


Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; i++)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}
