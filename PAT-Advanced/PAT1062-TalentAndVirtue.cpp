// PAT1062-TalentAndVirtue.cpp
// Ad
// Init: 19Aug31

// Score: OSK/25
// Time: 30'
// Runtime: 293 ms

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class -----------------------------------------------------------------------

struct Person
{
    string id;
    int virtue;
    int talent;

    bool operator<(const Person &rhs) const
    {
        if (virtue + talent != rhs.virtue + rhs.talent)
            return virtue + talent > rhs.virtue + rhs.talent;
        else if (virtue != rhs.virtue)
            return virtue > rhs.virtue;
        else
            return id < rhs.id;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    int numPeople = 0, lowerBound = 0, higherLine = 0;
    cin >> numPeople >> lowerBound >> higherLine;

    vector<Person> sages, noblemen, foolMen, smallMen;
    for (int i = 0; i < numPeople; ++i)
    {
        string id;
        int virtue = 0, talent = 0;
        cin >> id >> virtue >> talent;

        if (virtue < lowerBound || talent < lowerBound)
            continue;
        else if (virtue >= higherLine && talent >= higherLine)
            sages.push_back({id, virtue, talent});
        else if (virtue >= higherLine)
            noblemen.push_back({id, virtue, talent});
        else if (talent < higherLine && virtue >= talent)
            foolMen.push_back({id, virtue, talent});
        else
            smallMen.push_back({id, virtue, talent});
    }

    sort(sages.begin(), sages.end());
    sort(noblemen.begin(), noblemen.end());
    sort(foolMen.begin(), foolMen.end());
    sort(smallMen.begin(), smallMen.end());

    cout << sages.size() + noblemen.size() + foolMen.size() + smallMen.size() << endl;
    for (auto s : sages)
        cout << s.id << ' ' << s.virtue << ' ' << s.talent << endl;
    for (auto n : noblemen)
        cout << n.id << ' ' << n.virtue << ' ' << n.talent << endl;
    for (auto f : foolMen)
        cout << f.id << ' ' << f.virtue << ' ' << f.talent << endl;
    for (auto s : smallMen)
        cout << s.id << ' ' << s.virtue << ' ' << s.talent << endl;

    system("pause");
    return 0;
}
