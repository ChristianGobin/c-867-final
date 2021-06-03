//
//  roster.hpp
//  c867
//
//  Created by Christian Gobin on 5/13/21.
//

#ifndef roster_hpp
#define roster_hpp
#pragma once
#include <iostream>
#include <string>
#include "./student.hpp"
#include "./degree.h"



class Roster{
private:
	int roster_last_index = -1;
	const static int num_of_students = 5;
public:
	//Array of Pointers.
	Student * classRosterArray[num_of_students];
	Roster(); //ctor
	const static int pub_num_of_students = 5;
	
	//E2 body parser defined, function parses input and assigns values to student class.
	void body_parser(std::string row);
	
	
	//E3 A-F
	void add(
		std::string studentID, 
		std::string firstName, 
		std::string lastName, 
		std::string emailAddress, 
		int age, 
		int c1, int c2, int c3, //course 1, course2, course3
		DegreeProgram student_DP
	);
	
	void remove(std::string studentID);	
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram student_DP);
	~Roster(); //destructor
};






#endif /* roster_hpp */
