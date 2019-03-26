// PAT1001-A+BFormat.cpp
// Ad
// Init: 19Mar25

/* -----------------------------------------------------------------------------

1001 A+B Format （20 分)

Calculate a+b and output the sum in standard format -- that is, the digits must be separated into groups of three by commas (unless there are less than four digits).

### Input Specification:

Each input file contains one test case. 
Each case contains a pair of integers a and b where −10^​6​​ ≤ a,b ≤10^​6. 
The numbers are separated by a space.

### Output Specification:

For each test case, you should output the sum of a and b in one line. 
The sum must be written in the standard format.

----------------------------------------
Sample Input:
-1000000 9
Sample Output:
-999,991
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <string>

using namespace std;

void printSum(int i, int j);
string format(int num);

// Main ------------------------------------------------------------------------

// Score: 20/20.
// Runtime: 3 ms.
// Spent time: 50 min.

int main()
{
    int i{0}, j{0};
    while (cin >> i >> j)
        printSum(i, j);

    return 0;
}

// Functions -------------------------------------------------------------------

void printSum(int i, int j)
{
    int sum = i + j;
    int million{0}, thousand{0};
    if ((million = sum / 1000000) != 0)
    {
        thousand = sum < 0 ? -sum / 1000 % 1000 : sum / 1000 % 1000;
        sum = sum < 0 ? -sum % 1000 : sum % 1000;
        cout << million << ',' << format(thousand) << ',' << format(sum) << endl;
    }
    else if ((thousand = sum / 1000) != 0)
    {
        sum = sum < 0 ? -sum % 1000 : sum % 1000;
        cout << thousand << ',' << format(sum) << endl;
    }
    else
        cout << sum << endl;
}

string format(int num)
{
    string ret = to_string(num);
    if (num < 100)
        ret = '0' + ret;
    if (num < 10)
        ret = '0' + ret;
    return std::move(ret);
}
