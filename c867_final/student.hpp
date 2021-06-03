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

//D.
class Student{
public:
	//D2-d Constructor using all Params of student table:
	Student(std::string student_ID, std::string first_name, std::string last_name, std::string email_address, int age, int c1, int c2, int c3, DegreeProgram student_DP);
	
	~Student();
	
	//D2. Create getters, setters
	std::string get_student_ID();
	void set_student_ID(std::string new_ID);
	
	std::string get_first_name();
	void set_first_name(std::string new_first_name);
	
	std::string get_last_name();
	void set_last_name(std::string new_last_name);
	
	std::string get_email();
	void set_email(std::string new_email);
	
	DegreeProgram get_degree_program();
	void set_degree_program(DegreeProgram new_degree_program);
	
	int get_age();
	void set_age(int new_age);
	
	int get_days_to_complete(int course_index); //find courses using index -> days_to_complete[course_index]
	void set_days_to_complete(int c1, int c2, int c3); //courses 1,2,3;
	
	//D2-e Print function for specific student data.
	void print();
private:
	//D1. Properties of student class created
	//D2. Members Kept Private; Only accessable through Accessors + Mutators
	std::string student_ID, first_name, last_name, email_address;
	int age, days_to_complete[3];
	DegreeProgram student_DP;
};



#endif /* student_hpp */
