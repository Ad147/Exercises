// LC069-SqrtX.cpp
// Ad
// Init: 19Sep10

// Difficulty: Easy
// Status: Accepted
// Time: 21' + 17'
// Runtime: 100%
// Memory: 68%

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;

        int left = 0, right = x;
        while (left <= right)
        {
            size_t mid = left + (right - left) / 2;
            if (mid * mid <= x && (mid + 1) * (mid + 1) > x)
                return mid;
            else if (mid * mid > x)
                right = mid - 1;
            else
                left = mid + 1;
        }

        throw exception();
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<int> inputs{4, 8, 2147395599};

    for (auto i : inputs)
        cout << sol.mySqrt(i) << endl;

    system("pause");
    return 0;
}
