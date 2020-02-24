// LeetCode498-DiagonalTraverse.cpp
// Ad
// Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
// (0,0)->(0,1)->(1,0)->(2,0)->(1,1)->(0,2)->(1,2)->(2,1)->(2,2)
//      0+     +-     +0     -+     -+     +0     +-     0+

#include <iostream>
#include <vector>

// solution --------------------------------------------------------------------

class Solution
{
  public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> ret;
        if (matrix.empty())
            return ret;
        else if (matrix.size() == 1)
            return matrix[0];
        else if (matrix[0].size() == 1)
        {
            for (auto v : matrix)
                ret.push_back(v[0]);
            return ret;
        }
        size_t m{matrix.size()}, n{matrix[0].size()};
        size_t i{0}, j{0};
        size_t cnt{0};
        bool flag{true};
        while (i != m && j != n)
        {
            ret.push_back(matrix[i][j]);
            // std::cerr << matrix[i][j] << ": " << i << ' ' << j << ' '
            //   << cnt << ' ' << flag << std::endl;
            if (flag && (i == 0 || i == m - 1 || j == 0 || j == n - 1))
            {
                if (i == m - 1)
                    ++j;
                else if (j == n - 1)
                    ++i;
                else if (i == 0)
                    ++j;
                else
                    ++i;
                ++cnt;
                flag = false;
            }
            else
            {
                if (cnt % 2)
                {
                    ++i;
                    --j;
                }
                else
                {
                    --i;
                    ++j;
                }
                flag = true;
            }
        }
        return ret;
    }
};

// test ------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<std::vector<int>> mat0{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
        mat1{{7}}, mat2{{1, 2, 3}}, mat3{{1}, {2}, {3}};
    std::vector<int> res0{sol.findDiagonalOrder(mat0)};
    std::vector<int> res1{sol.findDiagonalOrder(mat1)};
    std::vector<int> res2{sol.findDiagonalOrder(mat2)};
    std::vector<int> res3{sol.findDiagonalOrder(mat3)};
    // expect 1,2,4,7,5,3,6,8,9
    for (auto i : res3)
        std::cout << i << ' ';
    std::cout << std::endl;

    // pause
    system("pause");
    return 0;
}