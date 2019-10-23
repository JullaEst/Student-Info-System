#pragma once
#include <string>
#include "Student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"

class Roster {

protected:
	int lastIndex;
	int capacity;
	Student** classRosterArray;


public: 
	Roster();
	Roster(int capacity);
	Student*getStudentAt(int index);

	void parseThenAdd(string row);
	void add(string studentId, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeType degree);
	void remove(string studentId);
	void printAll();
	void printAverageCourseDays(string studentId);
	void printInvalidEmails();
	void printByDegreeType(int degree);

	~Roster();

};
