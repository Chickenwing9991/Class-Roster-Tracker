#pragma once
#include <string>
#include <iostream>
#include "degree.h"

using namespace std;


class Student {

	public:
		Student();
		Student(string studentID, string firstName, string lastName, string email, int age, int days[], DEGREE degree);
		~Student();

	public:

		const static int daysArraySize = 3;
		/*Getters*/
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		int* getDays();
		DEGREE getDegree();
		int getAverageDaysInCourses();

		/*Setters*/
		void setStudentID(string id);
		void setFirstName(string name);
		void setLastName(string name);
		void setEmail(string mail);
		void setAge(int fage);
		void setDays(int days[]);
		void setDegree(DEGREE degree);
		


		static void printHeader();

		void print();

	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int days[daysArraySize];
		DEGREE degree;









};