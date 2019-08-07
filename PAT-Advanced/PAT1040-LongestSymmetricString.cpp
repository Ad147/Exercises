// PAT1040-LongestSymmetricString.cpp
// Ad
// Init: 19Aug07

// Score: 8/25
// Time: 45 min
// Runtime: 4 ms

#include <iostream>
#include <string>

using namespace std;

int getLongestSymmetric(const string &str);
int getCurrentSymmetric(const string &str, string::const_iterator itr1, string::const_iterator itr2, int currentLength);

// Main ------------------------------------------------------------------------

int main()
{
    string str;
    cin >> str;
    cout << getLongestSymmetric(str) << endl;

    return 0;
}

// Function --------------------------------------------------------------------

int getLongestSymmetric(const string &str)
{
    if (str.empty())
        return 0;
    if (str.size() == 1)
        return 1;

    int longest = 1;

    auto leftItr = str.cbegin(), midItr = leftItr + 1, rightItr = midItr + 1;
    while (rightItr != str.cend())
    {
        int symmetric1 = 0, symmetric2 = 0;
        if (*leftItr == *midItr)
            symmetric1 = getCurrentSymmetric(str, leftItr, midItr, 2);
        if (*leftItr == *rightItr)
            symmetric2 = getCurrentSymmetric(str, leftItr, rightItr, 3);

        longest = symmetric1 > longest ? symmetric1 : longest;
        longest = symmetric2 > longest ? symmetric2 : longest;

        leftItr++;
        midItr++;
        rightItr++;
    }

    if (*leftItr == *midItr)
        longest = 2 > longest ? 2 : longest;

    return longest;
}

int getCurrentSymmetric(const string &str, string::const_iterator itr1, string::const_iterator itr2, int currentLength)
{
    while (itr1 != str.cbegin() && itr2 != str.cend() - 1)
        if (*(--itr1) == *(++itr2))
            currentLength += 2;

    return currentLength;
}
