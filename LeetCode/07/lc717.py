# lc717.py

# LeetCode 717. 1-bit and 2-bit Characters `E`
# 1sk | 91% | 16'
# A~0h05

class Solution:
    def isOneBitCharacter(self, bits: List[int]) -> bool:
        n = len(bits) - 2
        for i in range(n, -1, -1):
            if bits[i] == 0:
                return (n-i) % 2 == 0

        return (n+1) % 2 == 0
