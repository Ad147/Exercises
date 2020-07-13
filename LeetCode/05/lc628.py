# lc628.py

# LeetCode 628. Maximum Product of Three Numbers `E`
# acc | 36%* | 11'
# A~0g13

class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        min1, min2 = 1000, 1000
        max1, max2, max3 = -1000, -1000, -1000
        for n in nums:
            if n <= min1:
                min1, min2 = n, min1
            elif n <= min2:
                min2 = n

            if n >= max1:
                max1, max2, max3 = n, max1, max2
            elif n >= max2:
                max2, max3 = n, max2
            elif n >= max3:
                max3 = n

        return max1 * max(min1 * min2, max2 * max3)
