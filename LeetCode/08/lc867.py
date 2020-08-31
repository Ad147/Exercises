# LeetCode 867. Transpose Matrix `E`
# 1sk | 97% | 15'
# A~0h31

class Solution:
    def transpose(self, A: List[List[int]]) -> List[List[int]]:
        return [[row[i] for row in A] for i in range(len(A[0]))]
