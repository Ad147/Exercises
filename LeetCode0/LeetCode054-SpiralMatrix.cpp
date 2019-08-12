// LeetCode054-SpiralMatrix.cpp
// Ad
// Given a matrix of m x n (m rows, n columns), return all elements of the matrix in spiral order.

#include <iostream>
#include <vector>

// solution --------------------------------------------------------------------

class Solution
{
  public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
    {
        std::vector<int> ret;
        if (matrix.empty() || matrix[0].empty())
            return ret;

        const size_t m{matrix.size()}, n{matrix[0].size()};
        size_t upEdge{1}, leftEdge{0}, downEdge{m - 1}, rightEdge{n - 1};
        size_t i{0}, j{0};
        unsigned dire{0};
        // ret.push_back(matrix[0][0]);
        while (ret.size() != m * n)
        {
            ret.push_back(matrix[i][j]);
            // std::cerr << "matrix[" << i << "][" << j << "]: "
            //           << matrix[i][j] << " direction: " << dire << std::endl;

            if (dire == 0 && j == rightEdge)
            {
                dire = 1;
                --rightEdge;
            }
            else if (dire == 1 && i == downEdge)
            {
                dire = 2;
                --downEdge;
            }
            else if (dire == 2 && j == leftEdge)
            {
                dire = 3;
                ++leftEdge;
            }
            else if (dire == 3 && i == upEdge)
            {
                dire = 0;
                ++upEdge;
            }

            switch (dire)
            {
            case 0:
                ++j;
                break;
            case 1:
                ++i;
                break;
            case 2:
                --j;
                break;
            case 3:
                --i;
                break;
            }
        }
        return ret;
    }
};

// test ------------------------------------------------------------------------

int main(int argc, char *argv[])
{
    Solution sol;
    std::vector<std::vector<int>> mat0{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    // expect 1,2,3,6,9,8,7,4,5
    for (auto i : sol.spiralOrder(mat0))
        std::cout << i << ' ';
    std::cout << std::endl;

    // pause
    system("pause");
    return 0;
}

// test list for Leet
// []
// [[7]]
// [[1,2]]
// [[1],[2]]
// [[1,2],[3,4]]
// [[1,2,3]]
// [[1],[2],[3]]
// [[1,2,3],[4,5,6]]
// [[1,2],[3,4],[5,6]]
// [[1,2,3],[4,5,6],[7,8,9]]
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// [[1,2,3],[4,5,6],[7,8,9],[10,11,12]]
// [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]]