//
//  student.cpp
//  c867_second_attempt
//
//  Created by Christian Gobin on 6/15/21.
//

#include "student.hpp"
#include "degree.h"
//
#include <string>
#include <iostream>
using namespace std;

Student::Student(string student_ID, string first_name, string last_name, string email_address, int age, int daysToComplete[], DegreeProgram student_DP)
{
	this->student_ID = student_ID;
	this->first_name = first_name;
	this->last_name = last_name;
	this->email_address = email_address;
	this->age = age;
	this->student_DP = student_DP;
	
	//Revision, take array instead of 3 individual ints.
	this->days_to_complete = new int [3]; // allocate memory for new array with length of 3
	for(int i = 0; i < 3; i++){ //iterate through array given in constructor
		this->days_to_complete[i] = daysToComplete[i]; //set each space of new array equal to given array values.
	}
}

Student::~Student(){
	delete [] days_to_complete;
}

//D2-A: an accessor (i.e., getter) for each instance variable from part D1
string Student::get_student_ID(){
	return student_ID;
}

string Student::get_first_name(){
	return first_name;
}

string Student::get_last_name(){
	return last_name;
}

string Student::get_email(){
	return email_address;
}

int Student::get_age(){
	return age;
}

int * Student::get_days_to_complete(){
	return days_to_complete;
}

DegreeProgram Student::get_degree_program(){
	return student_DP;
}

//D2-B: mutator (i.e., setter) for each instance variable from part D1
void Student::set_student_ID(string new_ID){
	this->student_ID = new_ID;
}

void Student::set_first_name(string new_first_name){
	this->first_name = new_first_name;
}

void Student::set_last_name(string new_last_name){
	this->last_name = new_last_name;
}

void Student::set_email(string new_email){
	this->email_address = new_email;
}

void Student::set_age(int new_age){
	this->age = new_age;
}

void Student::set_days_to_complete(int daysToComplete[]){
	int i = 0;
	while(i < 3){
		this->days_to_complete[i] = daysToComplete[i];
		i++;
	}
}

void Student::set_degree_program(DegreeProgram new_degree_program){
	this->student_DP = new_degree_program;
}

//D2-E: print() to print specific student data
void Student::print(){
	cout << student_ID  << "\t";
	cout << "First Name: " << first_name << "\t";
	cout << "Last Name: " << last_name << "\t";
	cout << "Age: " << age << "\t";
	cout << "Days Left In Courses: {" << days_to_complete[0] << ", " << days_to_complete[1] << ", " << days_to_complete[2] << "}\t ";
	switch(student_DP){
		case 0: //security
			cout << "Degree Program: SECURITY" << endl;
			break;
		case 1: //network
			cout << "Degree Program: NETWORK" << endl;
			break;
		case 2: //software
			cout << "Degree Program: SOFTWARE" << endl;
			break;
	}
	
}
/*
string student_ID, first_name, last_name, email_address;
int age, days_to_complete[3];
DegreeProgram student_DP;

*/

/*D.  For the Student class, do the following:
1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
•  student ID
•  first name
•   last name
•  email address
•  age
•  3 array of numbers of days to complete each course
•  degree program
2.  Create each of the following functions in the Student class:
a.  an accessor (i.e., getter) for each instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
d.  constructor using all of the input parameters provided in the table
e.  print() to print specific student data
*/
