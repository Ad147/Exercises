// LeetCode001-TwoSum.cpp
// Ad
// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.

#include <iostream>
#include <vector>
#include <map>

// solution ====================================================================

// One-pass Hash Table
// **official solution**
// 4 ms

class Solution
{
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::vector<int> ret = {};
        if (nums.empty())
            return ret;

        std::map<int, int> map0 = {};
        for (int i = {0}; i < nums.size(); ++i)
        {
            int complement = target - nums[i];
            auto index = map0.find(complement);
            if (index != map0.cend())
            {
                ret.push_back(index->second);
                ret.push_back(i);
                return ret;
            }
            map0.insert(std::make_pair(nums[i], i));
        }
    }
};

// solution ====================================================================

// brute force
// 170+ ms

class Solution1
{
  public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::vector<int> ret = {};
        if (nums.empty())
            return ret;

        auto left = nums.cbegin();
        while (left != nums.cend())
        {
            auto right = left + 1;
            while (right != nums.cend())
            {
                if ((*left + *right) == target)
                {
                    ret.push_back(left - nums.cbegin());
                    ret.push_back(right - nums.cbegin());
                    return ret;
                }
                ++right;
            }
            ++left;
        }
    }
};

// test ========================================================================

int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<int> nums1 = {2, 7, 11, 15}, nums2 = {3, 2, 4};
    int tar1 = 9, tar2 = 6;
    auto res = sol.twoSum(nums2, tar2);
    std::cout << res[0] << ' ' << res[1] << std::endl;

    // pause
    system("pause");
    return 0;
}