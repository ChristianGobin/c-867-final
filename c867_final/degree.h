//
//  degree.h
//  c867
//
//  Created by Christian Gobin on 5/13/21.
//
#ifndef degree_h
#define degree_h
#include <string>
//C. Enumerated data type "DegreeProgram" contains : SECURITY, NETWORK, SOFTWARE

enum DegreeProgram 
{
	DEFAULT, //used for default constructor in student class.
	SECURITY,
	NETWORK,
	SOFTWARE
};
//Parallel Array of corresponding string vals
static const std::string degreeStrings[] = {"DEFAULT", "SECURITY", "NETWORK", "SOFTWARE"};

#endif /* degree_h */
