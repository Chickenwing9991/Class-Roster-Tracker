#include <string>
#include "roster.h"
#include <vector>
#include "student.h"
#include "degree.h"

using namespace std;
static const string studentTypeStrings[3];

void Roster::parse(string studentdata) {
	DEGREE dg = SOFTWARE;


	//Parsing Through String and Assigning Each Part to a Variable for later Use.
	int comma = studentdata.find(",");
	string ID = studentdata.substr(0, comma);

	int lhs = comma + 1;
	comma = studentdata.find(",", lhs);
	string FirstName = studentdata.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(comma) - lhs);

	lhs = comma + 1;
	comma = studentdata.find(",", lhs);
	string LastName = studentdata.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(comma) - lhs);

	lhs = comma + 1;
	comma = studentdata.find(",", lhs);
	string Email = studentdata.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(comma) - lhs);

	lhs = comma + 1;
	comma = studentdata.find(",", lhs);
	int Age = stoi(studentdata.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(comma) - lhs));

	lhs = comma + 1;
	comma = studentdata.find(",", lhs);
	int Days1 = stoi(studentdata.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(comma) - lhs));
	lhs = comma + 1;
	comma = studentdata.find(",", lhs);
	int Days2 = stoi(studentdata.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(comma) - lhs));
	lhs = comma + 1;
	comma = studentdata.find(",", lhs);
	int Days3 = stoi(studentdata.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(comma) - lhs));

	lhs = comma + 1;
	comma = studentdata.find(",", lhs);
	string Degree = studentdata.substr(lhs, static_cast<std::basic_string<char, std::char_traits<char>, std::allocator<char>>::size_type>(comma) - lhs);

	DEGREE Degree2;

	if (Degree == "SECURITY") Degree2 = SECURITY;
	if (Degree == "NETWORK") Degree2 = NETWORK;
	if (Degree == "SOFTWARE") Degree2 = SOFTWARE;

	//Adding Parsed Info to Student Roster.
	add(ID, FirstName, LastName, Email, Age, Days1, Days2, Days3, Degree2);
}

//Add Function.
void Roster::add(string AstudentID, string AfirstName, string AlastName, string Aemail, int Aage, int day1, int day2, int day3, DEGREE Adegree) {
	int days[3] = { day1, day2, day3 }; 
	
	studentRosterArray[++lastIndex] = new Student(AstudentID, AfirstName, AlastName, Aemail, Aage, days, Adegree);
}

//Printing Student Info
void Roster::printAll() {

	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {

		studentRosterArray[i]->print();
	}
}

//Printing Student Info By Degree
void Roster::printByDegreeType(DEGREE degree) {
	Student::printHeader();
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (Roster::studentRosterArray[i]->getDegree() == degree) studentRosterArray[i]->print();
	}
	cout << std::endl;
}

//Checks for Invalid Emails and then Prints them.
void Roster::printInvaildEmails() {

	bool any = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		string ID = (studentRosterArray[i]->getEmail());
		if (ID.find('@') == string::npos || (ID.find('.') == string::npos)) {
			any = true;
			cout << ID << ": " << studentRosterArray[i]->getEmail() << std::endl;
		}
	}
	if (!any) cout << "No Invaild Emails" << std::endl;
}

//Calculates Avergae Days Per Class then Prints.
void Roster::printAverageDays(string studentID) {

	int stuID{};

	for (int i = 0; i < numStudents; i++) {
		if (studentRosterArray[i]->getStudentID() == studentID) {
			stuID = i;
		}
	}
	cout << "Student " << studentRosterArray[stuID]->getStudentID() << " "
		<< " has averaged "
		<< studentRosterArray[stuID]->getAverageDaysInCourses()
		<< " day(s) per course for the last three courses." << endl;

}

string Roster::getSID(int studentNo)
{
	return studentRosterArray[studentNo]->getStudentID();
}

//Removes Student by their ID.
void Roster::remove(string id) {

	bool deleted = false;
	for (int i = 0; i <= Roster::lastIndex; i++) {
		if (studentRosterArray[i]->getStudentID() == id) {
			deleted = true;
			if (i < numStudents - 1) {
				Student* stu = studentRosterArray[i];
				studentRosterArray[i] = studentRosterArray[numStudents - 1];
				studentRosterArray[numStudents - 1] = stu;
			}
			Roster::lastIndex--;
		}
	}
	if (deleted)
	{
		cout << id << " The Student was Removed" << std::endl << std::endl;
		this->printAll();
	}
	else cout << id << " Student Not Found." << std::endl << std::endl;
}
//Gets rid of Object.
Roster::~Roster() {
	cout << "DESTRUCTION INITATED!" << std::endl << std::endl;
	for (int i = 0; i < numStudents; i++) {
		delete studentRosterArray[i];
		studentRosterArray[i] = nullptr;
	}
}