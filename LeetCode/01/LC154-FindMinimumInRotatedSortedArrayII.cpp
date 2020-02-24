// LC154-FindMinimumInRotatedSortedArrayII.cpp
// Ad
// Init: 19Sep23

// Difficulty: Hard
// Status: Accepted
// Time: 37'
// Runtime: 98%
// Memory: 93%

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    int findMin(const vector<int> &nums)
    {
        if (nums.empty())
            return -1;
        if (nums.size() == 1 || nums.front() < nums.back())
            return nums.front();

        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (mid != 0 && nums[mid - 1] > nums[mid])
                return nums[mid];
            else if (nums.front() < nums[mid])
                left = mid + 1;
            else if (nums.front() > nums[mid])
                right = mid - 1;
            else
                return linearSearch(nums, left, right);
        }

        return nums[left];
    }

private:
    int linearSearch(const vector<int> &nums, int left, int right)
    {
        if (left == 0)
            ++left;

        for (int i = left; i <= right; ++i)
            if (nums[i - 1] > nums[i])
                return nums[i];

        return nums[left];
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<int> nums{2, 2, 2, 0, 1};

    cout << sol.findMin(nums) << endl;

    system("pause");
    return 0;
}
