// LeetCode
// Ad
// Given a 32-bit signed integer, reverse digits of an integer.
// Note: Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1].
// For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

#include <iostream>

// solution ====================================================================

// official solution
// 24 ms / 15%
// --> 12 ms (to string then reverse?)

class Solution
{
  public:
    int reverse(int x)
    {
        int rev = {0};
        while (x != 0)
        {
            int i = x % 10;
            x /= 10;
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && i > 7))
                return 0;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && i < -8))
                return 0;
            rev = rev * 10 + i;
        }
        return rev;
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
