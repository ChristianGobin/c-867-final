//  student.cpp
//  c867//  Created by Christian Gobin on 5/13/21.
//
#include "student.hpp"
#include "degree.h"
#include <iostream>
#include <string>


//D2-d Constructor using all params of input table.
Student::Student(std::string student_ID, std::string first_name, std::string last_name, std::string email_address, int age, int daysToComplete[], DegreeProgram student_DP){
	this -> student_ID = student_ID;
	this -> first_name = first_name;
	this -> last_name = last_name;
	this -> email_address = email_address;
	this -> age = age;
	this -> days_to_complete[0] = daysToComplete[0];
	this -> days_to_complete[1] = daysToComplete[1];
	this -> days_to_complete[2] = daysToComplete[2];
	this -> student_DP = student_DP;
}

Student::~Student(){
	return;
}


//D2-e Student print() specific values
void Student::print(){
	std::cout << student_ID  << "\t";
	std::cout << "First Name: " << first_name << "\t";
	std::cout << "Last Name: " << last_name << "\t";
	std::cout << "Age: " << age << "\t";
	std::cout << "Days Left In Courses: {" << days_to_complete[0] << ", " << days_to_complete[1] << ", " << days_to_complete[2] << "}\t ";
	switch(student_DP){
		case 0: //default
			std::cout << "Degree Program: DEFAULT" << std::endl;
			break;
		case 1: //security
			std::cout << "Degree Program: SECURITY" << std::endl;
			break;
		case 2: //network
			std::cout << "Degree Program: NETWORK" << std::endl;
			break;
		case 3: //software
			std::cout << "Degree Program: SOFTWARE" << std::endl;
			break;
	}
	
}


//Accessors
std::string Student::get_student_ID(){
	return student_ID;
}

std::string Student::get_first_name(){
	return first_name;
}

std::string Student::get_last_name(){
	return last_name;
}

std::string Student::get_email(){
	return email_address;
}

int Student::get_age(){
	return age;
}

int Student::get_days_to_complete(int course_index){
	return days_to_complete[course_index];
}

DegreeProgram Student::get_degree_program(){
	return student_DP;
}

//Mutators
void Student::set_student_ID(std::string new_ID){
	student_ID = new_ID;
}	
	
void Student::set_first_name(std::string new_first_name){
	first_name = new_first_name;
}

void Student::set_last_name(std::string new_last_name){
	last_name = new_last_name;
}

void Student::set_email(std::string new_email){
	email_address = new_email;
}

void Student::set_age(int new_age){
	age = new_age;
}

void Student::set_days_to_complete(int daysToComplete[]){
	days_to_complete[0] = daysToComplete[0];
	days_to_complete[1] = daysToComplete[1];
	days_to_complete[2] = daysToComplete[2];
}

void Student::set_degree_program(DegreeProgram new_degree_program){
	student_DP = new_degree_program;
}

/*
std::string student_ID, first_name, last_name, email_address;
int age, days_to_complete[3];
DegreeProgram student_DP;

*/