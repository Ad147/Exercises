// PAT1048-FindCoins.cpp
// Ad
// Init: 19Aug16

// Score: 25/25
// Time: 60'
// Runtime: 40 ms

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

// Main ------------------------------------------------------------------------

int main()
{
    int numCoins = 0, price = 0;
    cin >> numCoins >> price;
    vector<int> coins;
    for (int i = 0; i < numCoins; ++i)
    {
        int val = 0;
        cin >> val;
        coins.push_back(val);
    }

    sort(coins.begin(), coins.end());
    auto itr0 = coins.cbegin(), itr1 = coins.cend() - 1;
    bool solutionFound = false;
    while (itr0 != itr1)
    {
        if (*itr0 + *itr1 == price)
        {
            solutionFound = true;
            break;
        }
        else if (*itr0 + *itr1 > price)
            itr1--;
        else
            itr0++;
    }

    if (solutionFound)
        cout << *itr0 << ' ' << *itr1 << endl;
    else
        cout << "No Solution" << endl;

    return 0;
}
