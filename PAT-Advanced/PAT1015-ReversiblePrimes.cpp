// PAT1015-ReversiblePrimes.cpp
// Ad
// Init: 19Apr05

/* -----------------------------------------------------------------------------

1015 Reversible Primes （20 分)

A reversible prime in any number system is a prime whose "reverse" in that number system is also a prime. 
For example in the decimal system 73 is a reversible prime because its reverse 37 is also a prime.

Now given any two positive integers N (<10^5) and D (1<D≤10), you are supposed to tell if N is a reversible prime with radix D.

### Input Specification:

The input file consists of several test cases. 
Each case occupies a line which contains two integers N and D. 
The input is finished by a negative N.

### Output Specification:

For each test case, print in one line Yes if N is a reversible prime with radix D, or No if not.

----------------------------------------
Sample Input:
73 10
23 2
23 10
-2
Sample Output:
Yes
Yes
No
----------------------------------------

----------------------------------------------------------------------------- */

#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> inputNums(void);
bool isPrime(int num);
int getReverse(int num, int radix);

// Main ------------------------------------------------------------------------

// Score: 20/20.
// Runtime: 4 ms.
// Spent time: 60 min.

int main()
{
    vector<pair<int, int>> input = inputNums();

    vector<bool> output;
    for (auto &p : input)
        output.push_back(
            (isPrime(p.first) && isPrime(getReverse(p.first, p.second)))
                ? true
                : false);

    for (auto b : output)
        cout << (b ? "Yes" : "No") << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

vector<pair<int, int>> inputNums(void)
{
    vector<pair<int, int>> ret;
    int N = 0, D = 0;
    while (true)
    {
        cin >> N;
        if (N < 0)
            break;
        cin >> D;
        ret.push_back({N, D});
    }

    return ret;
}

bool isPrime(int num)
{
    if (num == 1)
        return false;

    bool isPrime = true;
    for (int i = 2; i < num; ++i)
        if (num % i == 0)
        {
            isPrime = false;
            break;
        }

    return isPrime;
}

int getReverse(int num, int radix)
{
    int reversedRadix = 0;
    while (num)
    {
        reversedRadix = reversedRadix * 10 + num % radix;
        num /= radix;
    }

    int reversed = 0;
    for (int i = 0; reversedRadix; ++i)
    {
        reversed += reversedRadix % 10 * pow(radix, i);
        reversedRadix /= 10;
    }

    return reversed;
}
