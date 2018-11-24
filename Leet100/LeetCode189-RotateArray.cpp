// LeetCode189-RotateArray.cpp
// Ad
// Given an array, rotate the array to the right by k steps, where k is non-negative.
// Note:
// Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
// Could you do it in-place with O(1) extra space?

#include <iostream>
#include <vector>
#include <algorithm>

// solution ====================================================================

class Solution
{
  public:
    void rotate(std::vector<int> &nums, int k)
    {
        int n = nums.size();
        k = k % n;
        int beg = {0};
        for (int cnt = {0}; cnt != n; ++beg)
        {
            auto i = beg;
            auto prev = nums[i];
            do
            {
                int next = {(i + k) % n};
                auto temp = nums[next];
                nums[next] = prev;
                i = next;
                prev = temp;
                ++cnt;
            } while (i != beg);
        }
    }
};

// solution ====================================================================

class Solution1
{
  public:
    void rotate(std::vector<int> &nums, int k)
    {
        k = k % nums.size();
        std::reverse(nums.begin(), nums.end() - k);
        std::reverse(nums.end() - k, nums.end());
        std::reverse(nums.begin(), nums.end());
    }
};

// solution ====================================================================

class Solution2
{
  public:
    void rotate(std::vector<int> &nums, int k)
    {
        if (nums.empty())
            return;

        k = k % nums.size();
        std::rotate(nums.begin(), nums.end() - k, nums.end());
    }
};

// test ========================================================================

int main(int argc, char *argv[])
{
    Solution sol;

    // pause
    system("pause");
    return 0;
}