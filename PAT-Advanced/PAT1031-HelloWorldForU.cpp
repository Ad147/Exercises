// PAT1031-HelloWorldForU.cpp
// Ad
// Init: 19May21

// Score: 20/20
// Spent time: 17 min
// Runtime: 4 ms

/* -----------------------------------------------------------------------------

1031 Hello World for U (20 分)

Given any string of N (≥5) characters, you are asked to form the characters into the shape of U. 
For example, helloworld can be printed as:
----------------------------------------
h  d
e  l
l  r
lowo
----------------------------------------

That is, the characters must be printed in the original order, starting top-down from the left vertical line with n1 characters, then left to right along the bottom line with n2 characters, and finally bottom-up along the vertical line with n3 characters. And more, we would like U to be as squared as possible -- that is, it must be satisfied that n1=n3=max{k|k≤n2 for all 3≤n2≤N} with n1+n2+n3−2=N.

### Input Specification:

Each input file contains one test case. 
Each case contains one string with no less than 5 and no more than 80 characters in a line. 
The string contains no white space.

### Output Specification:

For each test case, print the input string in the shape of U as specified in the description.

----------------------------------------
Sample Input:
helloworld!
Sample Output:
h   !
e   d
l   l
lowor
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <string>

using namespace std;

void printU(const string &str, int n1, int n2);

// Main ------------------------------------------------------------------------

int main()
{
    string str;
    cin >> str;
    int n1 = (str.size() + 2) / 3;
    int n2 = n1 + (str.size() + 2) % 3;

    printU(str, n1, n2);

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

void printU(const string &str, int n1, int n2)
{
    auto itr1 = str.begin();
    auto itr2 = str.end() - 1;

    for (int i = 0; i < n1 - 1; ++i)
    {
        cout << *itr1++;
        for (int j = 0; j < n2 - 2; ++j)
            cout << ' ';
        cout << *itr2-- << endl;
    }

    for (int i = 0; i < n2; ++i)
        cout << *itr1++;
    cout << endl;
}
