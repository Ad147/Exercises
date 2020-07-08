# lc594.py

# LeetCode 594. Longest Harmonious Subsequence `E`
# acc | 45%* | 41'
# A~0g07


class Solution:
    def findLHS(self, nums: List[int]) -> int:
        count = Counter(nums)
        maxlen = 0
        for i in count:
            if i + 1 in count:
                maxlen = max(count[i] + count[i + 1], maxlen)

        return maxlen
