#include "Courses.h" // Include the header file to define the class

// Default constructor
// Initializes the course number and course name to empty strings
Courses::Courses() : courseNum(""), courseName("") {}

// Constructor with parameters for course number and name
// Takes the course number and name as input and initializes the object
Courses::Courses(const std::string& number, const std::string& name) {
    courseNum = number;  // Assign the course number
    courseName = name;   // Assign the course name
}

// Function to add a prerequisite
// Inserts the prerequisite into the set, ensuring no duplicates
void Courses::addPrereq(const std::string& prerequisite) {
    prerequisites.insert(prerequisite); // Efficiently adds only unique values
}
