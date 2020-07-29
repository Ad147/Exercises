# lc697.py

# LeetCode 697. Degree of an Array `E`
# acc | 100% | 41'
# A~0g29

class Solution:
    def findShortestSubArray(self, nums: List[int]) -> int:
        if len(nums) == len(set(nums)):
            return 1

        count = Counter(nums)
        deg = max(count.values())
        ans = len(nums)
        for k, v in count.items():
            if v == deg:
                ans = min(len(nums) - nums[::-1].index(k) - nums.index(k), ans)

        return ans
