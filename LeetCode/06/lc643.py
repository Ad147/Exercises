# lc643.py

# LeetCode 643. Maximum Average Subarray I `E`
# 1sk | 98% | 9'
# A~0g17

class Solution:
    def findMaxAverage(self, nums: List[int], k: int) -> float:
        maxsum = cursum = sum(nums[0:k])
        for i in range(len(nums)-k):
            cursum += nums[i+k] - nums[i]
            maxsum = max(cursum, maxsum)

        return maxsum / k
