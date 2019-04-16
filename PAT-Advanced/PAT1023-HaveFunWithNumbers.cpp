// PAT1023-HaveFunWithNumbers.cpp
// Ad
// Init: 19Apr16

// Score: 11/20.
// Runtime: 3 ms.
// Spent time: 30 min.

/* -----------------------------------------------------------------------------

1023 Have Fun with Numbers （20 分)

Notice that the number 123456789 is a 9-digit number consisting exactly the numbers from 1 to 9, with no duplication. 
Double it we will obtain 246913578, which happens to be another 9-digit number consisting exactly the numbers from 1 to 9, only in a different permutation. 
Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. 
That is, double a given number with k digits, you are to tell if the resulting number consists of only a permutation of the digits in the original number.

### Input Specification:

Each input contains one test case. Each case contains one positive integer with no more than 20 digits.

### Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number that consists of only a permutation of the digits in the original number, or "No" if not. 
Then in the next line, print the doubled number.

----------------------------------------
Sample Input:
1234567899
Sample Output:
Yes
2469135798
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <vector>

using namespace std;

vector<int> div(unsigned long long num);

// Main ------------------------------------------------------------------------

int main()
{
    unsigned long long n = 0;
    cin >> n;
    // if (n > 1e19)
    // throw exception();

    vector<int> nDigits = div(n);
    unsigned long long dn = n * 2;
    vector<int> dnDigits = div(dn);

    cout << (nDigits == dnDigits ? "Yes" : "No") << endl
         << dn << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

vector<int> div(unsigned long long num)
{
    vector<int> ret(10, 0);

    while (num != 0)
    {
        int d = num % 10;
        ++ret[d];
        num /= 10;
    }

    return ret;
}
