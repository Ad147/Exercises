// LeetCode485-MaxConsecutiveOnes.cpp
// Ad
// Given a binary array, find the maximum number of consecutive 1s in this array.
// Note:
// The input array will only constain 0 and 1.
// The length of input array is a positive integer and will not exceed 10000.

#include <iostream>
#include <vector>
#include <algorithm>

// solution ====================================================================

class Solution
{
  public:
    int findMaxConsecutiveOnes(std::vector<int> &nums)
    {
        int ret = {0};

        auto beg = nums.cbegin();
        while (beg != nums.cend())
        {
            beg = std::find(beg, nums.cend(), 1);
            if (beg == nums.cend())
                return ret;

            auto end = std::find(beg, nums.cend(), 0);
            if (end - beg > ret)
                ret = end - beg;

            beg = end;
        }

        return ret;
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