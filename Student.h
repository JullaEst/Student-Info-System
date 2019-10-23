#pragma once
#include <string>
#include "Degree.h"
using std::string;

class Student
{

public:

	const static int courseArraySize = 3;

protected:
	string studentId;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseDays[courseArraySize]; 
	DegreeType degree;

public:

	Student();

	Student(string studentId, string firstName, string lastName, string emailAddress, int age, int courseDays[], DegreeType degree);

	//getters
	string getstudentId();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getAge();
	int* getcourseDays();
	virtual DegreeType getDegreeType() = 0;

	//setters
	void setstudentId(string studentId);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemailAddress(string emailAddress);
	void setAge(int age);
	void setcourseDays(int courseDays[]);
	void setDegreeType(DegreeType degree);

		virtual void print() = 0;

	//the destructor
		~Student();
};
