// LeetCode026_RemoveDuplicatesfromSortedArray.cpp
// Ad
// Remove duplicates from sorted array

// preprocessor ----------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

// solution ====================================================================

class Solution
{
  public:
    int removeDuplicates(std::vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        auto iter = std::unique(nums.begin(), nums.end());
        return iter - nums.begin();
    }
};

// solution --------------------------------------------------------------------

class Solution1
{
  public:
    int removeDuplicates(std::vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;
        for (std::vector<int>::iterator iter0{nums.begin()},
             iter1{nums.begin() + 1};
             iter1 != nums.end();)
        {
            if (*iter0 == *iter1)
            {
                iter1 = nums.erase(iter1);
            }
            else
            {
                ++iter0;
                ++iter1;
            }
        }
        return nums.size();
    }
};

// test ------------------------------------------------------------------------

int main()
{
    std::vector<int> vec{0, 0};
    Solution sol;
    sol.removeDuplicates(vec);
    for (int i : vec)
        std::cout << i << std::endl;
}