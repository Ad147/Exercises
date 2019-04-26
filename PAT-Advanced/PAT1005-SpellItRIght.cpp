// PAT1005-SpellItRight.cpp
// Ad
// Init: 19Mar28

// Score: 20/20.
// Spent time: 70 min.
// Runtime: 4 ms.

/* -----------------------------------------------------------------------------

1005 Spell It Right （20 分)

Given a non-negative integer N, your task is to compute the sum of all the digits of N, and output every digit of the sum in English.

### Input Specification:

Each input file contains one test case. Each case occupies one line which contains an N (≤10^​100).

### Output Specification:

For each test case, output in one line the digits of the sum in English words. 
There must be one space between two consecutive words, but no extra space at the end of a line.

----------------------------------------
Sample Input:
12345
Sample Output:
one five
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

static const vector<string> engDigits{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

int getSum();
void print(int sum);

// Main ------------------------------------------------------------------------

int main()
{
    print(getSum());

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

int getSum()
{
    int sum = 0;
    char c;
    while (cin >> c)
        sum += c - '0';

    return sum;
}

void print(int sum)
{
    vector<int> digits;
    do
    {
        digits.push_back(sum % 10);
        sum /= 10;
    } while (sum);

    cout << engDigits[digits.back()];
    for (auto itr = digits.rbegin() + 1; itr != digits.rend(); ++itr)
        cout << ' ' << engDigits[*itr];
    cout << endl;
}
