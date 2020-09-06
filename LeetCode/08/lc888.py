# LeetCode 888. Fair Candy Swap `E`
# 1sk | 92% | 7'
# A~0v06

class Solution:
    def fairCandySwap(self, A: List[int], B: List[int]) -> List[int]:
        setB = set(B)
        dif = (sum(B)-sum(A)) // 2
        for a in A:
            if a + dif in setB:
                return [a, a+dif]
