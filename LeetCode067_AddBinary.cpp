// LeetCode067_AddBinary.cpp
// Ad
// Given two binary strings, return their sum (also a binary string).
// The input strings are both non-empty and contains only characters 1 or 0.

#include <iostream>
#include <string>
#include <algorithm>

// solution --------------------------------------------------------------------

class Solution
{
  public:
    std::string addBinary(std::string a, std::string b)
    {
        std::string ret;
        bool flag{false};
        for (auto c : a)
            if (c == '1')
            {
                flag = 1;
                break;
            }
        for (auto c : b)
            if (c == '1')
            {
                flag = 1;
                break;
            }
        if (!flag)
            return std::string("0");

        size_t as{a.size()}, bs{b.size()};
        size_t siz{as};
        flag = false;
        if (as > bs)
        {
            siz = as;
            for (size_t i{0}; i != as - bs; ++i)
                b = '0' + b;
        }
        else if (as < bs)
        {
            siz = bs;
            for (size_t i{0}; i != bs - as; ++i)
                a = '0' + a;
        }

        for (size_t i{siz}; i != 0; --i)
        {
            char ai{a[i - 1]}, bi{b[i - 1]};
            if (ai != bi)
                ret.push_back(flag ? '0' : '1');
            else
            {
                ret.push_back(flag ? '1' : '0');
                flag = (ai == '1') ? true : false;
            }
        }
        if (flag)
            ret.push_back('1');
        reverse(ret.begin(), ret.end());
        return ret;
    }
};

// test ------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    Solution sol;
    std::string str1{"0"}, str2{"0"};
    std::cout << sol.addBinary(str1, str2) << std::endl;

    // pause
    system("pause");
    return 0;
}