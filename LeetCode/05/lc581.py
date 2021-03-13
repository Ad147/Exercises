# LeetCode 581. Shortest Unsorted Continuous Subarray `M`
# acc | 98% | 70'
# A~0g03


class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        i, j = 0, len(nums) - 1
        while i < j and nums[i] <= nums[i+1]:
            i += 1
        while i < j and nums[j-1] <= nums[j]:
            j -= 1

        if i == j:
            return 0

        minval = min(nums[i:j+1])
        maxval = max(nums[i:j+1])
        while j < len(nums) and nums[j] < maxval:
            j += 1
        while i >= 0 and nums[i] > minval:
            i -= 1
        return j - i - 1
