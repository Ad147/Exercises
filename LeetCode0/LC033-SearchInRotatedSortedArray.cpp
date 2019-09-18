// LC033-SearchInRotatedSortedArray.cpp
// Ad
// Init: 19Sep12
// Update: 19Sep18

// Difficulty: Medium
// Status: Accepted
// Time: 20'
// Runtime: 100%
// Memory: 44%

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.empty())
            return -1;

        int pivot = findPivot(nums);
        int left = pivot, right = nums.size() - 1;
        if (target > nums.back())
            left = 0, right = pivot - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

private:
    int findPivot(vector<int> &nums)
    {
        if (nums.empty())
            return -1;
        if (nums.front() <= nums.back())
            return 0;

        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (lessThanLeft(nums, mid))
                return mid;
            else if (nums[mid] < nums.front())
                right = mid - 1;
            else
                left = mid + 1;
        }

        throw exception();
    }

    bool lessThanLeft(const vector<int> &nums, int mid)
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
    // vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    vector<int> nums{1, 3};
    vector<int> targets{0, 1, 2, 3, 4, 5, 6, 7};

    for (auto target : targets)
        cout << sol.search(nums, target) << endl;

    system("pause");
    return 0;
}
