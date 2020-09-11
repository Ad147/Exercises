# LeetCode 908. Smallest Range I `E`
# 1sk | 97% | 3'
# A~0v11

class Solution:
    def smallestRangeI(self, A: List[int], K: int) -> int:
        return max(max(A) - min(A) - K*2, 0)
