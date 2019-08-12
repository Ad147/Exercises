// LeetCode283-MoveZeroes.cpp
// Ad
// Given an array nums, write a function to move all 0s to the end of it while maintaining the relative order of the non-zero elements.
// Note:
// 1. You must do this in-place without making a copy of the array.
// 2. Minimize the total number of operations.

#include <iostream>
#include <vector>
#include <algorithm>

// solution ====================================================================

class Solution
{
  public:
    void moveZeroes(std::vector<int> &nums)
    {
        if (nums.empty())
            return;

        auto left = std::find(nums.begin(), nums.end(), 0);
        if (left == nums.end())
            return;

        auto right = std::find_if(left, nums.end(), [](int i) { return i; });
        while (right != nums.end())
        {
            std::swap(*left, *right);
            ++left;
            right = std::find_if(right + 1, nums.end(),
                                 [](int i) { return i; });
        }
    }
};

// test ========================================================================

int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<int> iv = {1, 0, 99, 0, 0, 12, 0};
    sol.moveZeroes(iv);
    for (const auto &i : iv)
        std::cout << i << ' ';
    std::cout << std::endl;

    // pause
    system("pause");
    return 0;
}