// LC367-ValidPerfectSquare.cpp
// Ad
// Init: 19Sep21

// Difficulty: Easy
// Status: Accepted
// Time: 19'
// Runtime: 100%
// Memory: 71%

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    bool isPerfectSquare(int num)
    {
        int left = 1, right = num;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            long square = (long)mid * mid;
            if (square == num)
                return true;
            else if (square < num)
                left = mid + 1;
            else
                right = mid;
        }

        if ((long)left * left == num)
            return true;
        else
            return false;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<int> nums{16, 14, 1, 2, 3, 4, 5, 81, 10000, 1073741824};

    for (auto n : nums)
        cout << sol.isPerfectSquare(n) << endl;

    system("pause");
    return 0;
}
