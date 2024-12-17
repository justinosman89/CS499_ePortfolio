Courses.h

#ifndef COURSE_H
#define COURSE_H


#include <string>
#include <vector>

using namespace std;

//Courses class definition 
class Courses {
public:
	//declare strings and vector to hold course info and prereqs
	string courseNum;
	string courseName;
	vector<string> prerequisites;

	//default constructor
	Courses();

	//constructor with num and name parameters 
	Courses(const string& number, const string& name); 

	//function to add a prerequisite 
	void addPrereq(const string& prerequisite);
};

#endif 
