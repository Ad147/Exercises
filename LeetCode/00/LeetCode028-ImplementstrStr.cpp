// LeetCode028-ImplementstrStr.cpp
// Ad
// Implement strStr().
// Return the index of the first occurence of needle in haystack, or -1 if needle is not part of haystack.

#include <iostream>
#include <string>
#include <algorithm>

// solution --------------------------------------------------------------------

class Solution
{
  public:
    int strStr(std::string haystack, std::string needle)
    {
        if (needle.empty())
            return 0;
        if (haystack.empty() || haystack.size() < needle.size())
            return -1;

        for (size_t i = {0}; i != haystack.size() - needle.size() + 1; ++i)
        {
            // std::cerr << "i/substr: " << i << ' '
            //           << haystack.substr(i, needle.size()) << std::endl;
            if (haystack.substr(i, needle.size()) == needle)
                return i;
        }

        return -1;
    }
};

// test ------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    Solution sol;

    auto res = sol.strStr("hello", "ll");

    std::cout << res << std::endl;

    // pause
    system("pause");
    return 0;
}

// test examples: should return 2, -1, 0, 0, 4, -1
// "hello"
// "ll"
// ""
// "a"
// "abc"
// ""
// ""
// ""
// "asdfghhj"
// "ghh"
// "asdflkjg"
// "asf"
