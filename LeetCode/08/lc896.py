# LeetCode 896. Monotonic Array `E`
# 1sk | 97% | 9'
# A~0v09

class Solution:
    def isMonotonic(self, A: List[int]) -> bool:
        tone, prev = 0, A[0]
        for i in A[1:]:
            if i > prev:
                if tone == 0:
                    tone = 1
                elif tone < 0:
                    return False
            elif i < prev:
                if tone == 0:
                    tone = -1
                elif tone > 0:
                    return False
            prev = i
        return True
