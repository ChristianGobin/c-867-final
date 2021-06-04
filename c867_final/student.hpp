//
//  student.hpp
//  c867
//
//  Created by Christian Gobin on 5/13/21.
//
#ifndef student_hpp
#define student_hpp
#include <string>
#include "degree.h"
using namespace std;

const int max_courses {3};
//D1: Create the class Student in the files student.h and student.cpp
class Student{
public:
	//D2-D: constructor using all of the input parameters provided in the table
	Student(string student_ID, string first_name, string last_name, string email_address, int age, int daysToComplete[], DegreeProgram student_DP);
	
	~Student();
	
	//D2-A: an accessor (i.e., getter) for each instance variable from part D1
	string get_student_ID();
	string get_first_name();
	string get_last_name();
	string get_email();
	int get_age();
	DegreeProgram get_degree_program();
	void set_student_ID(string new_ID);
	int * get_days_to_complete();
	

	//D2-B: a mutator (i.e., setter) for each instance variable from part D1
	void set_first_name(string new_first_name);
	void set_last_name(string new_last_name);
	void set_email(string new_email);
	void set_degree_program(DegreeProgram new_degree_program);
	void set_age(int new_age);
	void set_days_to_complete(int daysToComplete[]);
	
	//D2-E: print() to print specific student data
	void print();
private:
	//D1. & D2-C: Members can only be manipulated / accessed through accessors and mutators.
	string student_ID;
	string first_name;
	string last_name;
	string email_address;
	int age;
	int * days_to_complete;
	DegreeProgram student_DP;
};



#endif /* student_hpp */
/*D.  For the Student class, do the following:
1.  Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
•  student ID
•  first name
•   last name
•  email address
•  age
•  array of number of days to complete each course
•  degree program
2.  Create each of the following functions in the Student class:
a.  an accessor (i.e., getter) for each instance variable from part D1
b.  a mutator (i.e., setter) for each instance variable from part D1
c.  All external access and changes to any instance variables of the Student class must be done using accessor and mutator functions.
d.  constructor using all of the input parameters provided in the table
e.  print() to print specific student data
*/