#pragma once
#include <string>
#include "student.h"

class Roster {
	private:
		int lastIndex = -1;
		const static int numStudents = 5;
		Student* studentRosterArray[numStudents];

	public:
		void parse(string row);

		void add(string AstudentID, string AfirstName, string AlastName, string Aemail, int Aage, int day1, int day2, int day3, DEGREE Adegree);

		void printAll();
		void printByDegreeType(DEGREE Adegree);
		void printInvaildEmails();
		void printAverageDays(string studentID);
		void remove(string studentID);
		string getSID(int studentNo);

		~Roster();

};