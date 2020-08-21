# LeetCode 840. Magic Squares In Grid `E`
# 1sk | 73% | 42'
# A~0h21

class Solution:
    def numMagicSquaresInside(self, grid: List[List[int]]) -> int:
        if len(grid) < 3 or len(grid[0]) < 3:
            return 0
        ans = 0
        for i in range(len(grid)-2):
            for j in range(len(grid[0])-2):
                if self.is_magic(grid, i, j):
                    ans += 1
        return ans

    def is_magic(self, grid, i, j):
        square = [grid[x][y] for x in range(i, i+3) for y in range(j, j+3)]

        if sorted(square) != list(range(1, 10)):
            return False

        lines = ((0, 1, 2), (3, 4, 5), (6, 7, 8), (0, 3, 6),
                 (1, 4, 7), (2, 5, 8), (0, 4, 8), (2, 4, 6))
        for i1, i2, i3 in lines:
            if square[i1] + square[i2] + square[i3] != 15:
                return False

        return True
