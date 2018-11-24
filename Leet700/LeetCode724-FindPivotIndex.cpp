// LeetCode724-FindPivotIndex.cpp
// Ad
// Given an array of integers nums, write a method that returns the "pivot" index of this array.
// We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.
// If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

#include <iostream>
#include <vector>

// solution --------------------------------------------------------------------

class Solution
{
  public:
    int pivotIndex(std::vector<int> &nums)
    {
        int leftSum{0}, rightSum{0};
        for (int i : nums)
            rightSum += i;
        for (unsigned index{0}; index != nums.size(); ++index)
        {
            rightSum -= nums[index];
            if (leftSum == rightSum)
                return index;
            leftSum += nums[index];
        }
        return -1;
    }
};

// test ------------------------------------------------------------------------

int main()
{
    std::vector<int> vec1{1, 2, 3, 2, 1};
}