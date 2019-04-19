// PAT1024-PalindromicNumber.cpp
// Ad
// Init: 19Apr19

// Score: 18/25.
// Runtime: 4 ms.
// Spent time: 30 min.

/* -----------------------------------------------------------------------------

1024 Palindromic Number （25 分)

A number that will be the same when it is written forwards or backwards is known as a Palindromic Number. 
For example, 1234321 is a palindromic number. 
All single digit numbers are palindromic numbers.

Non-palindromic numbers can be paired with palindromic ones via a series of operations. 
First, the non-palindromic number is reversed and the result is added to the original number. 
If the result is not a palindromic number, this is repeated until it gives a palindromic number. 
For example, if we start from 67, we can obtain a palindromic number in 2 steps: 67 + 76 = 143, and 143 + 341 = 484.

Given any positive integer N, you are supposed to find its paired palindromic number and the number of steps taken to find it.

### Input Specification:

Each input file contains one test case. 
Each case consists of two positive numbers N and K, where N (≤10^10) is the initial numer and K (≤100) is the maximum number of steps. 
The numbers are separated by a space.

### Output Specification:

For each test case, output two numbers, one in each line. 
The first number is the paired palindromic number of N, and the second number is the number of steps taken to find the palindromic number. 
If the palindromic number is not found after K steps, just output the number obtained at the Kth step and K instead.

----------------------------------------
Sample Input 1:
67 3
Sample Output 1:
484
2
Sample Input 2:
69 3
Sample Output 2:
1353
3
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <string>

using namespace std;

int makePalindromic(int maxSteps, size_t &num);
bool isPalindromic(size_t num);
size_t reverse(size_t num);

// Main ------------------------------------------------------------------------

int main()
{
    size_t num = 0;
    int maxSteps = 0;
    cin >> num >> maxSteps;

    int cnt = makePalindromic(maxSteps, num);

    cout << num << endl
         << cnt << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

int makePalindromic(int maxSteps, size_t &num)
{
    int cnt = 0;

    for (; cnt < maxSteps; ++cnt)
        if (isPalindromic(num))
            break;
        else
            num = num + reverse(num);

    return cnt;
}

bool isPalindromic(size_t num)
{
    string str = to_string(num);
    for (int i = 0, j = str.size() - 1; i < j; ++i, --j)
        if (str[i] != str[j])
            return false;

    return true;
}

size_t reverse(size_t num)
{
    size_t ret = 0;

    while (num != 0)
    {
        ret = ret * 10 + num % 10;
        num /= 10;
    }
cerr << "rev: " << ret << endl;
    return ret;
}
