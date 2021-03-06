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
using namespace std;
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

/*
E3 - A. public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int
	daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the
	instance variables from part D1 and updates the roster.
*/
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram student_DP){
	int days_to_complete[3] {daysInCourse1, daysInCourse2 , daysInCourse3};
	classRosterArray[++roster_last_index] = new Student(studentID, firstName, lastName, emailAddress, age, days_to_complete, student_DP);
}

/*
E3 - B. public void remove(string studentID)  that removes students from the roster by student ID. 
		If the student ID does not exist, the function prints an error message indicating that the student was not found.
*/
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

/*
E3 - C. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
*/
void Roster::printAll(){
	for(int i = 0; i < Roster::pub_num_of_students; i++){
		classRosterArray[i]->print();
	}
}

/*
E3 - D.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student???s average number of days in the
	three courses. The student is identified by the studentID parameter.

*/
void Roster::printAverageDaysInCourse(std::string studentID){
    for(int i = 0; i <= Roster::roster_last_index; i++){
        if(studentID == classRosterArray[i]->get_student_ID()){
			//point at array of student with matching ID.
			//access values of array and calculate average.
			int* array_of_days = classRosterArray[i]->get_days_to_complete();
			int averageDays = (array_of_days[0] + array_of_days[1] + array_of_days[2]) / 3;
			std::cout << "Average Days left for Student: " << classRosterArray[i]->get_student_ID() << ": " << averageDays << std::endl;
            break;//stop loop when we find the correct ID.
        }
    }
}

//Valid email must include '@' and '.'
//E3 - E.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
void Roster::printInvalidEmails(){
	bool any = false; //assume no invalid emails.
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
/*

E3 - F.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program
	specified by an enumerated type.
*/
void Roster::printByDegreeProgram(DegreeProgram student_DP){
	for(int i = 0; i <= Roster::roster_last_index; i++){
		if(Roster::classRosterArray[i]-> get_degree_program() == student_DP){
			classRosterArray[i]->print();
            std::cout << std::endl;
		}
	} 
	std::cout << std::endl;
}

//parse row of string data and store values to later create object.
/*
E2 - A.  Parse each set of data identified in the ???studentData Table.???
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
	int daysInCourse1 = stoi(row.substr(lhs, rhs - lhs)); //Course 1
	
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse2 = stoi(row.substr(lhs, rhs - lhs)); //Course 2
	
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	int daysInCourse3 = stoi(row.substr(lhs, rhs - lhs)); //Course 3
	
	lhs = rhs + 1;
	rhs = row.find(",", lhs);
	std::string student_DP = row.substr(lhs, rhs - lhs);
	//determine degree program using string values.
	DegreeProgram studentDP;
	if(student_DP == "SECURITY"){
		studentDP = SECURITY;
	} else if(student_DP == "NETWORK"){
		studentDP = NETWORK;
	} else {
		studentDP = SOFTWARE;
	}
	
	int days_to_complete[3] = {daysInCourse1, daysInCourse2, daysInCourse3}; // add parsed days to complete to array.
	//creates student object using the above defined variables.
	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, studentDP);

};


/* 
E.  Create a Roster class (roster.cpp) by doing the following:
1.  Create an array of pointers, classRosterArray, to hold the data provided in the ???studentData Table.???
2.  Create a student object for each student in the data table and populate classRosterArray.
a.  Parse each set of data identified in the ???studentData Table.???
b.  Add each student object to classRosterArray.
3.  Define the following functions:
a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error message indicating that the student was not found.
c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.
d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student???s average number of days in the three courses. The student is identified by the studentID parameter.
e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
 
Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
 
f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
*/
