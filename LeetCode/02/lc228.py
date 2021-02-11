# LeetCode 228. Summary Ranges `E`
# 1sk | 95% | 21'
# A~1c11

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        ans = []
        i, j = 0, 0
        for j in range(0, len(nums)):
            if j == len(nums)-1 or nums[j+1] - nums[j] > 1:
                if i == j:
                    ans.append(str(nums[j]))
                else:
                    ans.append(str(nums[i]) + "->" + str(nums[j]))
                i = j = j + 1
        return ans
