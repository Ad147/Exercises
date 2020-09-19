# LeetCode 941. Valid Mountain Array `E`
# 1sk | 81 | 10'
# A~0b19

class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A) < 3 or A[0] > A[1] or A[-1] > A[-2]:
            return False
        decrease = False
        for i in range(len(A)-1):
            if A[i] == A[i+1]:
                return False
            elif not decrease and A[i] > A[i+1]:
                decrease = True
            elif decrease and A[i] < A[i+1]:
                return False
        return True
