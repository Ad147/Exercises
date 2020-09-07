# LeetCode 892. Surface Area of 3D Shapes `E`
# acc | 94% | 45'
# A~0v07

class Solution:
    def surfaceArea(self, grid: List[List[int]]) -> int:
        ans = 0
        for i in range(len(grid)):
            for j in range(len(grid)):
                if grid[i][j]:
                    ans += 2 + grid[i][j] * 4
                    if i > 0:
                        ans -= min(grid[i][j], grid[i-1][j]) * 2
                    if j > 0:
                        ans -= min(grid[i][j], grid[i][j-1]) * 2
        return ans
