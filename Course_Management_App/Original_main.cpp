main.cpp

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <fstream>
#include "Courses.h"

using namespace std;

//unordered map to store course info
unordered_map<string, Courses> hashtable;

//Function created to load data from the given file into the hashtable
void openReadCheckFile() {
	string filename;
	//ask user for the file they wish to load data from
	cout << "Enter the name of the file you wish to load data from (example CourseInformation.txt) :" << endl;;
	cin >> filename;
	//open the given file
	ifstream file(filename);
	//if file can't be opened output error message to user
	if (!file.is_open()) {
		cout << "\nFile not found: " << filename << endl;
		return;
	}

	string line;

	while (getline(file, line)) {
		vector<string> tokens;
		string token;
		istringstream tokenStream(line);
		//break the line from file into tokens using','
		while (getline(tokenStream, token, ',')) {
			tokens.push_back(token);
		}
		//if statement to check that the line has at the least course num and name
		if (tokens.size() < 2) {
			cout << "\nError: Invalid format!" << line << endl;
			continue;
		}
		//first token in line will be the course num and the second will be the name
		string courseNum = tokens[0];
		string courseName = tokens[1];
		
		//if course num isn't already in the hash table then create new course
		if (hashtable.find(courseNum) == hashtable.end()) {
			//create new course with prereq list that's empty
			Courses newCourses(courseNum, courseName);
			hashtable[courseNum] = newCourses;
		}
		//loop through tokens vector, starting at index 2 to get prereqs for course
		for (size_t i = 2; i < tokens.size(); ++i) {
			//get a prereq as a string from the vector
			string prerequisite = tokens[i];
			//get reference (from hashtable) to Course object that goes with courseNum
			Courses& prereqCourse = hashtable[courseNum];
			//call add prereq to add prereq to the list
			prereqCourse.addPrereq(prerequisite);
		}
	}
	//close file
	cout << "\nFile loaded successfully\n";
	file.close();
}

	//Function created to print course info
void printCourseInfo(string courseNum) {
	//if course num is not in hash table, output error message to user
	if (hashtable.find(courseNum) == hashtable.end()) {
		cout << "\nCourse cannot be found: " << courseNum << endl;
	}
	
	else {
		//get course object that goes with the course num
		Courses course = hashtable[courseNum];
		//output course number and name
		cout << "\nCourse Number: " << course.courseNum << endl;
		cout << "Course Name: " << course.courseName << endl;
		//check the course for any prereqs
		if (!course.prerequisites.empty()) {
			cout << "Prerequisites: ";
			//iterate the list of prereqs and the output them
			for (const string& prereq : course.prerequisites) {
				cout << prereq << " ";
			}
			cout << endl;
		}
	}
}

//function created to sort and print course alphabetically
void printCourseListAlpha() {
	//create vector for course numbers
	vector<string> courseNums;
	//iterate through hash table and add course nums to list
	for (const auto& pair : hashtable) {
		courseNums.push_back(pair.first);
	}
	cout << "---------------- COURSE LIST ---------------" << endl;
	//alphabetically sort courses
	sort(courseNums.begin(), courseNums.end());
	//output the sorted list of courses
	for (const string& courseNum : courseNums) {
		Courses course = hashtable[courseNum];
		cout << course.courseNum << " - " << course.courseName << endl;
	}
}

//function created to display the menu to user
void menu() {
	string courseNum;
	//while loop that displays menu options to the user
	while (true) {
		cout << "\nMenu Options:" << endl;
		cout << "1. Load Data File : Must Start Here To Load File" << endl;
		cout << "2. Print Course List" << endl;
		cout << "3. Print Course" << endl;
		cout << "4. Exit\n" << endl;
		int choice;
		//get users choice
		cin >> choice;
		
		switch (choice) {
			//when user chooses option 1, call function to load and read file
			case 1:
				openReadCheckFile();
				break;
			//if user chooses option 2, call function to print course alpabetically
			case 2:
				printCourseListAlpha();
				break;
			//if user chooses option 3, ask for course num then call function to print info for that course
			case 3:
				cout << "Enter course number: ";
				cin >> courseNum;
				printCourseInfo(courseNum);
				break;
			//if user chooses option 4, exit program
			case 4: 
				cout << "Exiting program....";
				return;
			//if user does not choose a valid option(#1-4) output error message and try again
			default:
				cout << choice << " is not a valid option. Please select a valid option." << endl;
		}
	}
}
//main	
int main() {
	menu();
	return 0;
}
