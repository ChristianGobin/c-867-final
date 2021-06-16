//
//  student.hpp
//  c867_second_attempt
//
//  Created by Christian Gobin on 6/15/21.
//

#ifndef student_hpp
#define student_hpp
#include <stdio.h>
#include <string>
//
#include "degree.h"
using namespace std;
class Student{
    
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
    //D1.
    //D2-C: Members can only be accessed/manipulated through methods..properties are kept private.
    string student_ID;
    string first_name;
    string last_name;
    string email_address;
    int age;
    int* days_to_complete;
    DegreeProgram student_DP;
};
#endif /* student_hpp */
