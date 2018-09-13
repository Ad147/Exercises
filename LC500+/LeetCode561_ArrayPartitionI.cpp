// LeetCode561_ArrayPartitionI
// Ad
// Given an array of 2n integers, your task is to group these integers into n pairs of integer, say (a1, b1), (a2, b2), ..., (an, bn) which makes sum of min(ai, bi) for all i from 1 to n as large as possible.
// Note:
// 1. n is a positive integer, which is in the range of [1, 10000].
// 2. All the integers in the array will be in the range of [-10000, 10000].

#include <iostream>
#include <vector>
#include <algorithm>

// solution --------------------------------------------------------------------

class Solution
{
  public:
    int arrayPairSum(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());

        int sum{0};
        for (auto iter{nums.cbegin()}; iter != nums.cend(); iter += 2)
            sum += *iter;

        return sum;
    }
};

// test ------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    Solution sol;

    // pause
    system("pause");
    return 0;
}