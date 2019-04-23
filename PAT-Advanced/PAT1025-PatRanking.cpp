// PAT1025-PatRanking.cpp
// Ad
// Init: 19Apr23

// Score: 22/25.
// Runtime: 136 ms.
// Spent time: 45 min.

/* -----------------------------------------------------------------------------

1025 PAT Ranking （25 分)

Programming Ability Test (PAT) is organized by the College of Computer Science and Technology of Zhejiang University. 
Each test is supposed to run simultaneously in several places, and the ranklists will be merged immediately after the test. 
Now it is your job to write a program to correctly merge all the ranklists and generate the final rank.

### Input Specification:

Each input file contains one test case. 
For each case, the first line contains a positive number N (≤100), the number of test locations. 
Then N ranklists follow, each starts with a line containing a positive integer K (≤300), the number of testees, and then K lines containing the registration number (a 13-digit number) and the total score of each testee. 
All the numbers in a line are separated by a space.

### Output Specification:

For each test case, first print in one line the total number of testees. 
Then print the final ranklist in the following format:

`registration_number final_rank location_number local_rank`

The locations are numbered from 1 to N. 
The output must be sorted in nondecreasing order of the final ranks. 
The testees with the same score must have the same rank, and the output must be sorted in nondecreasing order of their registration numbers.

----------------------------------------
Sample Input:
2
5
1234567890001 95
1234567890005 100
1234567890003 95
1234567890002 77
1234567890004 85
4
1234567890013 65
1234567890011 25
1234567890014 100
1234567890012 85
Sample Output:
9
1234567890005 1 1 1
1234567890014 1 2 1
1234567890001 3 1 2
1234567890003 3 1 2
1234567890004 5 1 4
1234567890012 5 2 2
1234567890002 7 1 5
1234567890013 8 2 3
1234567890011 9 2 4
----------------------------------------

----------------------------------------------------------------------------- */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Testee;
vector<Testee> inputTestees(int location);
void sortAndNumber(vector<Testee> &testees);
vector<Testee> mergeAndNumber(const vector<vector<Testee>> &testees);

// Class -----------------------------------------------------------------------

struct Testee
{
    size_t id;
    int score;
    int location;
    int localRank;
    int rank;

    Testee(size_t i, int s, int l) : id{i}, score{s}, location{l}, localRank{0}, rank{0} {}

    bool operator<(const Testee &rhs) { return score == rhs.score ? (id < rhs.id) : (score > rhs.score); }
};

// Main ------------------------------------------------------------------------

int main()
{
    int numLocations = 0;
    cin >> numLocations;
    vector<vector<Testee>> testees(numLocations);

    for (int i = 0; i < numLocations; ++i)
    {
        testees[i] = inputTestees(i + 1);
        sortAndNumber(testees[i]);
    }

    auto ranklist = mergeAndNumber(testees);

    cout << ranklist.size() << endl;
    for (auto &t : ranklist)
        cout << t.id << ' ' << t.rank << ' ' << t.location << ' ' << t.localRank << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

vector<Testee> inputTestees(int location)
{
    vector<Testee> ret;
    int numTestees = 0;
    cin >> numTestees;

    for (int i = 0; i < numTestees; ++i)
    {
        size_t id = 0;
        int score = 0;
        cin >> id >> score;
        ret.push_back(Testee{id, score, location});
    }

    return ret;
}

void sortAndNumber(vector<Testee> &testees)
{
    sort(testees.begin(), testees.end());

    for (int i = 0; i < testees.size(); ++i)
        testees[i].localRank = i + 1;
    for (int i = 1; i < testees.size(); ++i)
        if (testees[i].score == testees[i - 1].score)
            testees[i].localRank = testees[i - 1].localRank;
}

vector<Testee> mergeAndNumber(const vector<vector<Testee>> &testees)
{
    vector<Testee> ret;
    for (auto &l : testees)
        for (auto &t : l)
            ret.push_back(t);

    sort(ret.begin(), ret.end());

    for (int i = 0; i < ret.size(); ++i)
        ret[i].rank = i + 1;
    for (int i = 1; i < ret.size(); ++i)
        if (ret[i].score == ret[i - 1].score)
            ret[i].rank = ret[i - 1].rank;

    return ret;
}
