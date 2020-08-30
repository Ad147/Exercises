# LeetCode 852. Peak Index in a Mountain Array `E`
# 1sk | 99% | 5'
# A~0h30

class Solution:
    def peakIndexInMountainArray(self, A: List[int]) -> int:
        beg, end = 0, len(A)-1
        while beg < end:
            i = (beg+end) // 2
            if A[i-1] > A[i]:
                end = i
            elif A[i] < A[i+1]:
                beg = i + 1
            else:
                return i

        return beg
