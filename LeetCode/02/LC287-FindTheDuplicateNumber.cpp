// LC287-FindTheDuplicateNumber.cpp
// Ad
// Init: 19Sep26

// Difficulty: Medium
// Status: OSK
// Time: 35'
// Runtime: 97%
// Memory: 80%

#include <iostream>
#include <vector>
using namespace std;

// Solution --------------------------------------------------------------------

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    int findDuplicate(const vector<int> &nums)
    {
        int left = 1, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int lessCnt = 0, greaterCnt = 0, equalCnt = 0;
            for (auto n : nums)
                if (n == mid)
                    ++equalCnt;
                else if (n < mid)
                    ++lessCnt;
                else
                    ++greaterCnt;

            if (equalCnt > 1)
                return mid;
            else if (lessCnt > mid - 1)
                right = mid - 1;
            else
                left = mid + 1;
        }

        return -1;
    }
};

// Main ------------------------------------------------------------------------

int main()
{
    Solution sol;
    vector<int> nums{3, 1, 3, 4, 2};

    cout << sol.findDuplicate(nums) << endl;

    system("pause");
    return 0;
}
