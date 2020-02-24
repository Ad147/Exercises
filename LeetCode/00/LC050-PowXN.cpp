// LC050-PowXN.cpp
// Ad
// Init: 19Sep19

// Difficulty: Medium
// Status: Accepted
// Time: 45'
// Runtime: 100%
// Memory: 51%

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    double myPow(double x, int n)
    {
        if (x == 0 || x == 1 || n == 1)
            return x;
        if (n == 0)
            return 1;

        if (n < 0)
            x = 1 / x;

        vector<int> remainders;
        while (n != 1 && n != -1)
        {
            remainders.push_back(n % 2);
            n /= 2;
        }

        double ret = x;
        for (auto itr = remainders.crbegin(); itr != remainders.crend(); ++itr)
        {
            ret *= ret;
            if (*itr)
                ret *= x;
        }

        return ret;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    double x = 8.84372;
    int n = -5;

    cout << sol.myPow(x, n) << endl;

    system("pause");
    return 0;
}
