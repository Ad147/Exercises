// PAT1039-CourseListForStudent.cpp
// Ad
// Init: 19Aug06

// Score: OSK/25
// Time: 25 min
// Runtime: 431 ms

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

map<string, set<int>> inputData(int numCourses);

// Main ------------------------------------------------------------------------

int main()
{
    int numStudents = 0, numCourses = 0;
    cin >> numStudents >> numCourses;
    map<string, set<int>> data = inputData(numCourses);

    vector<string> names;
    for (int i = 0; i < numStudents; ++i)
    {
        string name;
        cin >> name;
        names.push_back(name);
    }

    for (auto name : names)
    {
        cout << name << ' ' << data[name].size();
        for (auto course : data[name])
            cout << ' ' << course;
        cout << endl;
    }

    return 0;
}

// Functions -------------------------------------------------------------------

map<string, set<int>> inputData(int numCourses)
{
    map<string, set<int>> ret;

    for (int i = 0; i < numCourses; ++i)
    {
        int courseIndex = 0, registeredStudents = 0;
        cin >> courseIndex >> registeredStudents;

        for (int j = 0; j < registeredStudents; ++j)
        {
            string name;
            cin >> name;
            ret[name].insert(courseIndex);
        }
    }

    return ret;
}
