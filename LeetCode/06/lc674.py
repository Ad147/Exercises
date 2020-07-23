# lc674.py

# LeetCode 674. Longest Continuous Increasing Subsequence `E`
# 1sk | 99% | 7'
# A~0g23

class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        pre, curlen, maxlen = -1, 0, 0
        for n in nums:
            if n > pre:
                curlen += 1
            else:
                maxlen = max(curlen, maxlen)
                curlen = 1
            pre = n

        return max(curlen, maxlen)
