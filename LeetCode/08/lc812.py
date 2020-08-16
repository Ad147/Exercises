# LeetCode 812. Largest Triangle Area `E`
# acc | 82% | 27'
# A~0h16

class Solution:
    def largestTriangleArea(self, points: List[List[int]]) -> float:
        return max(.5 * abs(x1*y2 + x2*y3 + x3*y1 - y1*x2 - y2*x3 - y3*x1) for (x1, y1), (x2, y2), (x3, y3) in itertools.combinations(points, 3))
