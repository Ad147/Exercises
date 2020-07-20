# lc665.py

# LeetCode 665. Non-decreasing Array `E`
# acc | 98% | 34'
# A~0g20

class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        p = None
        for i in range(len(nums)-1):
            if nums[i] > nums[i+1]:
                if p is not None:
                    return False
                p = i
        return p is None or p == 0 or p == len(nums)-2 or nums[p] <= nums[p+2] or nums[p-1] <= nums[p+1]
