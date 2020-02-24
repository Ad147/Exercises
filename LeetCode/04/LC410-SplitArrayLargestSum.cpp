// LC410-SplitArrayLargestSum.cpp
// Ad
// Init: 190929

// Difficulty: Hard
// Status: 2/27
// Time: 56'
// Runtime: -
// Memory: -

#include <iostream>
#include <vector>
using namespace std;

// Solution ====================================================================

int _ = []() { ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }();

class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int lowBound = 0, highBound = 0;
        for (auto n : nums)
        {
            if (n > lowBound)
                lowBound = n;
            highBound += n;
        }

        int left = lowBound, right = highBound;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int res = checkSum(nums, m, mid);
            if (res == 0)
                return mid;
            else if (res < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }

        return -1;
    }

private:
    int checkSum(const vector<int> &nums, int m, int sum)
    {
        vector<int> sums;
        int actualSum = 0, maxSum = 0;
        for (auto n : nums)
        {
            actualSum += n;
            if (actualSum > sum)
            {
                actualSum -= n;
                sums.push_back(actualSum);
                if (actualSum > maxSum)
                    maxSum = actualSum;
                actualSum = n;
            }
        }
        sums.push_back(actualSum);
        if (actualSum > maxSum)
            maxSum = actualSum;

        if (sums.size() == m)
        {
            if (maxSum == sum)
                return 0;
            else
                return 1;
        }
        else if (sums.size() < m)
            return 1;
        else
            return -1;
    }
};

// Main ========================================================================

int main()
{
    Solution sol;
    vector<int> nums{7, 2, 5, 10, 8};
    int m = 2;

    cout << sol.splitArray(nums, m) << endl;

    system("pause");
    return 0;
}
