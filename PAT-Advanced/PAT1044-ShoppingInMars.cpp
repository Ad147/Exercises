// PAT1044-ShoppingInMars.cpp
// Ad
// Init: 19Aug12

// Score: 25/25
// Time: 53 min
// Runtime: 252 ms

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>> matchPayment(const vector<int> &diamonds, int price);

// Main ------------------------------------------------------------------------

int main()
{
    int numDiamonds = 0, price = 0;
    cin >> numDiamonds >> price;
    vector<int> diamonds;
    for (int i = 0; i < numDiamonds; ++i)
    {
        int val = 0;
        cin >> val;
        diamonds.push_back(val);
    }

    auto result = matchPayment(diamonds, price);

    for (auto v : result)
        cout << v.first << '-' << v.second << endl;

    return 0;
}

// Functions -------------------------------------------------------------------

vector<pair<int, int>> matchPayment(const vector<int> &diamonds, int price)
{
    vector<pair<int, int>> ret;
    if (diamonds.empty() || price <= 0)
        return ret;

    int sum = 0, minDiff = 65536;
    for (int i = 0, j = 0; j < diamonds.size();)
    {
        sum += diamonds[j];
        if (sum == price)
        {
            ret.push_back({i + 1, j + 1});
            sum -= diamonds[i];
            ++i;
            ++j;
        }
        else if (sum > price)
        {
            minDiff = min(sum - price, minDiff);
            sum -= diamonds[i] + diamonds[j];
            ++i;
        }
        else
            ++j;
    }

    if (ret.empty())
        return matchPayment(diamonds, price + minDiff);
    else
        return ret;
}
