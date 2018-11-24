# LeetCode747-LargestNumberAtLeastTwiceofOthers.py
# Ad
# In a given integer array nums, there is always exactly one largest element.
# Find whether the largest element in the array is at least twice as every other number in the array.
# If it is, return the index of the largest element, otherwise return -1.
# nums will have a length in the range [1, 50].
# Every nums[i] will be an integer in the range [0, 99].

# solution =====================================================================


class Solution:
    def dominantIndex(self, nums):
        index, max1, max2 = 0, 0, 0
        for i, n in enumerate(nums):
                if n > max1:
                max2 = max1
                max1 = n
                index = i
            elif n > max2:
                max2 = n
        if max1 >= max2 * 2:
            return index
        return -1
