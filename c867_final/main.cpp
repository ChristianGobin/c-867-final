//
//  main.cpp
//  c867
//
//  Created by Christian Gobin on 5/7/21.
//

#include <iostream>
#include "./student.hpp"
#include "./roster.hpp"
#include "./degree.h"
using namespace std;

//F1 function declared so that compiler knows of function existence.
void print_data();

int main(){
    //A. Modify Student Data Table to include personal info.
    const string studentData[5] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Christian, Gobin,cgobin@wgu.edu,27, 20,30,40,SOFTWARE"
        
    };
    
    //F1 function called to print requested data to console.
    //Course Title, Language Used, Student ID, Name
    print_data();
    cout << endl;
    
    //F2,3 create class roster->populate using studentData table.
    Roster classRoster;
    for(string item: studentData){
        classRoster.body_parser(item);
    }
    //F4
    classRoster.printAll();
    cout << endl;
    classRoster.printInvalidEmails();
    cout << endl;
    
    classRoster.printAverageDaysInCourse("A1");
    classRoster.printAverageDaysInCourse("A2");
    classRoster.printAverageDaysInCourse("A3");
    classRoster.printAverageDaysInCourse("A4");
    classRoster.printAverageDaysInCourse("A5");
    cout << endl;
    
    classRoster.printByDegreeProgram(SOFTWARE);

    classRoster.remove("A3");

    classRoster.printAll();
    
    classRoster.remove("A3");
    
    //Implement destructor
    classRoster.~Roster();
    return 0;
}

//F1
void print_data(){
    cout << "Course title: C867 - Scripting and Programming Applications\n";
    cout << "Programming Language Used: C++\n";
    cout << "Student ID: 001532237\n";
    cout << "Name: Christian Gobin\n";
}

