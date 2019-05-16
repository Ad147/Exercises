// PAT1029-Median.cpp
// Ad
// Init: 19May16

// Score: 16/25
// Spent time: 20 min
// Runtime: 2 ms

/* -----------------------------------------------------------------------------

1029 Median (25 分)

Given an increasing sequence S of N integers, the median is the number at the middle position. 
For example, the median of S1 = { 11, 12, 13, 14 } is 12, and the median of S2 = { 9, 10, 15, 16, 17 } is 15. 
The median of two sequences is defined to be the median of the nondecreasing sequence which contains all the elements of both sequences. 
For example, the median of S1 and S2 is 13.

Given two increasing sequences of integers, you are asked to find their median.

### Input Specification:

Each input file contains one test case. Each case occupies 2 lines, each gives the information of a sequence. 
For each sequence, the first positive integer N (≤2×10^5) is the size of that sequence. 
Then N integers follow, separated by a space. 
It is guaranteed that all the integers are in the range of long int.

### Output Specification:

For each test case you should output the median of the two given sequences in a line.

----------------------------------------
Sample Input:
4 11 12 13 14
5 9 10 15 16 17
Sample Output:
13
----------------------------------------

----------------------------------------------------------------------------- */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<long> inputSequence(void);
long getMedian(vector<long> s1, vector<long> s2);

// Main ------------------------------------------------------------------------

int main()
{
    vector<long> s1 = inputSequence();
    vector<long> s2 = inputSequence();

    auto median = getMedian(s1, s2);

    cout << median << endl;

    system("pause");
    return 0;
}

// Funtions --------------------------------------------------------------------

vector<long> inputSequence(void)
{
    vector<long> ret;
    int num = 0, digit = 0;
    cin >> num;

    for (int i = 0; i < num; ++i)
    {
        cin >> digit;
        ret.push_back(digit);
    }

    return ret;
}

long getMedian(vector<long> s1, vector<long> s2)
{
    int mid = (s1.size() + s2.size() - 1) / 2;
    auto itr1 = s1.begin(), itr2 = s2.begin();
    for (int i = 0; i < mid; ++i)
        if (itr1 == s1.end())
            itr2++;
        else if (itr2 == s2.end())
            itr1++;
        else
            *itr1 < *itr2 ? itr1++ : itr2++;

    if (itr1 == s1.end())
        return *itr2;
    else if (itr2 == s2.end())
        return *itr1;
    else
        return *itr1 < *itr2 ? *itr1 : *itr2;
}
