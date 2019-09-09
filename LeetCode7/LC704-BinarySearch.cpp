// LC704-BinarySearch.cpp
// Ad
// 19Sep09

// Difficulty: Easy
// Status: Accepted
// Time: 14'
// Runtime: 99%
// Memory: 100%

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

        int left = 0, right = nums.size();
        while (left < right)
        {
            int mid = (left + right) / 2;

            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid;
            else
                return mid;
        }

        return -1;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<vector<int>> nums{{-1, 0, 3, 5, 9, 12}, {-1, 0, 3, 5, 9, 12}};
    vector<int> targets{9, 2};

    for (size_t i = 0; i < nums.size(); ++i)
        cout << sol.search(nums[i], targets[i]) << endl;

    system("pause");
    return 0;
}
