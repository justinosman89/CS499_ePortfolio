#include <set>
#include <string>

class Courses {
public:
    std::string courseNum;
    std::string courseName;
    std::set<std::string> prerequisites;

    Courses();
    Courses(const std::string& number, const std::string& name);
    void addPrereq(const std::string& prerequisite);
};

void Courses::addPrereq(const std::string& prerequisite) {
    prerequisites.insert(prerequisite);
}

