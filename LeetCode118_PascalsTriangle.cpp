// LeetCode118_PascalsTriangle.cpp
// Ad
// Given a non-negative integer numRows, generate the first numRows of Pascal's triangle
// In Pascal's triangle, each number is the sum of the two numbers directly above it.

#include <iostream>
#include <vector>

// solution --------------------------------------------------------------------

class Solution
{
  public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> ret;
        if (!numRows)
            return ret;

        ret = {{1}};
        if (numRows == 1)
            return ret;

        ret.push_back({1, 1});
        for (size_t n{2}; n != numRows; ++n)
        {
            std::vector<int> ivec{1};
            for (size_t i{0}; i != n - 1; ++i)
            {
                ivec.push_back(ret[n - 1][i] + ret[n - 1][i + 1]);
            }
            ivec.push_back(1);
            ret.push_back(ivec);
        }
        return ret;
    }
};

// test ------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<std::vector<int>> tri{sol.generate(3)};
    for (auto v : tri)
    {
        for (auto i : v)
            std::cout << i << ' ';
        std::cout << std::endl;
    }

    // pause
    system("pause");
    return 0;
}