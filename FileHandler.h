#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <string>
#include <unordered_map>
#include "Courses.h"

// Constants for error messages
const std::string FILE_NOT_FOUND_MSG = "Error: File not found - ";
const std::string INVALID_LINE_FORMAT_MSG = "Warning: Invalid line format - ";

// FileHandler class for file operations
class FileHandler {
public:
    static bool loadCoursesFromFile(const std::string& filename, std::unordered_map<std::string, Courses>& hashtable);
};

#endif



