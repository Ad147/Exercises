/* lc463.c */

/* LeetCode 463. Island Perimeter `E` */
/* acc | 78%* | 43' */
/* A~0f13 */

int islandPerimeter(int **grid, int gridSize, int *gridColSize)
{
    const int row = gridSize, col = *gridColSize;
    int res = 0;
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            if (grid[i][j] == 0)
                continue;

            res += 4;
            if (i > 0 && grid[i - 1][j])
                --res;
            if (i < row - 1 && grid[i + 1][j])
                --res;
            if (j > 0 && grid[i][j - 1])
                --res;
            if (j < col - 1 && grid[i][j + 1])
                --res;
        }
    }

    return res;
}
