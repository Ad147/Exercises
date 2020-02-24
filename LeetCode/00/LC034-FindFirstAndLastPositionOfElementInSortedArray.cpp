// LC034-FindFirstAndLastPositionOfElementInSortedArray.cpp
// Ad
// Init: 19Sep16

// Difficulty: Medium
// Status: OSK
// Time: 26'
// Runtime: 99%
// Memory: 79%

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ret{-1, -1};
        if (nums.empty())
            return ret;

        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                int i = mid;
                while (i > 0 && nums[i - 1] == target)
                    --i;
                ret[0] = i;

                int j = mid;
                while (j + 1 < nums.size() && nums[j + 1] == target)
                    ++j;
                ret[1] = j;

                return ret;
            }
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return ret;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 8;

    vector<int> res = sol.searchRange(nums, target);
    cout << res[0] << ' ' << res[1] << endl;

    system("pause");
    return 0;
}