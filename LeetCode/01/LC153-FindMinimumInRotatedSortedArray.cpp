// LC153-FindMinimumInRotatedSortedArray.cpp
// Ad
// Init: 19Sep15

// Difficulty: Medium
// Status: Accepted
// Time: 18'
// Runtime: 100%
// Memory: 84%

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() {ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.empty())
            return -1;
        if (nums.front() <= nums.back())
            return nums.front();

        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (lessThanLeft(nums, mid))
                return nums[mid];
            else if (nums[mid] < nums.front())
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;
    }

private:
    bool lessThanLeft(vector<int> &nums, int mid)
    {
        if (mid == 0)
            return nums[mid] < nums.back();
        else
            return nums[mid] < nums[mid - 1];
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};

    cout << sol.findMin(nums) << endl;

    system("pause");
    return 0;
}