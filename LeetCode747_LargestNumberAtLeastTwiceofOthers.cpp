// LeetCode747_LargestNumberAtLeastTwiceofOthers.cpp
// Ad
// In a given integer array nums, there is always exactly one largest element.
// Find whether the largest element in the array is at least twice as every
// other number in the array. If it is, return the index of the largest element,
// otherwise return -1. nums will have a length in the range [1, 50]. Every
// nums[i] will be an integer in the range [0, 99].

#include <iostream>
#include <vector>

// solution --------------------------------------------------------------------

class Solution
{
  public:
    int dominantIndex(std::vector<int> &nums)
    {
        int index{0}, max1{0}, max2{0};
        for (unsigned i{0}; i < nums.size(); ++i)
        {
            if (nums[i] > max1)
            {
                max2 = max1;
                max1 = nums[i];
                index = i;
            }
            else if (nums[i] > max2)
            {
                max2 = nums[i];
            }
        }
        if (max1 >= max2 * 2)
            return index;
        return -1;
    }
};

// test ------------------------------------------------------------------------

int main()
{
    Solution sol;
    std::vector<std::vector<int>> vvec{
        {0}, {1}, {0, 1}, {1, 0}, {1, 2, 3}, {3, 2, 1}, {1, 2, 4}, {4, 2, 1}};
    // std::vector<std::vector<int>> vec{{}, vec1{0}, vec2{1}, vec3{0,1},
    // vec4{1,0};
    for (std::vector<int> v : vvec)
    {
        std::cout << sol.dominantIndex(v) << std::endl;
    }
    system("pause");
}

// excepted: 0, 0, 1, 0, -1, -1, 2, 0