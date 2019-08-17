// PAT1049-CountingOnes.cpp
// Ad
// Init: 19Aug17

// Score: 30/30
// Time: 63'
// Runtime: 3 ms

#include <iostream>

using namespace std;

long countOnes(long input);

// Main ------------------------------------------------------------------------

int main()
{
    long input = 0;
    cin >> input;

    cout << countOnes(input);

    system("pause");
    return 0;
}

// Function --------------------------------------------------------------------

long countOnes(long input)
{
    long cnt = 0;

    if (input < 65536)
        for (int i = 1; i <= input; ++i)
        {
            long n = i;
            while (n != 0)
            {
                if (n % 10 == 1)
                    ++cnt;
                n /= 10;
            }
        }
    else
        for (int i = 1, j = 0; i <= input; i *= 10, ++j)
        {
            int digit = input / i % 10;

            if (digit > 1)
                cnt += i;
            else if (digit == 1)
                cnt += input % i + 1;

            cnt += digit * i / 10 * j;
        }

    return cnt;
}
