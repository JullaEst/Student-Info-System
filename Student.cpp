#pragma once
#include <iostream>
#include <iomanip>
#include "Student.h"
using namespace std;
using std::cout;
using std::left;
using std::setw;

Student::Student() //empty constructor

{
	this->studentId = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < courseArraySize; i++) this->courseDays[i] = 0;

}

//full constructor
Student::Student(string studentId, string firstName, string lastName, string emailAddress, int age, int courseDays[], DegreeType degree)
{
	this->studentId = studentId;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < courseArraySize; i++) this->courseDays[i] = courseDays[i];
}

//getters
string Student::getstudentId() {
	return studentId;
}
string Student::getfirstName() {
	return firstName;
}
string Student::getlastName() {
	return lastName;
}
string Student::getemailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int* Student::getcourseDays() {
	return courseDays;
}


//setters
void Student::setstudentId(string studentId) {
	this->studentId = studentId;
}
void Student::setfirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setlastName(string lastName) {
	this->lastName = lastName;
}
void Student::setemailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setcourseDays(int courseDays[])
{
	for (int i = 0; i < 3; i++) {
		this->courseDays[i] = courseDays[i];
	}
}

//print method
void Student::print() {
	cout << left << setw(5) << getstudentId();
	cout << left << setw(10) << getfirstName();
	cout << left << setw(10) << getlastName();
	cout << left << setw(20) << getemailAddress();
	cout << left << setw(5) << getAge();
	cout << left << setw(5) << getcourseDays()[0];
	cout << left << setw(5) << getcourseDays()[1];
	cout << left << setw(10) << getcourseDays()[2];
}

//destructor
Student::~Student() {

}
