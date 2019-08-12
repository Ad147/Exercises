// LeetCode209-MinimumSizeSubarraySum.cpp
// Ad
// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum >= s.
// If there isn't one, return 0 instead.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
// #include <ctime>

// solution ====================================================================

class Solution
{
  public:
    int minSubArrayLen(int s, std::vector<int> &nums)
    {
        int ret = nums.size() + 1;
        int sum = {0};
        for (auto left = nums.cbegin(), right = left;
             right != nums.cend(); ++right)
        {
            sum += *right;
            while (sum >= s)
            {
                ret = std::min(ret, int(right - left + 1));
                sum -= *left++;
            }
        }

        return (ret == nums.size() + 1) ? 0 : ret;
    }
};

// solution1 ===================================================================

class Solution1
{
  public:
    int minSubArrayLen(int s, std::vector<int> &nums)
    {
        int ret = {nums.size()};
        if (!s || std::accumulate(nums.cbegin(), nums.cend(), 0) < s)
            return 0;

        for (auto beg = nums.cbegin(); beg != nums.cend(); ++beg)
        {
            int sum = {0};
            for (auto end = beg; end != nums.cend(); ++end)
            {
                sum += *end;
                if (sum >= s)
                {
                    if (end - beg + 1 < ret)
                        ret = end - beg + 1;
                    break;
                }
            }
        }

        return ret;
    }
};

// test ========================================================================

int main(int argc, char *argv[])
{
    Solution sln;
    std::vector<int> iv = {2, 3, 1, 2, 4, 3};
    int s = {7};
    // auto t0 = clock();
    std::cout << sln.minSubArrayLen(s, iv) << std::endl;
    // auto t1 = clock();
    // std::cout << t1 - t0 << std::endl;

    // pause
    system("pause");
    return 0;
}