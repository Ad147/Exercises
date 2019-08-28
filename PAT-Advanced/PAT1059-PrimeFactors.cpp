// PAT1059-PrimeFactors.cpp
// Ad
// Init: 19Aug28

// Score: OSK/25
// Time: 21'
// Runtime: 4 ms

#include <iostream>
#include <map>

using namespace std;

map<long, int> getPrimeFactors(long number);

// Main ------------------------------------------------------------------------

int main()
{
    long number = 0;
    cin >> number;

    map<long, int> factors = getPrimeFactors(number);

    auto itr = factors.cbegin();
    cout << number << '=' << itr->first;
    if (itr->second != 1)
        cout << '^' << itr->second;
    for (++itr; itr != factors.cend(); ++itr)
    {
        cout << '*' << itr->first;
        if (itr->second != 1)
            cout << '^' << itr->second;
    }
    cout << endl;

    system("pause");
    return 0;
}

// Function --------------------------------------------------------------------

map<long, int> getPrimeFactors(long number)
{
    map<long, int> ret;
    if (number == 1)
    {
        ret.insert({1, 1});
        return ret;
    }

    for (long i = 2; i <= number; ++i)
    {
        while (number % i == 0)
        {
            ++ret[i];
            number /= i;
        }
    }

    return ret;
}
