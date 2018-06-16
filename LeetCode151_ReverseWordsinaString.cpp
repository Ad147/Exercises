// LeetCode151_ReverseWordsinaString.cpp
// Ad
// Given an input string, reverse the string word by word.
// Note:
//  - A word is defined as a sequence of non-space characters.
//  - Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
//  - You need to reduce multiple spaces between two words to a single space in the reversed string.

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

// solution ====================================================================

class Solution
{
  public:
    void reverseWords(std::string &s)
    {
        if (s.empty())
            return;

        // trim
        s.erase(0, s.find_first_not_of(' '));
        s.erase(s.find_last_not_of(' ') + 1);

        auto beg = s.begin(), end = s.rend().base();
        while (end != s.end())
        {
            beg = std::find_if_not(end, s.end(),
                                   [](char c) { return std::isspace(c); });
            if (beg != end + 1 && beg != s.begin())
                beg = s.erase(end + 1, beg);
            end = std::find_if(beg, s.end(),
                               [](char c) { return std::isspace(c); });
            std::reverse(beg, end);
        }

        std::reverse(s.begin(), s.end());
    }
};

// test ========================================================================

int main(int argc, char *argv[])
{
    Solution sol;
    std::string s = {"the sky is blue"};
    sol.reverseWords(s);
    std::cout << s << std::endl;

    std::vector<std::string> sv = {"abc", "come on", "this is it", " left right", " left right ", " left right ", "left  middle  right", "   the    quick   brown   fox    "};
    for (auto &s : sv)
    {
        sol.reverseWords(s);
        std::cout << s << std::endl;
    }

    // pause
    system("pause");
    return 0;
}