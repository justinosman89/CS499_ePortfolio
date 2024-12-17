Courses.cpp

#include "Courses.h"

using namespace std;

//default constructor that initializes courseNum and courseName to empty strings
Courses::Courses() : courseNum(""), courseName("") {}

//constructor with parameters courseNum and courseName
Courses::Courses(const string& number, const string& name) {
	courseNum = number;
	courseName = name;
}

//function to add prereq to the prerequisites vector
void Courses::addPrereq(const string& prerequisite) {
	prerequisites.push_back(prerequisite);
}
