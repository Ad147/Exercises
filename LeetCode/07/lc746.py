# LeetCode 746. Min Cost Climbing Stairs `E`
# acc | 89% | 60'
# A~0h08

class Solution(object):
    def minCostClimbingStairs(self, cost):
        f1 = f2 = 0
        for x in reversed(cost):
            f1, f2 = x + min(f1, f2), f1
        return min(f1, f2)
