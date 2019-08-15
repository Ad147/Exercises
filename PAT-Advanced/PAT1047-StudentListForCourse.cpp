// PAT1047-StudentListForCourse.cpp
// Ad
// Init: 19Aug15

// Score: 21/25
// Time: 12'
// Runtime: 3 ms

#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

// Main ------------------------------------------------------------------------

int main()
{
    int numStudents = 0, numCourses = 0;
    cin >> numStudents >> numCourses;
    vector<set<string>> courses(numCourses);
    for (int i = 0; i < numStudents; ++i)
    {
        string name;
        int numRegistered = 0;
        cin >> name >> numRegistered;
        for (int j = 0; j < numRegistered; ++j)
        {
            int courseNumer = 0;
            cin >> courseNumer;
            courses[courseNumer - 1].insert(name);
        }
    }

    for (int i = 0; i < courses.size(); ++i)
    {
        cout << i + 1 << ' ' << courses[i].size() << endl;
        for (auto name : courses[i])
            cout << name << endl;
    }

    return 0;
}
