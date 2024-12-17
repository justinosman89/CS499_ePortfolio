Courses.h

#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <set>

// The Courses class stores course information and its prerequisites
class Courses {
public:
    std::string courseNum;   // Course number (e.g., CS101)
    std::string courseName;  // Course name (e.g., Intro to Programming)
    std::set<std::string> prerequisites; // Unique prerequisites

    // Default constructor
    Courses();

    // Constructor with course number and name
    Courses(const std::string& number, const std::string& name);

    // Function to add a prerequisite (ensures uniqueness)
    void addPrereq(const std::string& prerequisite);
};

#endif


