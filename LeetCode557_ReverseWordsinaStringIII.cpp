// LeetCode557_ReverseWordsinaStringIII.cpp
// Ad
// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
// Note:
// In the string, each word is separated by single space and there will not be any extra space in the string.

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// solution ====================================================================

class Solution
{
  public:
    std::string reverseWords(std::string s)
    {
        if (s.empty())
            return s;

        auto beg = s.begin();
        auto end = beg;
        while (end != s.end())
        {
            end = std::find_if(
                beg, s.end(), [](char c) { return std::isspace(c); });
            std::reverse(beg, end);
            beg = end + 1;
        }

        return s;
    }
};

// test ========================================================================

int main(int argc, char *argv[])
{
    Solution sol;
    std::string s = {"Let's take LeetCode contest"};
    std::cout << sol.reverseWords(s) << std::endl;

    // pause
    system("pause");
    return 0;
}