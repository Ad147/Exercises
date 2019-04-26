// PAT1019-GeneralPalindromicNumber.cpp
// Ad
// Init: 19Apr09

// Score: 20/20 (One-Shot Kill).
// Spent time: 25 min.
// Runtime: 3 ms.

/* -----------------------------------------------------------------------------

1019 General Palindromic Number （20 分)

A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. 
For example, 1234321 is a palindromic number. 
All single digit numbers are palindromic numbers.

Although palindromic numbers are most often considered in the decimal system, the concept of palindromicity can be applied to the natural numbers in any numeral system. 
Consider a number N>0 in base b≥2, where it is written in standard notation with k+1 digits ai as ∑^k_i=0 (ai*bi). 
Here, as usual, 0≤ai<b for all i and ak is non-zero. 
Then N is palindromic if and only if ai=ajj_k-1 for all i. 
Zero is written 0 in any base and is also palindromic by definition.

Given any positive decimal integer N and a base b, you are supposed to tell if N is a palindromic number in base b.

### Input Specification:

Each input file contains one test case. 
Each case consists of two positive numbers N and b, where 0<N≤10^9 is the decimal number and 2≤b≤10^9 is the base. 
The numbers are separated by a space.

### Output Specification:

For each test case, first print in one line Yes if N is a palindromic number in base b, or No if not. 
Then in the next line, print N as the number in base b in the form "ak, a_k-1, ..., a0". 
Notice that there must be no extra space at the end of output.

----------------------------------------
Sample Input 1:
27 2
Sample Output 1:
Yes
1 1 0 1 1
Sample Input 2:
121 5
Sample Output 2:
No
4 4 1
----------------------------------------
鸣谢网友“CCPC拿不到牌不改名”修正数据！

----------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

vector<int> convert(unsigned long long num, const unsigned long long base);
bool isPalindromic(const vector<int> &digits);

// Main ------------------------------------------------------------------------

int main()
{
    unsigned long long num = 0, base = 0;
    cin >> num >> base;

    vector<int> digits = convert(num, base);

    cout << (isPalindromic(digits) ? "Yes" : "No") << endl;
    cout << digits.back();
    for (auto itr = digits.rbegin() + 1; itr != digits.rend(); ++itr)
        cout << ' ' << *itr;
    cout << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

vector<int> convert(unsigned long long num, const unsigned long long base)
{
    vector<int> digits;

    while (num)
    {
        digits.push_back(num % base);
        num /= base;
    }

    return digits;
}

bool isPalindromic(const vector<int> &digits)
{
    for (auto itr1 = digits.begin(), itr2 = digits.end() - 1; itr1 < itr2; ++itr1, --itr2)
        if (*itr1 != *itr2)
            return false;

    return true;
}
