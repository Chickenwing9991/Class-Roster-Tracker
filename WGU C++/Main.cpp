// WGU C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "student.h"
#include "roster.h"

using namespace std;


int main()
{
	cout << "Patrick Fuller, StudentID: 000820715, Course: Scripting and Programming - Applications - C867, Language: C++" << endl;
	//String that Needs parsing, Student Data
	const std::string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Patrick,Fuller,pfulle7@wgu.edu,23, 22, 32, 58,SOFTWARE" };

	const int numStudents = 5;

	Roster rost;

	//Calling PrintAll Function to show all Students.
	for (int i = 0; i < numStudents; i++) rost.parse(studentData[i]);
	cout << "Showing All Students" << std::endl;
	rost.printAll();
	cout << std::endl;

	///Calling PrintByDegree to Show Students by Degree
	for (int i = 0; i < 3; i++) {
		cout << "Showing Students By Degree: " << DEGREEStrings[i] << std::endl;
		rost.printByDegreeType((DEGREE)i);
	}

	///Calling PrintInvaildEmails to find invaild emails.
	cout << "Showing Students with Invaild Emails" << std::endl;
	rost.printInvaildEmails();
	cout << std::endl;

	//Calculating Average Days in a Class per student
	//cout << "Showing Average Days in Class" << std::endl;
	//rost.printAverageDays("");

	cout << endl << "Calculating Average Days in Class for each student:" << std::endl;
	for (int i = 0; i < numStudents; i++) {
		cout << i << endl;
		rost.printAverageDays(rost.getSID(i));
	}


	//Removes a Student from the Roster and Prints table again.
	cout << '\n';
	cout << "Remove A Student with the ID A3: " << std::endl;
	rost.remove("A3");
	cout << std::endl;

	system("pause");
	return 0;

}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
