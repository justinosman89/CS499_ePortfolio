#include "FileHandler.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Implementation of FileHandler::loadCoursesFromFile
bool FileHandler::loadCoursesFromFile(const std::string& filename, std::unordered_map<std::string, Courses>& hashtable) {
    // Attempt to open the file
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file - " << filename << std::endl;
        return false;
    }

    std::string line;
    // Read the file line by line
    while (getline(file, line)) {
        std::vector<std::string> tokens;
        std::istringstream tokenStream(line);
        std::string token;

        // Split the line by commas into tokens
        while (getline(tokenStream, token, ',')) {
            tokens.push_back(token);
        }

        // Validate line format: each line must have at least a course number and name
        if (tokens.size() < 2) {
            std::cerr << "Warning: Invalid line format - " << line << std::endl;
            continue;
        }

        // Extract course number and name
        std::string courseNum = tokens[0];
        std::string courseName = tokens[1];

        // Add the course to the hashtable if it doesn't exist
        if (hashtable.find(courseNum) == hashtable.end()) {
            hashtable[courseNum] = Courses(courseNum, courseName);
        }

        // Add prerequisites for the course
        for (size_t i = 2; i < tokens.size(); ++i) {
            hashtable[courseNum].addPrereq(tokens[i]);
        }
    }

    // Close the file after processing
    file.close();
    return true;
}


