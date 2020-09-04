# LeetCode 883. Projection Area of 3D Shapes `E`
# 1sk | 97% | 27'
# A~0v04

class Solution:
    def projectionArea(self, grid: List[List[int]]) -> int:
        top = len(grid)**2 - sum(row.count(0) for row in grid)
        front = sum(list(map(max, grid)))
        side = sum(list(map(max, zip(*grid))))
        return top + front + side
