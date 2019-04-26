// PAT1028-ListSorting.cpp
// Ad
// Init: 19Apr26

// Score: 25/25 (One-Shot Kill).
// Spent time: 28 min.
// Runtime: 302 ms.

/* -----------------------------------------------------------------------------

1028 List Sorting (25 分)

Excel can sort records according to any column. 
Now you are supposed to imitate this function.

### Input Specification:

Each input file contains one test case. 
For each case, the first line contains two integers N (≤10^5) and C, where N is the number of records and C is the column that you are supposed to sort the records with. 
Then N lines follow, each contains a record of a student. 
A student's record consists of his or her distinct ID (a 6-digit number), name (a string with no more than 8 characters without space), and grade (an integer between 0 and 100, inclusive).

### Output Specification:

For each test case, output the sorting result in N lines. 
That is, if C = 1 then the records must be sorted in increasing order according to ID's; 
if C = 2 then the records must be sorted in non-decreasing order according to names; 
and if C = 3 then the records must be sorted in non-decreasing order according to grades. 
If there are several students who have the same name or grade, they must be sorted according to their ID's in increasing order.

----------------------------------------
Sample Input 1:
3 1
000007 James 85
000010 Amy 90
000001 Zoe 60
Sample Output 1:
000001 Zoe 60
000007 James 85
000010 Amy 90
Sample Input 2:
4 2
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 98
Sample Output 2:
000010 Amy 90
000002 James 98
000007 James 85
000001 Zoe 60
Sample Input 3:
4 3
000007 James 85
000010 Amy 90
000001 Zoe 60
000002 James 90
Sample Output 3:
000001 Zoe 60
000007 James 85
000002 James 90
000010 Amy 90
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <string>
#include <set>

using namespace std;

struct Student;
set<Student> inputRecords(void);

// Class -----------------------------------------------------------------------

struct Student
{
    string id;
    string name;
    int grade;
    int sort;

    Student(string i, string n, int g, int s) : id{i}, name{n}, grade{g}, sort{s} {}

    bool operator<(const Student &rhs) const
    {
        if (sort == 1)
            return id < rhs.id;
        if (sort == 2)
            return (name != rhs.name) ? name < rhs.name : id < rhs.id;
        if (sort == 3)
            return (grade != rhs.grade) ? grade < rhs.grade : id < rhs.id;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    set<Student> students = inputRecords();

    for (auto &s : students)
        cout << s.id << ' ' << s.name << ' ' << s.grade << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

set<Student> inputRecords(void)
{
    set<Student> ret;
    int numRecords = 0, sortColumn = -1;
    cin >> numRecords >> sortColumn;

    for (int i = 0; i < numRecords; ++i)
    {
        string id, name;
        int grade = -1;
        cin >> id >> name >> grade;
        ret.insert(Student{id, name, grade, sortColumn});
    }

    return ret;
}
