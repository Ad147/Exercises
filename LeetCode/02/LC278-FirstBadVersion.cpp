// LC278-FirstBadVersion.cpp
// Ad
// Init: 19Sep13

// Difficulty: Easy
// Status: Accepted
// Time: 31'
// Runtime: 100%
// Memory: 27%

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

// int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int left = 1, right = n;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (!isBadVersion(mid))
                left = mid + 1;
            else
                right = mid;
        }

        return left;
    }
};
