//
//  roster.cpp
//  c867
//
//  Created by Christian Gobin on 5/13/21.
//

#include "roster.hpp"
#include "./student.hpp"
#include "./degree.h"

#include <iostream>
#include <string>

//E1 - E2
//Array of pointers that are Student objects.
//Constructor
Roster::Roster(){};

//Destructor
Roster::~Roster(){
	for(int i = 0; i < num_of_students; i++){
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
};


void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int c1, int c2, int c3, DegreeProgram student_DP){
	//append new student to end of classRosterArray.
	classRosterArray[++roster_last_index] = new Student(studentID, firstName, lastName, emailAddress, age, c1, c2, c3, student_DP);
}

void Roster::remove(std::string studentID){
	bool success = false; //assume student not there
	for(int i = 0; i <= Roster::roster_last_index; i++){
		if(studentID == classRosterArray[i]->get_student_ID()){
			success = true;
			if(i < num_of_students - 1){
				//move student into last position.
				//then decrement to no longer access student.
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[num_of_students - 1];
				classRosterArray[num_of_students - 1] = temp;
			}
			Roster::roster_last_index--; //Removes last student from roster;
		}
	}
	if(success){
		std::cout << studentID << " removed from roster." << std::endl;
		//this->printAll();
	} else {
		std::cout << studentID << " not found. " << std::endl;
	}
}

void Roster::printAll(){
	for(int i = 0; i <= Roster::num_of_students; i++){
		std::cout << classRosterArray[i]-> print();
	}
}

//iterate through each student object in class roster array
//if studentID matches given studentID:
//				add each value of days left to complete array to total days int
//				then calculate avg days and cout avg.
void Roster::printAverageDaysInCourse(std::string studentID){
    for(int i = 0; i <= Roster::roster_last_index; i++){
        if(studentID == classRosterArray[i]->get_student_ID()){
            int averageDays = (classRosterArray[i]->get_days_to_complete(0) + classRosterArray[i]->get_days_to_complete(1) + classRosterArray[i]->get_days_to_complete(2)) / 3;
            std::cout << "Average Days left for Student: " << classRosterArray[i]->get_student_ID() << ": " << averageDays << std::endl;
            break;//stop loop when we find the correct ID.
        }
    }
}

//Valid email must include '@' and '.'
//Display invalid emails.
void Roster::printInvalidEmails(){
	bool any = false; //assume no invalid emails.
	//loop through each student obj in class roster
	//set student email to string
	//check each student email for required chars @ and . 
	//also check for space character
	for(int i = 0; i <= Roster::roster_last_index; i++){
		std::string student_email = (classRosterArray[i]->get_email());
		if(student_email.find('@') == std::string::npos || (student_email.find('.') == std::string::npos || (student_email.find(' ') != std::string::npos))){
			any = true;
			std::cout << "Invalid Email: " << student_email << std::endl;
		}
	}
	if(!any){
		std::cout << "NONE FOUND" << std::endl;
	}
}

void Roster::printByDegreeProgram(DegreeProgram student_DP){
	for(int i = 0; i <= Roster::roster_last_index; i++){
		if(Roster::classRosterArray[i]-> get_degree_program() == student_DP){
			classRosterArray[i]->print();
            std::cout << std::endl;
		}
	} 
	std::cout << std::endl;
}
//Format of string to be parsed.
//ID, First, Last, Email, Age, C1, c2, c3, Degree

//parse row of string data and store values to later create object.
/*
 Basic function:
 find location in string of the commas.
 assign data found to left and right of comma to appropriate properties.
 */
void Roster::body_parser(std::string row){
	int rhs = row.find(",");
	std::string studentID = row.substr(0, rhs); //Get student ID substring infront of the first comma.
	
	int lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string firstName = row.substr(lhs, rhs - lhs); //First Name
	
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string lastName = row.substr(lhs, rhs - lhs); //Last Name
	
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string emailAddress = row.substr(lhs, rhs - lhs); //Email
	
	//convert strings to ints.
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int age = stoi(row.substr(lhs, rhs - lhs)); //Age
	
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int c1 = stoi(row.substr(lhs, rhs - lhs)); //Course 1
	
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int c2 = stoi(row.substr(lhs, rhs - lhs)); //Course 2
	
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int c3 = stoi(row.substr(lhs, rhs - lhs)); //Course 3
	
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string student_DP = row.substr(lhs, rhs - lhs);
	//determine degree program using string values.
	DegreeProgram studentDP;
	if(student_DP == "DEFAULT"){
		studentDP = DEFAULT;
	} else if(student_DP == "SECURITY"){
		studentDP = SECURITY;
	} else if(student_DP == "NETWORK"){
		studentDP = NETWORK;
	} else {
		studentDP = SOFTWARE;
	}
	
	//creates student object using the above defined variables.
	add(studentID, firstName, lastName, emailAddress, age, c1, c2, c3, studentDP);

};
