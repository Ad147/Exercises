// LeetCode066_PlusOne.cpp
// Ad
// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
// You may assume the integer does not contain any leading zero, except the number 0 itself.

#include <iostream>
#include <vector>

// solution --------------------------------------------------------------------

class Solution
{
  public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {
        std::vector<int>::iterator it{digits.end() - 1};
        while (it != digits.begin() && *it == 9)
        {
            *it = 0;
            --it;
        }
        if (*it == 9)
        {
            *it = 0;
            it = digits.insert(it, 0);
        }
        ++*it;
        return digits;
    }
};

// test ------------------------------------------------------------------------

int main()
{
    std::vector<int> ivec{9, 9};
    Solution sol;
    std::vector<int> po{sol.plusOne(ivec)};
    for (int i : po)
        std::cout << i << ' ';
    std::cout << std::endl;
    system("pause");
    return 0;
}