// LC162-FindPeakElement.cpp
// Ad
// Init: 19Sep14

// Difficulty: Medium
// Status: OSK
// Time: 19'
// Runtime: 100%
// Memory: 93%

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        if (nums.empty())
            return -1;
        // if (nums.size() == 1)
        //     return 0;
        // if (nums.size() == 2)
        //     return nums[0] > nums[1] ? 0 : 1;

        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (greaterThanLeft(nums, mid))
                if (greaterThanRight(nums, mid))
                    return mid;
                else
                    left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

private:
    bool greaterThanLeft(vector<int> &nums, int idx)
    {
        if (idx == 0)
            return true;
        else
            return nums[idx] > nums[idx - 1];
    }

    bool greaterThanRight(vector<int> &nums, int idx)
    {
        if (idx == nums.size() - 1)
            return true;
        else
            return nums[idx] > nums[idx + 1];
    }
};
