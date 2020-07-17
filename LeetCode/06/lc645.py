# lc645.py

# LeetCode 645. Set Mismatch `E`
# acc | 91% | 34'
# A~0g17

class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        sm = sum(nums)
        dup = sm - sum(set(nums))
        miss = dup + (sum(range(1, len(nums)+1))) - sm
        return [dup, miss]
