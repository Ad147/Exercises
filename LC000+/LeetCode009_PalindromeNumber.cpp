// LeetCode009_PalindromeNumber.cpp
// Ad
// Determine whether an integer is a palindrome.
// An integer is a palindrome when it reads the same backward as forward.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// solution ====================================================================

// 140 ms / 54%
// --> 120 ms

class Solution
{
  public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;

        // forward and backward
        int f = x, b = {0};
        while (f != 0)
        {
            b = b * 10 + f % 10;
            f /= 10;
        }

        if (x == b)
            return true;
        else
            return false;
    }
};

// solution ====================================================================

// convert int to string
// 136 ms

class Solution1
{
  public:
    bool isPalindrome(int x)
    {
        std::string s = std::to_string(x);
        std::string r = s;
        std::reverse(r.begin(), r.end());
        if (s == r)
            return true;
        else
            return false;
    }
};

// test ========================================================================

int main(int argc, char *argv[])
{
    Solution sol;

    // pause
    system("pause");
    return 0;
} // LeetCode
