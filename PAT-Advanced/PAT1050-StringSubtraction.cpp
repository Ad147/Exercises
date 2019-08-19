// PAT1050-StringSubtraction.cpp
// Ad
// Init: 19Aug19

// Score: 20/20
// Time: 12'
// Runtime: 5 ms

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

string subtract(const string &s1, const string &s2);

// Main ------------------------------------------------------------------------

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    cout << subtract(s1, s2) << endl;

    // system("pause");
    return 0;
}

// Funtion ---------------------------------------------------------------------

string subtract(const string &s1, const string &s2)
{
    string ret;

    unordered_set<char> s2Chars;
    for (auto c : s2)
        s2Chars.insert(c);

    for (auto c : s1)
        if (s2Chars.find(c) == s2Chars.end())
            ret.push_back(c);

    return ret;
}
