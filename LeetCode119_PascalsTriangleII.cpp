// LeetCode119_PascalsTriangleII.cpp
// Ad
// Given a non-negative index k where k <= 33, return the kth index row of the Pascal's triangle.
// Note that the row index starts from 0.

#include <iostream>
#include <vector>

// solution ====================================================================

class Solution
{
  public:
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> ret = {1};
        if (!rowIndex)
            return ret;

        for (int row = {1}; row != rowIndex + 1; ++row)
        {
            ret.push_back(1);
            int temp1 = {1}, temp2 = {0};
            for (int i = {1}; i != row; ++i)
            {
                temp2 = ret[i];
                ret[i] = temp1 + temp2;
                temp1 = temp2;
            }
        }

        return ret;
    }
};

// test ========================================================================

int main(int argc, char *argv[])
{
    Solution sol;
    sol.getRow(4);

    // pause
    system("pause");
    return 0;
}