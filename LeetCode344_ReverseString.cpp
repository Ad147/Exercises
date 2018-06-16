// LeetCode344_ReverseString.cpp
// Ad
// Write a function that takes a string as input and returns the string reversed.

#include <iostream>
#include <string>
#include <algorithm>

// solution --------------------------------------------------------------------

class Solution
{
  public:
    std::string reverseString(std::string s)
    {
        std::reverse(s.begin(), s.end());
        return s;
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