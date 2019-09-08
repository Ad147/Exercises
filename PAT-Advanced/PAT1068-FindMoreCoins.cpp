// PAT1068-FindMoreCoins.cpp
// Ad
// Init: 19Sep08

// Score: 29/30
// Time: 35'
// Runtime: 6 ms

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool calcPayment(size_t price, const vector<unsigned> &coins, size_t idx, vector<unsigned> &solution);

// Main ------------------------------------------------------------------------

int main()
{
    size_t numCoins = 0, price = 0;
    cin >> numCoins >> price;
    vector<unsigned> coins;
    for (size_t i = 0; i < numCoins; ++i)
    {
        unsigned val = 0;
        cin >> val;
        coins.push_back(val);
    }

    sort(coins.begin(), coins.end());
    vector<unsigned> solution;
    if (calcPayment(price, coins, 0, solution))
    {
        cout << solution.front();
        for (size_t i = 1; i < solution.size(); ++i)
            cout << ' ' << solution[i];
        cout << endl;
    }
    else
        cout << "No Solution" << endl;
    
    return 0;
}

// Function --------------------------------------------------------------------

bool calcPayment(size_t price, const vector<unsigned> &coins, size_t idx, vector<unsigned> &solution)
{
    if (idx >= coins.size())
        return false;
    
    for (size_t i = idx; i < coins.size(); ++i)
    {
        solution.push_back(coins[i]);
        if (coins[i] == price)
            return true;
        else if (coins[i] > price)
        {
            solution.pop_back();
            return false;
        }

        if (calcPayment(price - coins[i], coins, i + 1, solution))
            return true;
        else
            solution.pop_back();
    }

    return false;
}

