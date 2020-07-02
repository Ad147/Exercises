# lc575.py

# LeetCode 575. Distribute Candies `E`
# 1sk | 96% | 16'
# A~0g02


class Solution:
    def distributeCandies(self, candies: List[int]) -> int:
        return min(len(set(candies)), len(candies) // 2)
