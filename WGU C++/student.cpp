#include "student.h"
#include "degree.h"

Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->email = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; i++) this->days[i] = 0;
	this->degree = DEGREE::SOFTWARE;
}

Student::Student(string studentID, string firstName, string lastName, string email, int age, int days[], DEGREE degree) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	for (int i = 0; i < daysArraySize; i++) this->days[i] = days[i];
	this->degree = degree;
}

Student::~Student() {}

//Getters and Setters
void Student::setStudentID(string id) {
	this->studentID = id;
}

string Student::getStudentID() {
	return this->studentID;
}

void Student::setFirstName(string name) {
	this->firstName = name;
}

string Student::getFirstName() {
	return this->firstName;
}

void Student::setLastName(string name) {
	this->lastName = name;
}

string Student::getLastName() {
	return this->lastName;
}

void Student::setEmail(string femail) {
	this->email = femail;
}

string Student::getEmail() {
	return this->email;
}

void Student::setAge(int fage) {
	this->age = fage;
}

int Student::getAge() {
	return this->age;
}

void Student::setDays(int fdays[]) {
	for (int i = 0; i < daysArraySize; i++) this->days[i] = 0;
}

int* Student::getDays() {
	return this->days;
}

void Student::setDegree(DEGREE fdegree) {
	this->degree = fdegree;
}

DEGREE Student::getDegree() {
	return this->degree;
}

//Printing Header
void Student::printHeader() {
	cout << "StudentID|FirstName|LastName|Email|Age|Days|Degree\n";
}

//Printing Single Line
void Student::print() {
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmail() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDays()[0] << ',';
	cout << this->getDays()[1] << ',';
	cout << this->getDays()[2] << '\t';
	cout << DEGREEStrings[this->getDegree()] << '\n';
}


int Student::getAverageDaysInCourses()
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < 3; i++) {
		sum = sum + days[i];
	}
	return sum / 3;
}