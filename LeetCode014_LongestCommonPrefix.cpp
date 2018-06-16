// LeetCode014_LongestCommonPrefix.cpp
// Ad
// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
// All given inputs are in lowercase letters a-z.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// solution --------------------------------------------------------------------

class Solution
{
  public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::string ret;

        if (strs.empty())
            return ret;
        if (strs.size() == 1)
            return strs.back();
        for (const auto &s : strs)
            if (s.empty())
                return ret;

        // find the shortest string in strs
        ret = *std::min_element(strs.cbegin(), strs.cend(),
                                [](const std::string &s1, const std::string &s2) {
                                    return s1.size() < s2.size();
                                });
        auto size{ret.size()};

        bool flag{true};
        while (size)
        {
            for (auto const &s : strs)
                if (s.substr(0, size) != ret)
                {
                    flag = false;
                    break;
                }
            if (flag)
                return ret;
            ret = ret.substr(0, --size);
            flag = true;
        }

        return ret;
    }
};

// test ------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    Solution sln;
    std::vector<std::string> sv{"flower", "flow", "flight"};

    std::cout << sln.longestCommonPrefix(sv) << std::endl;

    // pause
    system("pause");
    return 0;
}

// test
// ["flower","flow","flight"]
// []
// [""]
// ["a"]
// ["abc"]
// ["", ""]
// ["", "a"]
// ["a", ""]
// ["a", "a"]
// ["abc", "abc"]
// ["ab", "abc"]