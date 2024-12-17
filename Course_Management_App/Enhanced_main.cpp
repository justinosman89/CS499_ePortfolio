Main.cpp

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <fstream>
#include "Courses.h"
#include "FileHandler.h"

using namespace std;

//unordered map to store course info
unordered_map<string, Courses> hashtable;

//Function created to load data from the given file into the hashtable
// Function to prompt the user for a file name and load course data
void openReadCheckFile() {
	std::string filename;
	std::cout << "Enter the name of the file you wish to load data from: ";
	std::cin >> filename;

	try {
		if (!FileHandler::loadCoursesFromFile(filename, hashtable)) {
			throw std::runtime_error("Failed to load file. Please check the filename or format.");
		}
		std::cout << "File loaded successfully.\n";
	}
	catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
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

void menu() {
	std::string courseNum;
	while (true) {
		std::cout << "\nMenu Options:\n";
		std::cout << "1. Load Data File\n";
		std::cout << "2. Print Course List\n";
		std::cout << "3. Print Course\n";
		std::cout << "4. Exit\n";
		std::cout << "Enter your choice: ";

		int choice;
		if (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input. Please enter a number between 1 and 4.\n";
			continue;
		}

		switch (choice) {
		case 1:
			openReadCheckFile();
			break;
		case 2:
			printCourseListAlpha();
			break;
		case 3:
			std::cout << "Enter course number: ";
			std::cin >> courseNum;
			printCourseInfo(courseNum);
			break;
		case 4:
			std::cout << "Exiting program...\n";
			return;
		default:
			std::cout << "Invalid choice. Please select a valid option.\n";
		}
	}
}

//main	
int main() {
	menu();
	return 0;
}
