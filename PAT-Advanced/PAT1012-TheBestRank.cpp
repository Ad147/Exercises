// PAT1012-TheBestRank.cpp
// Ad
// Init: 19Apr03

// Score: 25/25.
// Spent time: 120 min.
// Runtime: 43 ms.

/* -----------------------------------------------------------------------------

1012 The Best Rank （25 分)

To evaluate the performance of our first year CS majored students, we consider their grades of three courses only:

- C - C Programming Language, 
- M - Mathematics (Calculus or Linear Algrbra), and 
- E - English. 

At the mean time, we encourage students by emphasizing on their best ranks 
-- that is, among the four ranks with respect to the three courses and the average grade, we print the best rank for each student.

For example, The grades of C, M, E and A - Average of 4 students are given as the following:
----------------------------------------
StudentID  C  M  E  A
310101     98 85 88 90
310102     70 95 88 84
310103     82 87 94 88
310104     91 91 91 91
----------------------------------------

Then the best ranks for all the students are No.1 since the 1st one has done the best in C Programming Language, while the 2nd one in Mathematics, the 3rd one in English, and the last one in average.

### Input Specification:

Each input file contains one test case. 
Each case starts with a line containing 2 numbers N and M (≤2000), which are the total number of students, and the number of students who would check their ranks, respectively. 
Then N lines follow, each contains a student ID which is a string of 6 digits, followed by the three integer grades (in the range of [0, 100]) of that student in the order of C, M and E. 
Then there are M lines, each containing a student ID.

### Output Specification:

For each of the M students, print in one line the best rank for him/her, and the symbol of the corresponding rank, separated by a space.

The priorities of the ranking methods are ordered as A > C > M > E. 
Hence if there are two or more ways for a student to obtain the same best rank, output the one with the highest priority.

If a student is not on the grading list, simply output N/A.

----------------------------------------
Sample Input:
5 6
310101 98 85 88
310102 70 95 88
310103 82 87 94
310104 91 91 91
310105 85 90 90
310101
310102
310103
310104
310105
999999
Sample Output:
1 C
1 M
1 E
1 A
3 A
N/A
----------------------------------------

----------------------------------------------------------------------------- */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student;
Student inputGrades();
void calcBestRank(vector<Student> &students);
string getBestRank(const string id, const vector<Student> &students);

// Class -----------------------------------------------------------------------

struct Student
{
    string id;
    int C;
    int M;
    int E;
    double A;
    int bestRank;
    string bestSubject;

    Student(string ID, int c, int m, int e)
        : id{ID}, C{c}, M{m}, E{e}, A{(c + m + e) / 3}, bestRank{2001}, bestSubject{""} {}
};

// Main ------------------------------------------------------------------------

int main()
{
    vector<Student> students;
    int N = 0, M = 0;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        students.push_back(inputGrades());

    calcBestRank(students);

    vector<string> checkStudents;
    for (int i = 0; i < M; ++i)
    {
        string id;
        cin >> id;
        checkStudents.push_back(id);
    }

    for (auto &s : checkStudents)
        cout << getBestRank(s, students) << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

Student inputGrades()
{
    string id;
    int C = 0, M = 0, E = 0;
    cin >> id >> C >> M >> E;
    return Student{id, C, M, E};
}

void calcBestRank(vector<Student> &students)
{
    // A -----------------------------------------------------------------------
    sort(students.begin(), students.end(),
         [](const Student &lhs, const Student &rhs) { return lhs.A > rhs.A; });
    if (students[0].bestRank != 1)
    {
        students[0].bestRank = 1;
        students[0].bestSubject = "A";
    }
    int prevRank = 1, currRank = 0;
    for (int i = 1; i < students.size(); ++i)
    {
        if (students[i].A == students[i - 1].A)
            currRank = prevRank;
        else
            currRank = i + 1;

        if (currRank < students[i].bestRank)
        {
            students[i].bestRank = currRank;
            students[i].bestSubject = "A";
        }

        prevRank = currRank;
    }

    // C -----------------------------------------------------------------------
    sort(students.begin(), students.end(),
         [](const Student &lhs, const Student &rhs) { return lhs.C > rhs.C; });
    if (students[0].bestRank != 1)
    {
        students[0].bestRank = 1;
        students[0].bestSubject = "C";
    }
    prevRank = 1;
    for (int i = 1; i < students.size(); ++i)
    {
        if (students[i].C == students[i - 1].C)
            currRank = prevRank;
        else
            currRank = i + 1;

        if (currRank < students[i].bestRank)
        {
            students[i].bestRank = currRank;
            students[i].bestSubject = "C";
        }

        prevRank = currRank;
    }

    // M -----------------------------------------------------------------------
    sort(students.begin(), students.end(),
         [](const Student &lhs, const Student &rhs) { return lhs.M > rhs.M; });
    if (students[0].bestRank != 1)
    {
        students[0].bestRank = 1;
        students[0].bestSubject = "M";
    }
    prevRank = 1;
    for (int i = 1; i < students.size(); ++i)
    {
        cerr << students[i].id << students[i].E << students[i].bestRank << students[i].bestSubject << endl;
        if (students[i].M == students[i - 1].M)
            currRank = prevRank;
        else
            currRank = i + 1;

        if (currRank < students[i].bestRank)
        {
            students[i].bestRank = currRank;
            students[i].bestSubject = "M";
        }

        prevRank = currRank;
    }

    // E -----------------------------------------------------------------------
    sort(students.begin(), students.end(),
         [](const Student &lhs, const Student &rhs) { return lhs.E > rhs.E; });
    if (students[0].bestRank != 1)
    {
        students[0].bestRank = 1;
        students[0].bestSubject = "E";
    }
    prevRank = 1;
    for (int i = 1; i < students.size(); ++i)
    {
        if (students[i].E == students[i - 1].E)
            currRank = prevRank;
        else
            currRank = i + 1;

        if (currRank < students[i].bestRank)
        {
            students[i].bestRank = currRank;
            students[i].bestSubject = "E";
        }

        prevRank = currRank;
    }
}

string getBestRank(const string id, const vector<Student> &students)
{
    for (auto &s : students)
        if (s.id == id)
            return to_string(s.bestRank) + " " + s.bestSubject;

    return "N/A";
}
