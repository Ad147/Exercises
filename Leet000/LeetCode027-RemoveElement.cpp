// LeetCode027-RemoveElement.cpp
// Ad
// Given an array nums and a value val, remove all instances of that value in-place and return the new length.
// Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
// The order of elements can be changed. It does not matter what you leave beyond the new length.

#include <iostream>
#include <vector>
#include <algorithm>

// solution ====================================================================

class Solution
{
  public:
    int removeElement(std::vector<int> &nums, int val)
    {
        auto iter = std::remove(nums.begin(), nums.end(), val);
        return iter - nums.begin();
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