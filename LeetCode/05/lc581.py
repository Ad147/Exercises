# lc581.py

# LeetCode 581. Shortest Unsorted Continuous Subarray `E`
# 184/307 | - | 70'
# A~0g03


class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        if len(nums) == 1:
            return 0

        minval, maxval = 2 ** 31, -1
        flag = False
        for i in range(1, len(nums)):
            if nums[i - 1] > nums[i]:
                flag = True
            if flag:
                minval = min(minval, nums[i])

        for i in range(len(nums) - 2, -1, -1):
            if nums[i] > nums[i + 1]:
                flag = True
            if flag:
                maxval = max(maxval, nums[i])

        i = j = 0
        for i in range(len(nums)):
            if minval < nums[i]:
                break
        for j in range(len(nums) - 1, -1, -1):
            if maxval > nums[j]:
                break

        if j - i < 0:
            return 0
        else:
            return j - i + 1
